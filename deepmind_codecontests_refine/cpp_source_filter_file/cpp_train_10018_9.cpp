#include <bits/stdc++.h>
using namespace std;
long long n, m, l[2010], s[2010], c[2010], f[4010][2010];
signed main() {
  scanf("%lld%lld", &n, &m);
  m = n + m;
  for (long long i = n; i; i--) scanf("%lld", &l[i]);
  for (long long i = n; i; i--) scanf("%lld", &s[i]);
  for (long long i = 1; i <= m; i++) scanf("%lld", &c[i]);
  memset(f, 0xaf, sizeof(f));
  for (long long i = 0; i <= m; i++) f[i][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = n; j; j--) {
      f[l[i]][j] = max(f[l[i]][j], f[l[i]][j - 1] - s[i] + c[l[i]]);
    }
    for (long long j = l[i]; j <= m; j++) {
      for (long long k = 0; k <= n >> (j - l[i]); k += 2) {
        f[j + 1][k / 2] = max(f[j + 1][k / 2],
                              max(f[j][k], f[j][k + 1]) + c[j + 1] * (k / 2));
      }
    }
  }
  printf("%lld\n", f[m][0]);
  return 0;
}
