////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//            Copyright (C) 2013, RDA Microeletronics.                        //
//                            All Rights Reserved                             //
//                                                                            //
//      This source code is the property of RDA Microeletronics and is        //
//      confidential.  Any  modification, distribution,  reproduction or      //
//      exploitation  of  any content of this file is totally forbidden,      //
//      except  with the  written permission  of  RDA Microeletronics.        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  $HeadURL: http://svn.rdamicro.com/svn/developing1/Sources/chip/branches/8810/hal/8810/include/hal_config.h $ //
//    $Author: huazeng $                                                        // 
//    $Date: 2013-07-30 19:19:13 +0800 (Tue, 30 Jul 2013) $                     //   
//    $Revision: 20765 $                                                          //   
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file hal_config.h                                                        //
/// That file describes the configuration structure used to set all
/// configurable parameters in HAL.                                           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef _HAL_CONFIG_H_
#define _HAL_CONFIG_H_

// =============================================================================
//  MACROS
// =============================================================================


// =============================================================================
//  TYPES
// =============================================================================

// =============================================================================
// HAL_LCD_MODE_T
// -----------------------------------------------------------------------------
/// The LCD interface modes.
// =============================================================================
typedef enum
{
    HAL_LCD_MODE_SPI,
    HAL_LCD_MODE_PARALLEL_16BIT,
    HAL_LCD_MODE_DSI,
    HAL_LCD_MODE_RGB_16BIT,
#if defined(CONFIG_MACH_RDA8810E) || defined(CONFIG_MACH_RDA8810H) || defined(CONFIG_MACH_RDA8850E)
    HAL_LCD_MODE_RGB_18BIT,
#endif
    HAL_LCD_MODE_RGB_24BIT,

    HAL_LCD_MODE_QTY,
} HAL_LCD_MODE_T;

// =============================================================================
// HAL_CAM_MODE_T
// -----------------------------------------------------------------------------
/// The camera interface modes.
// =============================================================================
typedef enum
{
    HAL_CAM_MODE_PARALLEL,
    HAL_CAM_MODE_SPI,
    HAL_CAM_MODE_CSI,

    HAL_CAM_MODE_QTY,
} HAL_CAM_MODE_T;

// =============================================================================
// HAL_CAM_CSI_ID_T
// -----------------------------------------------------------------------------
/// The camera CSI IDs.
// =============================================================================
typedef enum
{
    HAL_CAM_CSI_NONE,
    HAL_CAM_CSI_1,
    HAL_CAM_CSI_2,

    HAL_CAM_CSI_ID_QTY,
} HAL_CAM_CSI_ID_T;

// =============================================================================
// HAL_CFG_SDMMC_T
// -----------------------------------------------------------------------------
/// This structure describes the SDMMC configuration for a given target.
// =============================================================================
typedef struct
{
    /// The sdmmc is used.
    BOOL sdmmcUsed :1;
    /// The sdmmc2 is used.
    BOOL sdmmc2Used :1;
    /// The sdmmc3 is used.
    BOOL sdmmc3Used :1;
} HAL_CFG_SDMMC_T;

// =============================================================================
// HAL_CFG_CAM_T
// -----------------------------------------------------------------------------
/// This structure describes the camera configuration for a given target.
/// The first field identify if camera is used.
/// The second and third field is the RemapFlag which identify if camera PDN/RST
/// need to be remapped to other GPIOs instead of default (GPIO_5 and GPIO_4),
/// for the first camera sensor.
/// The fourth and fifth field is the remapped pin when RemapFlag is set, for the
/// first camera sensor.
/// The sixth and seventh fields are used to describe which GPIOs are used for 
/// the PDN/RST lines of the optional second camera sensor. This second camera
/// sensor can only be used on with GPIOs to control its PDN and RST lines.
// =============================================================================
typedef struct
{
    /// \c TRUE if the rear camera is used
    BOOL            camUsed :1;
    /// The polarity of the Power DowN line, for the rear sensor.
    BOOL            camPdnActiveH :1;
    /// The polarity of the Reset line, for the rear sensor.
    BOOL            camRstActiveH :1;
    /// The remapped GPIO controlling PDN (-1 if not remapped), for the rear sensor.
    INT32           camPdnRemap;
    /// The remapped GPIO controlling RST (-1 if not remapped), for the rear sensor.
    INT32           camRstRemap;
    /// The CSI ID (valid only if camera mode is CSI)
    HAL_CAM_CSI_ID_T camCsiId;
    /// \c TRUE if the front camera is used
    BOOL            cam1Used :1;
    /// The polarity of the Power DowN line, for the front sensor.    
    BOOL            cam1PdnActiveH :1;
    /// The polarity of the Reset line, for the front sensor.
    BOOL            cam1RstActiveH :1;
    /// The remapped GPIO controlling PDN (-1 if not remapped), for the front sensor.
    INT32           cam1PdnRemap;
    /// The remapped GPIO controlling RST (-1 if not remapped), for the front sensor.
    INT32           cam1RstRemap;
    /// The CSI ID (valid only if camera mode is CSI)
    HAL_CAM_CSI_ID_T cam1CsiId;
    /// The camera interface mode
    HAL_CAM_MODE_T  camMode;
} HAL_CFG_CAM_T;

