#include <bits/stdc++.h>
const int N = 1010, D = 10;
int n, x, y, a[N], b[N], c, d, f, xo, res;
int query(int d, int *a) {
  int x = 0;
  if (d) {
    printf("? %d ", d);
    for (int i = 1; i <= d; i++) printf("%d ", a[i] + 1);
    fflush(stdout);
    scanf("%d", &x);
  }
  return x;
}
int main() {
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < D; i++) {
    d = 0;
    for (int j = 0; j < n; j++)
      if (j >> i & 1) a[++d] = j;
    int r = query(d, a) ^ y;
    if (!r || r == x) xo ^= 1 << i, f = i;
  }
  for (int i = 0; i < n; i++)
    if (i >> f & 1) b[++c] = i;
  for (int i = 0; i < D; i++)
    if (i == f)
      res ^= 1 << i;
    else {
      d = 0;
      for (int k = 1; k <= c; k++)
        if (b[k] >> i & 1) a[++d] = b[k];
      int r = query(d, a) ^ y;
      if (!r || r == x) res ^= 1 << i;
    }
  int s0 = res, s1 = res ^ xo, te;
  if (s0 > s1) te = s0, s0 = s1, s1 = te;
  printf("! %d %d", s0 + 1, s1 + 1);
  fflush(stdout);
  return 0;
}
