#include <bits/stdc++.h>
int main() {
  int n, k, l, c, d, p, nl, np, x, y, z, e, f, g;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  x = (k * l) / n;
  y = (d * c);
  z = p / np;
  e = x / n;
  f = y / n;
  g = z / n;
  int min = e;
  if (f < e && f < g) min = f;
  if (g < e && g < f) min = g;
  printf("%d", min);
}
