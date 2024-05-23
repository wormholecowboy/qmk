#include QMK_KEYBOARD_H

enum combo_events {
    NUMPAD,
    CAPSWORD,
    TAB,
    ENTER,
    L_PAREN,
    R_PAREN,
    COMBO_LENGTH
};

// Main Layer combos
const uint16_t PROGMEM numpad[] = {KC_SCLN, KC_N, COMBO_END};
const uint16_t PROGMEM capsword[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM enter[] = {KC_H, KC_J, COMBO_END};

// Nav/Shortcut combos
const uint16_t PROGMEM l_paren[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM r_paren[] = {KC_L, KC_K, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    COMBO(numpad, KC_ENTER),
    COMBO(capsword, KC_TAB),
    COMBO(tab, KC_TAB),
    COMBO(enter, KC_ENTER),
    COMBO(l_paren, LSFT(KC_9)),
    COMBO(r_paren, LSFT(KC_0))
};

const uint16_t* layer_0_combos[] = { numpad, capsword, tab, enter, COMBO_END };
const uint16_t* layer_2_combos[] = { r_paren, COMBO_END };
// const uint16_t* layer_2_combos[] = { COMBO_END }


const uint16_t** get_combo_config(void) {
    switch (biton32(layer_state)) {
        case 0:
            return layer_0_combos;
        case 2:
            return layer_2_combos;
            break;
        default:
            return layer_0_combos;
    }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,        KC_Y,    KC_U,           KC_I,           KC_O,           KC_P,
    KC_A,           KC_S,           KC_D,           LT(5, KC_F),           KC_G,        KC_H,    SFT_T(KC_J),    GUI_T(KC_K),    ALT_T(KC_L),    CTL_T(KC_SCLN),
    GUI_T(KC_Z),    ALT_T(KC_X),    SFT_T(KC_C),    CTL_T(KC_V),    KC_B,        KC_N,    CTL_T(KC_M),    SFT_T(KC_COMM), ALT_T(KC_DOT),  GUI_T(KC_SLSH),
                          LT(1,KC_ESC), LT(2,OSM(MOD_LSFT)),      KC_SPC,  KC_BSPC
    ),
    [1] = LAYOUT_split_3x5_2(
    LCTL(KC_Q),    LCTL(KC_W),  KC_SPC,                     LCTL(KC_R),                      KC_PSCR,              LCTL(KC_1),    LCTL(KC_2),    LCTL(KC_3),    LCTL(KC_4),    LCTL(KC_5),
    LALT(KC_TAB),  LCTL(KC_L),  LCTL(LGUI(LSFT(KC_COMM))),  LCTL(LGUI(LSFT(KC_DOT))),        LCTL(LSFT(KC_M)),     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DELETE,
    LCTL(KC_Z),    LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  LCTL(KC_T),  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                               _______,   KC_MNXT,     QK_CAPS_WORD_TOGGLE, KC_CAPS_LOCK
    ),
    [2] = LAYOUT_split_3x5_2(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    LSFT(KC_GRV), KC_GRV,  LSFT(KC_LBRC), LSFT(KC_RBRC),  KC_MINS,    KC_PLUS, KC_LBRC, KC_RBRC,  KC_UNDS, KC_EQL,
    GUI_T(KC_EXLM), ALT_T(KC_AT),   SFT_T(KC_HASH), CTL_T(KC_DLR), KC_PERC,     KC_ASTR, CTL_T(KC_QUOTE), SFT_T(KC_QUOTE), ALT_T(KC_PIPE), GUI_T(KC_BSLS),
                               _______, _______,     KC_SPC,  KC_BSPC
    ),
    [3] = LAYOUT_split_3x5_2(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,      _______, KC_WH_U, KC_WH_D, _______, QK_BOOT,
    _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,      KC_MS_L, KC_VOLD, KC_VOLU, KC_MS_R, KC_INS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,      _______, KC_BTN1, KC_BTN2, _______, _______,
                               _______, _______,     _______, _______
    ),
    [4] = LAYOUT_split_3x5_2(
    _______, _______,   _______,   _______,   _______,      KC_MINS, KC_7, KC_8, KC_9, KC_ASTR,
    _______, _______,   _______,   MOD_LSFT,   _______,      KC_PLUS, KC_4, KC_5, KC_6, KC_ASTR,
    MOD_LGUI, MOD_LALT,   _______,   MOD_LCTL,   _______,      KC_DOT, KC_1, KC_2, KC_3, KC_4,
                               KC_EQL, _______,     KC_SPC, KC_BSPC
    ),
    [5] = LAYOUT_split_3x5_2(
    _______, _______,   _______,   _______,   _______,      _______, KC_F9, KC_F10, KC_F11, KC_F12,
    _______, _______,   MOD_LCTL,   _______,   _______,      _______, KC_F5, KC_F6, KC_F7, KC_F8,
    MOD_LGUI, MOD_LALT, MOD_LSFT,   _______,   _______,      _______, KC_F1, KC_F2, KC_F3, KC_F4,
                               _______, _______,     KC_SPC, KC_BSPC
    )
};

