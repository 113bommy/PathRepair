#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, p, q, r;
  cin >> n >> p >> q >> r;
  long long a[n + 1], mx = -1e9;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long dp[n + 1][3];
  dp[0][0] = -1e9;
  dp[0][1] = -1e9;
  dp[0][2] = -1e9;
  for (long long i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], p * a[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i][0] + q * a[i]);
    dp[i][2] = max(dp[i - 1][2], dp[i][1] + r * a[i]);
  }
  cout << dp[n][2];
}
