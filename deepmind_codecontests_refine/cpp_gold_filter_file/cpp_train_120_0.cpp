#include <bits/stdc++.h>
int main() {
  int n, x, z, i;
  scanf("%d", &n);
  int a, b, c;
  for (i = 0; i < n; i++) {
    z = 0;
    scanf("%d %d %d", &a, &b, &c);
    x = c / 2;
    if (b > x) {
      z = (c / 2) * 3;
      if (2 * a <= (b - x)) {
        z = z + 3 * a;
      } else {
        z = z + 3 * ((b - x) / 2);
      }
    }
    if (b <= c / 2) {
      z = b * 3;
    }
    printf("%d\n", z);
  }
  return 0;
}
