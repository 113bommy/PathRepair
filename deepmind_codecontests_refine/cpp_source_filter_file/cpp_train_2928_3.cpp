#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
long long n, k, x;
long long a[N];
long long dp[N][N];
long long cost[N][N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> x;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; i++) {
    long long maxi = -1e18;
    for (long long j = i; j <= n; j++) {
      maxi = max(maxi, a[j]);
      cost[i][j] = maxi;
    }
  }
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= n; j++) {
      dp[i][j] = -1e18;
    }
  }
  for (long long i = 0; i <= k - 1; i++) dp[i][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= i; j++) {
      for (long long pos = i - 1; pos >= max(0ll, i - k); pos--) {
        dp[i][j] = max(dp[i][j], dp[pos][j - 1] + cost[pos + 1][i]);
      };
    }
  }
  long long ans = dp[n][x];
  if (ans < 0) ans = -1;
  cout << ans << "\n";
  return 0;
}
