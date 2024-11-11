#include <bits/stdc++.h>
int smallest(int x, int y, int z) {
  int p = 0;
  if (x <= y && x <= z) {
    p = x;
  } else if (y <= x && y <= z) {
    p = y;
  } else if (z <= y && z <= x) {
    p = z;
  }
  return p;
}
int main() {
  int a, b, c, d, m, n, k = 0, s = 0, t;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  m = smallest(a, c, d);
  if (a > 0 && c > 0 && d > 0) {
    k = m * 256;
  }
  n = a - m;
  if (n > 0 && b > 0 && b > n) {
    s = n * 32;
  } else if (n > 0 && b > 0 && b < n) {
    s = b * 32;
  }
  t = k + s;
  printf("%d", t);
  return 0;
}
