#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  int i = 1;
  while (1) {
    if (y < 2 || ((100 * x) + (10 * y)) < 220) {
      if (i & 1 == 1)
        printf("Hanako");
      else
        printf("Ciel");
      return 0;
    }
    if (i & 1 == 1) {
      if (x >= 2) {
        x -= 2;
        y -= 2;
      } else {
        y -= ((220 - (100 * x))) / 10;
        x = 0;
      }
    } else {
      if (y >= 22)
        y -= 22;
      else if (y >= 12) {
        x--;
        y -= 12;
      } else {
        x -= 2;
        y -= 2;
      }
    }
    i++;
  }
  return 0;
}
