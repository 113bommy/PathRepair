#include <bits/stdc++.h>
int main() {
  int t, b, p, f, h, c, m;
  scanf("%d", &t);
  int i, r;
  for (i = 1; i <= t; i++) {
    scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
    int k;
    k = b / 2;
    r = 0;
    if (h > c) {
      if (k > p) {
        r = p;
        k -= p;
        if (k > f) {
          m = f;
        } else
          m = k;
        printf("%d\n", (r * h) + (c * m));
      } else {
        r = k;
        printf("%d\n", r * h);
      }
    } else {
      if (k > f) {
        r = f;
        k -= f;
        if (k > p) {
          m = p;
        } else
          m = k;
        printf("%d\n", (r * c) + (m * h));
      } else {
        printf("%d\n", k * c);
      }
    }
  }
}
