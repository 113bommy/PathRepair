#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5;
long long mp[3][maxn], dp[3][maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long m;
    cin >> m;
    for (long long i = 0; i < 2; ++i)
      for (long long j = 1; j <= m; ++j) cin >> mp[i][j];
    for (long long i = 0; i < 2; ++i)
      for (long long j = 1; j <= m; ++j) dp[i][j] = dp[i][j - 1] + mp[i][j];
    long long ans = 0xfffffff;
    for (long long i = 1; i <= m; ++i) {
      ans = min(ans, max(dp[1][i - 1], (dp[0][m] - dp[0][i])));
    }
    cout << ans << endl;
  }
  return 0;
}
