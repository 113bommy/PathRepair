#include <bits/stdc++.h>
using namespace std;
int t, n, i, m, y[100005], x[100005], j, k, g0, s0, a, b, z, p;
void aj() {
  int n0, y1, m0;
  n0 = m;
  m0 = n;
  for (i = 0; i < p; ++i) {
    y1 = y[i];
    y[i] = n - x[i] + 1;
    x[i] = y1;
  }
  n = n0;
  m = m0;
}
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &z, &p);
  for (i = 0; i < p; ++i) scanf("%d%d", x + i, y + i);
  b %= 4;
  a %= 4;
  z %= 2;
  while (a--) aj();
  if (z > 0) {
    for (i = 0; i < p; ++i) {
      y[i] = m - y[i] + 1;
    }
  }
  b = 4 - b;
  while (b--) {
    aj();
  }
  for (i = 0; i < p; ++i) {
    printf("%d %d\n", x[i], y[i]);
  }
  return 0;
}
