#include <bits/stdc++.h>
using namespace std;
int const A = 5000 + 20, MOD = 1e9 + 7;
int n, a, b, k;
long long dp[A][2], part[A];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b >> k;
  for (int i = 1; i <= n; i++) {
    if (i != b) dp[i][0] = 1;
    part[i] = dp[i][0] + part[i - 1];
  }
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i <= n; i++) {
      if (i == b) continue;
      if (i > b)
        dp[i][j % 2] = (part[min(n, 2 * i - b - 1)] - part[b] -
                        dp[i][(j - 1) % 2] + 10LL * MOD) %
                       MOD;
      else
        dp[i][j % 2] = (part[b - 1] - part[max(0, 2 * i - b)] -
                        dp[i][(j - 1) % 2] + 10LL * MOD) %
                       MOD;
    }
    for (int i = 1; i <= n; i++) part[i] = (part[i - 1] + dp[i][j % 2]) % MOD;
  }
  return cout << dp[a][k % 2], 0;
}
