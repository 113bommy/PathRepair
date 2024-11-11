#include <bits/stdc++.h>
int main() {
  int t, n, x, y, d;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &n, &x, &y, &d);
    if ((y - x) % d == 0) {
      printf("%d\n", abs(y - x) / d);
      continue;
    }
    int a1 = 1e9, a2 = 1e9;
    if ((n - y) % d == 0) {
      a1 = (n - y) / d + (n - x - 1) / d + 1;
    }
    if ((y - 1) % d == 0) {
      a2 = (y - 1) / d + (x - 1 - 1) / d + 1;
    }
    printf("%d\n", (((a1) < (a2)) ? (a1) : (a2)) < 1e9
                       ? (((a1) < (a2)) ? (a1) : (a2))
                       : -1);
  }
  return 0;
}
