#include <bits/stdc++.h>
using namespace std;
const int N = 210;
const long long inf = 1e15;
int n, K, t;
long long a[N], b[N], c[N], A[N], B[N], C[N], f[N][N][2], g[N][N][2];
int main() {
  scanf("%d%d%d", &n, &t, &K);
  for (int i = (1); i <= (n); ++i) scanf("%lld%lld%lld", a + i, b + i, c + i);
  ++n;
  a[n] = c[n] = inf;
  for (int i = (1); i <= (n); ++i)
    A[i] = a[i] + A[i - 1], B[i] = b[i] + B[i - 1];
  for (int p = (1); p <= (n); ++p)
    for (int s = (0); s <= (t); ++s)
      for (int z = (0); z <= (1); ++z) f[p][s][z] = g[p][s][z] = inf;
  for (int p = (1); p <= (n); ++p)
    for (int s = (0); s <= (t); ++s)
      for (int z = (0); z <= (1); ++z) {
        if (f[p - 1][s][z] != inf && a[p] * z + b[p] * s <= c[p]) {
          f[p][s][z] = min(f[p - 1][s][z], f[p][s][z]);
          long long x = (z * A[p - 1] + s * B[p - 1] + K - 1) / K;
          if (x * K <= z * A[p] + s * B[p]) g[p][s][z] = min(g[p][s][z], x);
        }
        for (int r = (0); r <= (s - 1); ++r)
          if (g[p][r][z] != inf) {
            long long m = z * A[p] + r * B[p] - K * g[p][r][z],
                      x = (max(m + (s - r) * b[p] - c[p], 0ll) + K - 1) / K;
            if (x * K <= m && f[p - 1][s - r][0] != inf) {
              long long y = ((s - r) * B[p - 1] + K - 1) / K;
              f[p][s][z] = min(f[p][s][z], g[p][r][z] + x + f[p - 1][s - r][0]);
              if (y * K <= (s - r) * B[p] + m - x * K)
                g[p][s][z] = min(g[p][s][z], g[p][r][z] + x + y);
            }
          }
      }
  printf("%lld\n", f[n][t][1]);
  return 0;
}
