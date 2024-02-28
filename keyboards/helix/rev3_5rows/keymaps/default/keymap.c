/* Copyright 2020 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  ADJUST,
  RGBRST,
  E_AIR,
  E_500,
  O_RAL,
  O_LAS,
  REINF,
  RESUPP,
  RAIL,
  SPACK
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  // [_QWERTY] = LAYOUT(
  //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  //     ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, EISU,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  //   ),
  [_QWERTY] = LAYOUT(
      KC_PMNS,  KC_PAST, KC_PSLS,  KC_NUM,   KC_BSPC,    KC_BSPC,                      KC_BSPC, KC_BSPC,    KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
      KC_PPLS,  KC_P9,   KC_P8,    KC_P7,    KC_MPLY,    KC_VOLU,                      KC_VOLU, KC_MPLY,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
      KC_PPLS,  KC_P6,   KC_P5,    KC_P4,    KC_MPRV,    KC_VOLD,                      KC_VOLD, KC_MPRV,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
      KC_PENT,  KC_P3,   KC_P2,    KC_P1,    KC_MNXT,    KC_MUTE,  ADJUST, ADJUST,     KC_MUTE, KC_MNXT,    KC_P1,      KC_P2,      KC_P3,      KC_PENT,
      KC_PENT,   KC_PDOT,  KC_P0,  KC_P0,  KC_CALC,       KC_APP,   RAISE,  RAISE,      KC_APP,  KC_CALC,    KC_P0,      KC_P0,      KC_PDOT,    KC_PENT
    ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |  (   |   )  |  F12 |      |      | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
      KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_LPRN, KC_RPRN, KC_F12,  _______, _______, KC_HOME, KC_END,  _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      | E_AIR|E_500 | O_RAL| O_LAS|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |      |      |REINF |RESUPP|      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |      | RAIL |SPACK |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |RAISE |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      O_LAS,   O_RAL,   E_500,   E_AIR,   _______, _______,                   _______, _______, E_AIR,   E_500,   O_RAL,   O_LAS,
      _______, _______, RESUPP,  REINF,   _______, _______,                   _______, _______, REINF,   RESUPP,  _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, SPACK,   RAIL,    _______, _______,  ADJUST, ADJUST,_______, _______, RAIL,    SPACK,   _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|EEPRST|      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | Mac  |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT(
      O_LAS,   O_RAL,   E_500,   E_AIR,   _______, _______,                   _______, _______, E_AIR,   E_500,   O_RAL,   O_LAS,
      _______, _______, RESUPP,  REINF,   _______, _______,                   _______, _______, REINF,   RESUPP,  _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, SPACK,   RAIL,    _______, _______,  ADJUST,  ADJUST, _______, _______, RAIL,    SPACK,   _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),    ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_HOME, KC_END)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EISU:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LNG2);
        }else{
          tap_code16(LALT(KC_GRAVE));
        }
      } else {
        unregister_code(KC_LNG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LNG1);
        }else{
          tap_code16(LALT(KC_GRAVE));
        }
      } else {
        unregister_code(KC_LNG1);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_RAISE);
      } else {
        layer_off(_LOWER);
        layer_off(_RAISE);
      }
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
    case E_AIR:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_RIGHT));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case E_500:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case O_RAL:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_RIGHT));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case O_LAS:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_DOWN));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case REINF:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_LEFT) SS_DELAY(100) SS_TAP(X_UP));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case RESUPP:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_RIGHT));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case RAIL:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_LEFT) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_LEFT) SS_DELAY(100) SS_TAP(X_RIGHT));
        } else {
            // when keycode QMKURL is released
        }
        break;
    case SPACK:
      if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_LEFT) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_DOWN));
        } else {
            // when keycode QMKURL is released
        }
        break;
  }
  return true;
}

// KC_RIGHT
// KC_LEFT
// KC_DOWN	
// KC_UP


//   E_AIR,
//   E_500,
//   O_RAL,
//   O_LAS,
//   REINF,
//   RESUPP,
//   RAIL,
//   SPACK