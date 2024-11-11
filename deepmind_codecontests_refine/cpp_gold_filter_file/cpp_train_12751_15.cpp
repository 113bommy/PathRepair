#include <bits/stdc++.h>
using namespace std;
long long mod;
int n, m;
int V;
int bug[600];
long long dp[600][600];
int main() {
  cin >> n >> m >> V >> mod;
  for (int i = 1; i <= n; i++) cin >> bug[i];
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = bug[i]; k <= V; k++) {
        dp[j][k] = (dp[j][k] + dp[j - 1][k - bug[i]]) % mod;
      }
  long long ans = 0;
  for (int i = 0; i <= V; i++) ans = (ans + dp[m][i]) % mod;
  cout << ans << endl;
}
