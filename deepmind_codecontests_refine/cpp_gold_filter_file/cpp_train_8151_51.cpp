#include <bits/stdc++.h>
int main() {
  int n, k, l, c, d, p, nl, np, a, b, i, j, m, tau;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  a = k * l;
  b = a / nl;
  i = c * d;
  j = p / np;
  if (b <= i && b <= j) {
    m = b;
  }
  if (i <= b && i <= j) {
    m = i;
  }
  if (j <= i && j <= b) {
    m = j;
  }
  tau = m / n;
  printf("%d", tau);
  return 0;
}
