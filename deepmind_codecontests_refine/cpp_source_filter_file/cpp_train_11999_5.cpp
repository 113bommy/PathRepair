#include <bits/stdc++.h>
int main(void) {
  char a[100000], b;
  fgets(a, 100000, stdin);
  int i, m = 0, n = 0, o = 0, x;
  for (i = 0; a[i] != '\0'; i++) switch (a[i]) {
      case '0':
        m++;
        break;
      case '1':
        n++;
        break;
      case '?':
        o++;
        break;
    }
  if (m + o > n) printf("00\n");
  b = a[i - 2];
  if (b == '1') {
    x = (m + o - n + (m + n + o) % 2) / 2;
    if (x >= 0 && x <= o) printf("01\n");
  } else if (b == '?') {
    x = (m + (o - 1) - (n + 1) + (m + n + o) % 2) / 2;
    if (x >= 0 && x <= (o - 1)) printf("01\n");
  }
  if (b == '0') {
    x = (m + o - n + (m + n + o) % 2) / 2;
    if (x >= 0 && x <= o) printf("10\n");
  } else if (b == '?') {
    x = (m + 1 + (o - 1) - n + (m + n + o) % 2) / 2;
    if (x >= 0 && x <= (o - 1)) printf("10\n");
  }
  if (n + o > m + 1) printf("11\n");
  return 0;
}
