//
//  SentryException.h
//  Sentry
//
//  Created by Daniel Griesser on 05/05/2017.
//  Copyright © 2017 Sentry. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<Sentry/Sentry.h>)
#import <Sentry/SentryDefines.h>
#import <Sentry/SentrySerializable.h>
#else
#import "SentryDefines.h"
#import "SentrySerializable.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class SentryThread;

NS_SWIFT_NAME(Exception)
@interface SentryException : NSObject <SentrySerializable>
SENTRY_NO_INIT

/**
 * The name of the exception
 */
@property(nonatomic, copy) NSString *value;

/**
 * Type of the exception
 */
@property(nonatomic, copy) NSString *type;

/**
 * Additional information about the exception
 */
@property(nonatomic, strong) NSDictionary<NSString *, id> *_Nullable mechanism;

/**
 * Can be set to define the module
 */
@property(nonatomic, copy) NSString *_Nullable module;

/**
 * Determines if the exception was reported by a user BOOL
 */
@property(nonatomic, copy) NSNumber *_Nullable userReported;

/**
 * SentryThread of the SentryException
 */
@property(nonatomic, strong) SentryThread *_Nullable thread;

/**
 * Initialize an SentryException with value and type
 * @param value String
 * @param type String
 * @return SentryException
 */
- (instancetype)initWithValue:(NSString *)value type:(NSString *)type;

@end

NS_ASSUME_NONNULL_END
