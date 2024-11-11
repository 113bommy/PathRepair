#include <bits/stdc++.h>
int main() {
  char str[101];
  int zeros = 0, ones = 0, dangerous = 0, i, len;
  gets(str);
  len = strlen(str);
  for (i = 0; i < len; i++) {
    if (str[i] == '0') {
      ones = 0;
      zeros++;
    } else {
      zeros = 0;
      ones++;
    }
    if (ones == 7 || zeros == 7) {
      dangerous = 1;
      break;
    }
  }
  printf("%s", dangerous ? "yes\n" : "no\n");
  return 0;
}
