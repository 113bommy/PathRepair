#include <bits/stdc++.h>
int main() {
  int i, j, k, flag = 0, n, a, b, c, d, e, f;
  long long count = 0;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  while (1) {
    if (c == 0 || e == 0) break;
    count = count + d * 2 + 1;
    d++;
    c--;
    e--;
  }
  if (c == 0) {
    while (1) {
      if (b == 0 || e == 0) break;
      count = count + d * 2;
      b--;
      e--;
    }
    while (1) {
      if (b == 0) break;
      d--;
      count = count + d * 2 + 1;
      b--;
    }
    printf("%lld\n", count);
    return 0;
  }
  if (e == 0) {
    while (1) {
      if (c == 0 || f == 0) break;
      count = count + d * 2;
      c--;
      f--;
    }
    while (1) {
      if (f == 0) break;
      d--;
      count = count + d * 2 + 1;
      f--;
    }
  }
  printf("%lld\n", count);
  return 0;
}
