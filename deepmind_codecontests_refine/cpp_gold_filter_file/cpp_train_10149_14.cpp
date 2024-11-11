#include <bits/stdc++.h>
using namespace std;
int n, m, b, a[510], mod, dp[510][510];
long long int ans = 0;
int main() {
  cin >> n >> m >> b >> mod;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = a[i]; k <= b; k++)
        dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
  for (int i = 0; i <= b; i++) ans = (ans + dp[m][i]) % mod;
  cout << ans % mod << endl;
  return 0;
}