// =============================================================================
// HAL_CFG_PWM_T
// -----------------------------------------------------------------------------
/// This structure describes the PWM configuration for a given target. 
/// The fields tell wether the pin corresponding to PWM output 
/// is actually used as PWM output and not as something else (for 
/// instance as a GPIO). 
// =============================================================================
typedef struct
{
    /// \c TRUE if the PWL0 is used
    BOOL pwl0Used :1;
    /// \c TRUE if the PWL1 is used
    BOOL pwl1Used :1;
    /// \c TRUE if the PWT is used
    BOOL pwtUsed :1;
    /// \c TRUE if the LPG is used
    BOOL lpgUsed :1;
} HAL_CFG_PWM_T;

// =============================================================================
// HAL_CFG_I2C_T
// -----------------------------------------------------------------------------
/// This structure describes the I2C configuration for a given target. The
/// fields tell wether the corresponding I2C pins are actually used
/// for I2C and not as something else (for instance as a GPIO). 
// =============================================================================
typedef struct
{
    /// \c TRUE if the I2C pins are used
    BOOL i2cUsed :1;
    /// \c TRUE if the I2C2 pins are used
    BOOL i2c2Used :1;
    /// \c TRUE if the I2C2 pins are used from cam pins
    BOOL i2c2PinsCam :1;
    /// \c TRUE if the I2C3 pins are used
    BOOL i2c3Used :1;
#if defined(CONFIG_MACH_RDA8810E) || defined(CONFIG_MACH_RDA8810H) || defined(CONFIG_MACH_RDA8850E)
    /// \c TRUE if the I2CBB pins are used
    BOOL modemI2cUsed :1;
#endif
} HAL_CFG_I2C_T;

// =============================================================================
// HAL_CFG_I2S_T
// -----------------------------------------------------------------------------
/// This structure describes the I2S configuration for a given target. The
/// fields tell wether the corresponding I2S pin is actually used
/// for I2S and not as something else (for instance as a GPIO). 
// =============================================================================
typedef struct
{
    /// \c TRUE if the data out pin is used
    BOOL doUsed :1;
    BOOL :3;
    /// \c TRUE if corresponding input is used
    BOOL di0Used :1;
    BOOL di1Used :1;
    BOOL di2Used :1;
} HAL_CFG_I2S_T;

// =============================================================================
// HAL_UART_CONFIG_T
// -----------------------------------------------------------------------------
/// Used to describes a configuration for used pin by an UART for a given target.
// =============================================================================
typedef enum
{
    /// invalid
    HAL_UART_CONFIG_INVALID = 0,

    /// UART is not used
    HAL_UART_CONFIG_NONE,

    /// UART use only data lines (TXD & RXD)
    HAL_UART_CONFIG_DATA,

    /// UART use data and flow control lines (TXD, RXD, RTS & CTS)
    HAL_UART_CONFIG_FLOWCONTROL,

    /// UART use all lines (TXD, RXD, RTS, CTS, RI, DSR, DCD & DTR)
    HAL_UART_CONFIG_MODEM,

    HAL_UART_CONFIG_QTY
} HAL_UART_CONFIG_T;

