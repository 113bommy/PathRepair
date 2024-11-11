#include <bits/stdc++.h>
const int32_t LETT = 26;
const size_t MAX_STR = 20000;
char str[MAX_STR];
int32_t strLen;
bool occur2[LETT * LETT];
bool occur3[LETT * LETT * LETT];
bool pos2[MAX_STR];
bool pos3[MAX_STR];
int main() {
  scanf("%s", str);
  strLen = strlen(str);
  int32_t code = str[strLen - 1] - 'a' + (str[strLen - 2] - 'a') * 26;
  int32_t possibCnt = 0;
  if (strLen >= 7) {
    occur2[code] = true;
    pos2[strLen - 2] = true;
    possibCnt++;
  }
  code = code + (str[strLen - 3] - 'a') * 26 * 26;
  if (strLen >= 8) {
    occur3[code] = true;
    pos3[strLen - 3] = true;
    possibCnt++;
  }
  for (int32_t i = strLen - 4; i > 4; i--) {
    if (pos3[i + 2]) {
      pos2[i] = true;
    } else if ((pos2[i + 2]) &&
               ((str[i] != str[i + 2]) || (str[i + 1] != str[i + 3]))) {
      pos2[i] = true;
    }
    code = (str[i] - 'a') * 26 + str[i + 1] - 'a';
    if (pos2[i]) {
      if (not occur2[code]) {
        occur2[code] = true;
        possibCnt++;
      }
    }
    if (pos2[i + 3]) {
      pos3[i] = true;
    } else if ((pos3[i + 3]) &&
               ((str[i] != str[i + 3]) || (str[i + 1] != str[i + 4]) ||
                (str[i + 2] != str[i + 5]))) {
      pos3[i] = true;
    }
    code = code * 26 + str[i + 2] - 'a';
    if (pos3[i]) {
      if (not occur3[code]) {
        occur3[code] = true;
        possibCnt++;
      }
    }
  }
  printf("%i\n", possibCnt);
  code = 0;
  for (int32_t f = 0; f < LETT; f++) {
    for (int32_t s = 0; s < LETT; s++) {
      code = f * 26 + s;
      if (occur2[code]) {
        printf("%c%c\n", f + 'a', s + 'a');
      }
      code *= 26;
      for (int32_t t = 0; t < LETT; t++) {
        if (occur3[code]) {
          printf("%c%c%c\n", f + 'a', s + 'a', t + 'a');
        }
        code++;
      }
    }
  }
}
