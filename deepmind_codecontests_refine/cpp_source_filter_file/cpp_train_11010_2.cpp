#include <bits/stdc++.h>
int main() {
  int n, q, x, i, j, k, l, m, a, b, c, d, e, f, y;
  scanf("%d", &n);
  a = n / 100;
  i = n % 100;
  c = j / 20;
  k = j % 20;
  d = k / 10;
  l = k % 10;
  e = l / 5;
  m = l % 5;
  f = m / 1;
  y = a + c + d + e + f;
  printf("%d", y);
  return 0;
}
