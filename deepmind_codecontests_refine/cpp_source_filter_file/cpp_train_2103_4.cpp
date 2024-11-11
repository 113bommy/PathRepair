#include <bits/stdc++.h>
int main() {
  int t, a, b, c, d, k, x, y, i, j, p;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    for (j = 0; j < 100; j++) {
      if (c * j >= a) {
        x = j;
        break;
      }
    }
    for (j = 0; j < 100; j++) {
      if (d * j >= b) {
        y = j;
        break;
      }
    }
    if (x + y <= k)
      printf("%d %d", x, y);
    else
      printf("%d", -1);
  }
  return 0;
}
