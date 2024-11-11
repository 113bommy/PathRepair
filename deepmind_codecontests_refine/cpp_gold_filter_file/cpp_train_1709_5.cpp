#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long f[2005][2005], ans, sum[2005];
int n, m;
char c[2005];
int main() {
  register int i, j, k;
  scanf("%d%d", &n, &m);
  scanf("%s", c + 1);
  f[0][0] = sum[0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      for (k = i - 1; k >= 0 && j - (i - k) * (n - i + 1ll) >= 0; k--) {
        f[i][j] =
            (f[i][j] + f[k][j - (n - i + 1ll) * (i - k)] * ('z' - c[i]) % mod);
      }
      f[i][j] = (f[i][j] + (c[i] - 'a') * sum[j] % mod) % mod;
      sum[j] = (sum[j] + f[i][j]) % mod;
    }
  }
  for (i = 0; i <= n; i++) ans = (ans + f[i][m]) % mod;
  printf("%lld", ans);
  return 0;
}
