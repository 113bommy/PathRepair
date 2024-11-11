#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5, M = 1000 + 5;
long long n, m, a[M][M], b[M];
long long f[M][M], g[M][M], ansf[N], ansg[N];
signed main(void) {
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) b[j] = a[i][j];
    sort(b + 1, b + 1 + m);
    long long tot = unique(b + 1, b + 1 + m) - (b + 1);
    for (long long j = 1; j <= m; ++j) {
      f[i][j] = lower_bound(b + 1, b + 1 + tot, a[i][j]) - b;
      ansf[i] = max(ansf[i], f[i][j]);
    }
  }
  for (long long i = 1; i <= m; ++i) {
    for (long long j = 1; j <= n; ++j) b[j] = a[j][i];
    sort(b + 1, b + 1 + n);
    long long tot = unique(b + 1, b + 1 + n) - (b + 1);
    for (long long j = 1; j <= n; ++j) {
      g[j][i] = lower_bound(b + 1, b + 1 + tot, a[j][i]) - b;
      ansg[i] = max(ansg[i], g[j][i]);
    }
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      long long ans = max(ansf[i], ansg[j]);
      if (f[i][j] > g[i][j]) ans = max(ans, ansg[j] + (f[i][j] - g[i][j]));
      if (g[i][j] > f[i][j]) ans = max(ans, ansf[i] + (g[i][j] - f[i][j]));
      printf("%lld ", ans);
    }
    puts("");
  }
  return 0;
}
