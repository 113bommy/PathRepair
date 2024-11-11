#include <bits/stdc++.h>
const int mo = 1000000007;
long long f[55][55][55][55];
int d[55];
void update(int p2, int p1, int c2, int c1, int d, long long v) {
  if (d == 2) {
    (f[p2][p1][c2][c1 + 1] += v) %= mo;
    if (c1) (f[p2][p1][c2][c1 - 1] += v * c1) %= mo;
    if (c2) (f[p2][p1][c2 - 1][c1 + 1] += v * c2) %= mo;
  } else {
    (f[p2][p1][c2 + 1][c1] += v) %= mo;
    (f[p2][p1][c2][c1] += v * c1) %= mo;
    if (c2)
      (f[p2][p1][c2 - 1][c1 + 2] += v * c2) %= mo,
          (f[p2][p1][c2 - 1][c1] += v * c1 * c2) %= mo;
    if (c1 > 1) (f[p2][p1][c2][c1 - 2] += v * c1 * (c1 - 1) / 2) %= mo;
    if (c2 > 1) (f[p2][p1][c2 - 2][c1 + 2] += v * c2 * (c2 - 1) / 2) %= mo;
  }
}
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  f[d[1] == 3][d[1] == 2][d[2] == 3][d[2] == 2] = 1;
  for (int i = 3; i <= n; i++) {
    for (int p2 = 0; p2 < i; p2++)
      for (int p1 = 0; p1 + p2 < i; p1++)
        for (int c2 = 0; c2 + p1 + p2 < i; c2++)
          for (int c1 = 0; c1 + c2 + p1 + p2 < i; c1++)
            if (f[p2][p1][c2][c1]) {
              long long v = f[p2][p1][c2][c1];
              if (!p2 && !p1) (f[c2][c1][0][0] += v) %= mo;
              f[p2][p1][c2][c1] = 0;
              if (p1) update(p2, p1 - 1, c2, c1, d[i], p1 * v);
              if (p2) update(p2 - 1, p1 + 1, c2, c1, d[i], p2 * v);
            }
  }
  printf("%I64d\n", f[0][0][0][0]);
}
