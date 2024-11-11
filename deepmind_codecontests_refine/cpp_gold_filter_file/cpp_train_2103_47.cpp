#include <bits/stdc++.h>
int main() {
  int a, b, c, d, k, t, i, x, y;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    x = (a + (c - 1)) / c;
    y = (b + (d - 1)) / d;
    if (x + y <= k) {
      printf("%d %d\n", x, y);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
