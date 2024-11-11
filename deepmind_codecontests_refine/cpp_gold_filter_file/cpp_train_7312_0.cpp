#include <bits/stdc++.h>
using namespace std;
const int N = 110;
long long f[N][N];
long long a[N][N];
const long long INF = 1LL << 62;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
    for (int i = 0; i <= n + 1; ++i) f[i][0] = INF;
    for (int i = 0; i <= m + 1; ++i) f[0][i] = INF;
    long long ans = INF;
    for (int p = 1; p <= n; ++p)
      for (int q = 1; q <= m; ++q) {
        long long threshold = a[p][q] - (p + q - 1);
        if (a[1][1] < threshold + 1) continue;
        if (a[n][m] < threshold + n + m - 1) continue;
        for (int i = 0; i <= n + 1; ++i) f[i][q - 1] = INF;
        for (int i = 0; i <= m + 1; ++i) f[p - 1][i] = INF;
        f[0][1] = f[1][0] = f[0][0] = 0;
        for (int i = 1; i <= p; ++i)
          for (int j = 1; j <= q; ++j) {
            long long &res = f[i][j];
            res = INF;
            if (a[i][j] >= threshold + i + j - 1) {
              long long tmp = min(f[i - 1][j], f[i][j - 1]);
              if (tmp != INF) f[i][j] = tmp + a[i][j];
            }
          }
        if (f[p][q] == INF) continue;
        for (int i = p; i <= n; ++i)
          for (int j = q; j <= m; ++j) {
            long long &res = f[i][j];
            res = INF;
            if (a[i][j] >= threshold + i + j - 1) {
              long long tmp = min(f[i - 1][j], f[i][j - 1]);
              if (tmp != INF) f[i][j] = tmp + a[i][j];
            }
          }
        long long cost =
            (threshold + 1 + threshold + n + m - 1) * (n + m - 1) / 2;
        if (f[n][m] != INF) ans = min(ans, f[n][m] - cost);
      }
    printf("%llu\n", ans);
    memset(a, 0, sizeof(a[0]) * (n + 3));
  }
  return 0;
}