// =============================================================================
// HAL_CFG_SPI_T
// -----------------------------------------------------------------------------
/// This structure describes the SPI configuration for a given target. The first
/// fields tell wether the pin corresponding to chip select is actually used
/// as a chip select and not as something else (for instance as a GPIO). 
/// Then, the polarity of the Chip Select is given. It is only relevant
/// if the corresponding Chip Select is used as a Chip Select.
/// Finally which pin is used as input, Can be none, one or the other.
/// On most chip configuration the input 0 (di0) is on the output pin: SPI_DIO
// =============================================================================
typedef struct
{
    /// \c TRUE if the corresponding pin is used as a Chip Select.
    BOOL cs0Used :1;
    BOOL cs1Used :1;
    BOOL cs2Used :1;
    BOOL cs3Used :1;
    /// \c TRUE if the first edge is falling
    BOOL cs0ActiveLow :1;
    BOOL cs1ActiveLow :1;
    BOOL cs2ActiveLow :1;
    BOOL cs3ActiveLow :1;
    /// \c TRUE if corresponding input is used
    BOOL di0Used :1;
    BOOL di1Used :1;
} HAL_CFG_SPI_T;

// =============================================================================
// HAL_CFG_GOUDA_T
// -----------------------------------------------------------------------------
/// This structure describes the GOUDA configuration for a given target. 
/// The first fields tell wether the pin corresponding to chip select is 
/// actually used as a chip select and not as something else (for instance
/// as a GPIO). If none are used, the GOUDA is considered unused.
// =============================================================================
typedef struct
{
    /// \c TRUE if the corresponding pin is used as a Chip Select.
    BOOL cs0Used :1;
    BOOL cs1Used :1;
    /// \c TRUE if LCD 16-23 bits are from camera, FALSE from NAND
    BOOL lcd16_23Cam :1;
#if defined(CONFIG_MACH_RDA8810E) || defined(CONFIG_MACH_RDA8810H) || defined(CONFIG_MACH_RDA8850E)
    /// \c TRUE if LCD 8-23 (except for 16-17) bits are from camera2, FALSE from other
    BOOL lcd8_23Cam2 :1;
    /// \c TRUE if LCD 16-17 bits are from LCD CS, FALSE from other
    BOOL lcd16_17Cs :1;
#endif
    /// \c LCD interface mode
    HAL_LCD_MODE_T lcdMode;
} HAL_CFG_GOUDA_T;

// =============================================================================
// HAL_CFG_IO_DRIVE_T
// -----------------------------------------------------------------------------
/// This structure describes the IO Drive configuration for a given target. 
// =============================================================================
typedef union
{
    struct
    {
        UINT32 vDdrDomain:3;    // 2:0
        UINT32 vPsram1Domain:3; // 5:3
        UINT32 vPsram2Domain:3; // 6:8
        UINT32 vNFlashDomain:3; // 11:9
        UINT32 vLcd1Domain:3;   // 14:12
        UINT32 vLcd2Domain:3;   // 17:15
        UINT32 vSDat1Domain:3;  // 20:18
        UINT32 vSDat2Domain:3;  // 23 :21
        UINT32 vCamDomain:2;    // 25:24
        UINT32 vSim1Domain:2;   // 27:26
        UINT32 vSim2Domain:2;   // 29:28
        UINT32 vSim3Domain:2;   // 31:30
        UINT32 vGpioDomain:2;   // 1:0
        UINT32 :30;
    };
    struct
    {
        UINT32 select1;
        UINT32 select2;
    };
} HAL_CFG_IO_DRIVE_T;

