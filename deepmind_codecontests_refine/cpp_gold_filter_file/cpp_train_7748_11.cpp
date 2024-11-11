#include <bits/stdc++.h>
using namespace std;
long long n, t, ans = 0, dp[2005][2005], i, j, k;
const long long mod = 1e9 + 7;
int main() {
  cin >> n >> t;
  dp[0][1] = 1;
  for (i = 1; i <= t; i++)
    for (j = 1; j <= n; j++)
      for (k = j; k <= n; k += j) {
        (dp[i][k] += dp[i - 1][j]) %= mod;
      }
  for (i = 1; i <= n; i++) (ans += dp[t][i]) %= mod;
  cout << ans << endl;
}
