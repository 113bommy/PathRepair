#include <bits/stdc++.h>
int min(int x, int y, int z) {
  if (x <= y && x <= z) {
    return x;
  } else if (y <= x && y <= z) {
    return y;
  } else {
    return z;
  }
}
int main() {
  int n, k, l, c, d, p, nl, np, a;
  scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
  a = k * l;
  a = min((a / nl), c * d, (p / np));
  printf("%d", a / n);
  return 0;
}
