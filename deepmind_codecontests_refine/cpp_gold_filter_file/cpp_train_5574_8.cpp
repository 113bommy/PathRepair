#include <bits/stdc++.h>
int main() {
  int m, n, i, x, y;
  scanf("%d %d", &n, &m);
  int min = 0;
  int max = n + 1;
  if (m == 0)
    printf("%d\n", n - 1);
  else {
    for (i = 0; i < m; i++) {
      scanf("%d %d", &x, &y);
      if (x < y) {
        if (min < x) min = x;
        if (max > y) max = y;
      } else {
        if (y > min) min = y;
        if (max > x) max = x;
      }
    }
    if (min >= max) {
      printf("0\n");
    } else {
      printf("%d\n", max - min);
    }
  }
  return 0;
}
