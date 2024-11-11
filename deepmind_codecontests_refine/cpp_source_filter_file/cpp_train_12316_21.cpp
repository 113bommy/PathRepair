#include <bits/stdc++.h>
int main() {
  int n, k, l, m, d, i, s = 0;
  scanf("%d", &k);
  scanf("%d", &l);
  scanf("%d", &m);
  scanf("%d", &n);
  scanf("%d", &d);
  for (i = 0; i < d; i++) {
    if (k <= d && l <= d && m <= d && n <= d) {
      if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
        s++;
      }
    } else {
      break;
    }
  }
  printf("%d", s);
  return 0;
}
