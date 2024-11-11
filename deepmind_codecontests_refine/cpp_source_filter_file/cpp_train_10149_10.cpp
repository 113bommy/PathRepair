#include <bits/stdc++.h>
using namespace std;
long long int n, m, b, mod, a[501], dp[501][501], ans = 0, i, j, k;
int main() {
  cin >> n >> m >> b >> mod;
  for (i = 0; i < n; i++) cin >> a[i];
  i = 0;
  for (j = 0; j <= m; j++)
    if (a[0] * j <= b) dp[j][a[i] * j] = 1;
  for (i = 1; i < n; i++) {
    for (j = 0; j <= m; j++) {
      for (k = 0; k <= b; k++) {
        if (j > 0 && k >= a[i]) dp[j][k] += dp[j - 1][k - a[i]];
        if (dp[i][j] >= mod) dp[j][k] -= mod;
      }
    }
  }
  for (i = 0; i <= b; i++) ans += dp[m][i];
  cout << ans % mod << endl;
  return 0;
}
