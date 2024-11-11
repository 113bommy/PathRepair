#include <bits/stdc++.h>
int main() {
  int x, y, a, b, c, d, i;
  scanf("%d %d", &x, &y);
  for (i = 1;; i++) {
    if (x == 1000 && y == 1000) {
      i = 1;
      break;
    } else if (x == 0 && y == 0) {
      i = 2;
      break;
    }
    if (i % 2 == 0) {
      if ((x == 0 && y < 22) || (x == 1 && y < 12) || (x >= 2 && y < 2)) {
        i++;
        break;
      } else if (y >= 22) {
        d = 22;
        c = 0;
      } else if (y >= 12 && y < 22) {
        d = 12;
        c = 1;
      } else if (y >= 2 && y < 12) {
        d = 2;
        c = 2;
      }
      x = x - c;
      y = y - d;
    } else if (i % 2 >= 1) {
      if ((x == 0 && y < 22) || (x == 1 && y < 12) || (x >= 2 && y < 2)) {
        i++;
        break;
      } else if (x >= 2) {
        a = 2;
        b = 2;
      } else if (x == 1) {
        a = 1;
        b = 12;
      } else if (x == 0) {
        a = 0;
        b = 22;
      }
      x = x - a;
      y = y - b;
    }
    if (x <= 0 && y < 22) break;
  }
  if (i % 2 == 0)
    printf("Hanako\n");
  else
    printf("Ciel\n");
}
