#include <bits/stdc++.h>
using namespace std;
char str[2001];
int main() {
  int n, i, len, x, y, z, xx, yy;
  scanf("%d%s", &n, str);
  len = strlen(str);
  z = 0;
  xx = yy = 0;
  for (i = 0; i < len; i++) {
    if (str[i] == 'R')
      xx++;
    else if (str[i] == 'L')
      yy++;
  }
  for (i = 0; i < len; i++) {
    if (str[i] == 'R') {
      x = i;
      z = 1;
      break;
    }
  }
  for (i = len - 1; i >= 0; i--) {
    if (str[i] == 'R') {
      y = i;
      z = 1;
      break;
    }
  }
  if (z) {
    if (yy != 0)
      printf("%d %d\n", x + 1, y + 1);
    else
      printf("%d %d\n", x, y + 2);
  } else {
    for (i = 0; i < len; i++) {
      if (str[i] == 'L') {
        x = i;
        break;
      }
    }
    for (i = len - 1; i >= 0; i--) {
      if (str[i] == 'L') {
        y = i;
        break;
      }
    }
    if (xx != 0)
      printf("%d %d\n", y + 1, x + 1);
    else
      printf("%d %d\n", y + 2, x);
  }
  return 0;
}
