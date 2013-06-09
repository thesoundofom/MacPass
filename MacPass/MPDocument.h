//
//  MPDocument.h
//  MacPass
//
//  Created by Michael Starke on 08.05.13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MPDatabaseVersion.h"


APPKIT_EXTERN NSString *const MPDocumentDidAddGroupNotification;
APPKIT_EXTERN NSString *const MPDocumentWillDelteGroupNotification;
APPKIT_EXTERN NSString *const MPDocumentDidAddEntryNotification;
APPKIT_EXTERN NSString *const MPDocumentWillDeleteEntryNotification;

APPKIT_EXTERN NSString *const MPDocumentEntryKey;
APPKIT_EXTERN NSString *const MPDocumentGroupKey;

@class KdbGroup;
@class KdbEntry;

@interface MPDocument : NSDocument

@property (assign, readonly) KdbGroup *root;
@property (retain, readonly) NSURL *file;
@property (nonatomic,retain) NSString *password;
@property (nonatomic, retain) NSURL *key;
@property (assign, readonly) MPDatabaseVersion version;
@property (assign, readonly) BOOL isDecrypted;

- (id)initWithVersion:(MPDatabaseVersion)version;
- (BOOL)decryptWithPassword:(NSString *)password keyFileURL:(NSURL *)keyFileURL;

/* Undoable Intiialization of elements */
- (KdbGroup *)createGroup:(KdbGroup *)parent;
- (KdbEntry *)createEntry:(KdbGroup *)parent;

/*
 Undoable movement of object
*/
- (void)moveGroup:(KdbGroup *)group toGroup:(KdbGroup *)target index:(NSInteger)index;
- (BOOL)group:(KdbGroup *)group isMoveableToGroup:(KdbGroup *)target;

@end