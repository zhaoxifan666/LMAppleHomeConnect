//
//  LMAppleHomeActivator.h
//  LMAppleHomeConnect
//
//  Created by MadHeart on 2021/3/3.
//

#import <Foundation/Foundation.h>
#import <HomeKit/HomeKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LMAppleHomeActivator : NSObject

/// 新加入的设备列表,一般取第一个
@property (nonatomic, strong, readonly)NSMutableArray <HMAccessory *> *freshJoinedAccessoryList;

+ (instancetype)sharedInstance;

/// 获取HomeKit权限
/// @param completion 结果回调 没有错误表示home已授权
- (void)requestHomeKitAuthroization:(void (^)(NSError *error))completion;


/// 当前用户是否具有家庭的管理权限。
/// @param home 家庭
- (BOOL)isAdminForHome:(HMHome *)home;

/// 创建一个新家
/// @param homeName 新家名称
/// @param completion （HMHome, NSError）
- (void)addHomeToAppleHome:(NSString *)homeName completion:(void (^)(HMHome *home, NSError *error))completion;


/// 获取home家庭列表
/// @param compleiton HMHome 家庭对象列表 Error 错误信息
- (void)getHomekitHomes:(void (^)(NSArray<HMHome *> * _Nullable homeList, NSError *error))compleiton;



/// 在某个家庭下添加新的设备，当设置完成后返回新增设备对象
/// @param home 家庭
/// @param completion （HMAccessory列表, 错误）
- (void)addAccessoryWithHome:(HMHome *)home settingDoneCompletion:(void (^)(NSArray <HMAccessory *> *accessoryList, NSError *error))completion;



/// 获取设备的lumi model值
/// @param accessory HomeKit设备
/// @param completion （设备model, error）
- (void)getAccessoryLumiModel:(HMAccessory *)accessory completion:(void (^)(NSString *model, NSError *error))completion;


/// 获取设备的did
/// @param accessory HomeKit设备
/// @param completion （设备did, error）
- (void)getAccessoryLumiDid:(HMAccessory *)accessory completion:(void (^)(NSString *did, NSError *error))completion;


/// 获取设备的绑定状态值
/// @param accessory HomeKit设备
/// @param completion （绑定状态值 1 == 已经绑定到私有云，0 == 未绑定到私有云, error）
- (void)getAccessoryBindState:(HMAccessory *)accessory completion:(void (^)(NSString *bindState, NSError *error))completion;




/// 判断这个设备是否支持绑定到私有云
/// @param accessory 目标设备
- (BOOL)isSupportToBindToCloudAccessory:(HMAccessory *)accessory;



/// 将apple home中的设备绑定到私有云
/// @param accessory 要绑定的HomeKit设备
/// @param countryDomain 设备要入网的域名
/// @param bindKey 向私有云请求的绑定key
/// @param completion 错误信息
- (void)bindAccessory:(HMAccessory *)accessory countryDomain:(NSString *)countryDomain bindKey:(NSString *)bindKey compeltion:(void (^)(NSError *error))completion;



/// 判断一个HomeKit设备是不是lumi的网关类设备
/// @param accessory 目标设备
- (BOOL)isLumiGatewayAccessory:(HMAccessory *)accessory;



/// 开启HomeKit模式下绿米网关添加子设备的功能
/// @param accessory 绿米网关
/// @param completion block（new added accessory, error）;
/// @param home 设备所在家庭
- (void)startAddNewAccessoryPermissionOnAccessory:(HMAccessory *)accessory onHome:(HMHome *)home completion:(void(^)(HMAccessory *accessory, NSError *error))completion;




/// 关闭HomeKit模式下绿米网关添加子设备的功能
/// @param accessory 绿米网关
/// @param completion block（error）;
/// @param home 设备所在家庭

- (void)stopAddNewAccessoryPermissionOnAccessory:(HMAccessory *)accessory onHome:(HMHome *)home  completion:(void(^)(NSError *error))completion;


/// 判断一个HomeKit设备是不是米家的固件
/// @param accessory 目标设备
- (BOOL)isMiioFirmwareAccessory:(HMAccessory *)accessory;

@end

NS_ASSUME_NONNULL_END
