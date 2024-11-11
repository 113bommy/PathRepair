#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, f, g, h, i, t, n, x;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &x);
    b = 0;
    c = 1000000000;
    while (n--) {
      scanf("%d", &a);
      if (x % a == 0) {
        b = x / a;
      } else {
        if (a > x) {
          b = 2;
        } else {
          b = x / a + 1;
        }
      }
      if (b < c) {
        c = b;
      }
    }
    printf("%d", c);
  }
}
