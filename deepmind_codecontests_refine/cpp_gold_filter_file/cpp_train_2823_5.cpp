#include <bits/stdc++.h>
int main() {
  char a[2][3];
  char ch;
  int i, sign = 0, flog_a = 0, flog_b;
  char b[] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
  while (scanf("%c", &ch) != EOF) {
    getchar();
    scanf("%s%s", a[0], a[1]);
    getchar();
    sign = 0;
    flog_a = 0;
    flog_b = 0;
    if (a[0][1] == ch) {
      if (a[1][1] != ch) {
        sign = 1;
      } else {
        for (i = 0; i < 9; i++) {
          if (b[i] == a[0][0]) {
            flog_a = i;
          }
          if (b[i] == a[1][0]) {
            flog_b = i;
          }
        }
        if (flog_a > flog_b) {
          sign = 1;
        }
      }
    } else {
      if (a[1][1] == a[0][1]) {
        for (i = 0; i < 9; i++) {
          if (b[i] == a[0][0]) {
            flog_a = i;
          }
          if (b[i] == a[1][0]) {
            flog_b = i;
          }
        }
        if (flog_a > flog_b) {
          sign = 1;
        }
      }
    }
    if (sign) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