// =============================================================================
// HAL_CFG_CONFIG_T
// -----------------------------------------------------------------------------
/// HAL configuration structure. 
/// This structure is used to setup HAL with regards to the specific 
/// configuration of the board.
/// Enabling a feature such as i2sCfg will set the corresponding pins which 
/// could also be a GPIO to their alternative use, that is I2S for this 
/// example.
/// GPIO Pins not connected must be set in the noConnectPins bitfield, for
/// power saving. They are configured as output and driven to '0'.
/// Pins which are not not connected (ie are connected) but are not used in
/// an alternative mode as I2S, are considered to be used as GPIOs.
// =============================================================================
typedef struct{
    /// Chip version
    UINT32  chipVersion;
    /// RF Clock Frequency
    UINT32  rfClkFreq;
    /// \c TRUE if LPS_CO_1 is used as LPS
    BOOL    useLpsCo1;
    /// Bitfield with '1' for keypad pins used as input on the keypad
    UINT8   keyInMask;
    /// Bitfield with '1' for keypad pins used as output on the keypad
    UINT8   keyOutMask;
    /// PWM Configuration
    HAL_CFG_PWM_T pwmCfg;
    HAL_CFG_I2C_T i2cCfg;
    /// I2S Configuration
    HAL_CFG_I2S_T i2sCfg;
#if defined(CONFIG_MACH_RDA8810E) || defined(CONFIG_MACH_RDA8810H) || defined(CONFIG_MACH_RDA8850E)
    HAL_CFG_I2S_T i2s2Cfg;
#endif
    /// UART Configuration
    HAL_UART_CONFIG_T uartCfg[3];
    /// SPI Configuration
    HAL_CFG_SPI_T modemSpiCfg[1];
    HAL_CFG_SPI_T spiCfg[2];
    /// SDMMC Configuration
    HAL_CFG_SDMMC_T sdmmcCfg;
    /// Camera Configuration
    HAL_CFG_CAM_T   camCfg;
#if defined(CONFIG_MACH_RDA8810E) || defined(CONFIG_MACH_RDA8810H) || defined(CONFIG_MACH_RDA8850E)
    /// Camera2 Configuration
    HAL_CFG_CAM_T   cam2Cfg;
#endif
    /// Gouda/LCD Configuration
    HAL_CFG_GOUDA_T goudaCfg;
    /// \c TRUE if parallel NAND interface is used
    BOOL    parallelNandUsed;
    /// \c TRUE if host UART is used
    BOOL    hostUartUsed;
    /// \c TRUE if host clock is used
    BOOL    hostClkUsed;
    /// \c TRUE if CLK_OUT pin is used
    BOOL    clkOutUsed;
    /// \c TRUE if CLK_32K pin is used
    BOOL    useClk32k;
#if defined(CONFIG_MACH_RDA8810E) || defined(CONFIG_MACH_RDA8810H) || defined(CONFIG_MACH_RDA8850E)
    /// \c TRUE if SDIO2_UART1 pin is used for UART1, FALSE for SDIO2
    BOOL    sdio2Uart1Used;
    /// \c TRUE if EMAC pin is used
    BOOL    emacUsed;
#endif

    /// Bitfield with '1' for physically not connected GPIO_C pins
    UINT32  noConnectGpio_C;
    /// Bitfield with '1' for GPIO really used as GPIO_C
    UINT32  usedGpio_C;
    /// Bitfield with '1' for TCO really used as TCO
    UINT32  usedTco;
    /// Bitfield with '1' for physically not connected GPIO_A pins
    UINT32  noConnectGpio_A;
    /// Bitfield with '1' for GPIO really used as GPIO_A
    UINT32  usedGpio_A;
    /// Bitfield with '1' for GPO really used as GPO_A
    UINT32  usedGpo_A;
    /// Bitfield with '1' for physically not connected GPIO_B pins
    UINT32  noConnectGpio_B;
    /// Bitfield with '1' for GPIO really used as GPIO_B
    UINT32  usedGpio_B;
    /// Bitfield with '1' for physically not connected GPIO_D pins
    UINT32  noConnectGpio_D;
    /// Bitfield with '1' for GPIO really used as GPIO_D
    UINT32  usedGpio_D;
#if defined(CONFIG_MACH_RDA8810E) || defined(CONFIG_MACH_RDA8810H) || defined(CONFIG_MACH_RDA8850E)
    /// Bitfield with '1' for physically not connected GPIO_E pins
    UINT32  noConnectGpio_E;
    /// Bitfield with '1' for GPIO really used as GPIO_E
    UINT32  usedGpio_E;
#endif
    /// IO Drive Value
    HAL_CFG_IO_DRIVE_T ioDrive;

} HAL_CFG_CONFIG_T;


// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================

//  

// =============================================================================
//  FUNCTIONS
// =============================================================================

#endif // _HAL_CONFIG_H_

