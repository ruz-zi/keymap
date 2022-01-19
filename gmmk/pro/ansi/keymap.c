/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

//custom keycodes
#define MODS_ALT_MASK (MOD_BIT(KC_LALT)) // Make ALT layer for encoder use
#define MODS_CTRL_MASK (MOD_BIT(KC_LCTL)) // Make CTRL layer for encoder use
#define ALTSFT (LALT(KC_LSFT))
#define LWORD (LCTL(KC_LEFT))
#define RWORD (LCTL(KC_RGHT))
#define EMOJI (LGUI(KC_DOT))
#define LEFTI (LGUI(KC_LEFT))
#define RGHTI (LGUI(KC_RGHT))
#define MAXI (LGUI(KC_UP))
#define MINI (LGUI(KC_DOWN))
#define UNDO (LCTL(KC_Z))
#define REDO (LCTL(KC_Y))
#define COPY (LCTL(KC_C))
#define PASTE (LCTL(KC_V))
#define CUT (LCTL(KC_X))
#define ALL (LCTL(KC_A))
#define ULINE (LALT(KC_UP))
#define DLINE (LALT(KC_DOWN))

enum {
	SELECT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
        ALTSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT ,          KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_HOME, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                           KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MYCM, KC_WHOM, KC_MAIL, KC_MSEL, KC_CALC, KC_MEDIA_PLAY_PAUSE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG,           KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET  ,           _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_MOD,  _______,
        _______, _______, _______,                            _______,                            _______, _______, KC_TRNS, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, SELECT,  EMOJI,   _______, _______, REDO,    LWORD,   KC_UP,   RWORD,   _______, _______, _______, _______,          _______,
        _______, ALL,     KC_LSFT, KC_DEL,  _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,          _______,          _______,
        _______,          UNDO,    CUT,     COPY,    PASTE,   _______, DLINE,   ULINE,   _______, _______, _______,          _______, MAXI,    _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, LEFTI,   MINI,    RGHTI
    ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_mods() & MODS_ALT_MASK) {
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code16(S(KC_TAB));
        }
    } else if (get_mods() & MODS_CTRL_MASK) {
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code16(S(KC_TAB));
        }
    } else if(IS_LAYER_ON(1)) {
        if (clockwise) {
            tap_code(KC_MEDIA_NEXT_TRACK);
        } else {
            tap_code(KC_MEDIA_PREV_TRACK);
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode) {
	case SELECT:
		if (record->event.pressed) {
			SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
			SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
		}
		return false;
	}
	return true;
}