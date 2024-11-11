#include <bits/stdc++.h>
int min(int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  } else if (b <= a && b <= c) {
    return b;
  } else if (c <= b && c <= a) {
    return c;
  }
}
int main() {
  int n, k, l, c, d, p, nl, np;
  int x, y, z;
  scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
  x = (l * k) / nl;
  y = c * d;
  z = p / np;
  printf("%d\n", min(x, y, z) / n);
  return 0;
}
