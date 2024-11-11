#include <bits/stdc++.h>
using namespace std;
string s, p;
long long n, m;
const long long N = 201;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cin >> s >> p;
  if (p[0] == p[1]) {
    long long cnt = 0;
    for (char i : s)
      if (i == p[0]) cnt++;
    cnt = min(n, cnt + m);
    cout << (cnt * (cnt - 1)) / 2;
    return 0;
  }
  vector<vector<vector<long long>>> dp(
      n + 2, vector<vector<long long>>(m + 2, vector<long long>(n + 2, -1e18)));
  for (long long i = 0; i <= m; ++i) dp[0][i][0] = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long left = 0; left <= m; ++left) {
      for (long long cnt = 0; cnt <= n; ++cnt) {
        if (dp[i][left][cnt] < 0) continue;
        if (left > 0)
          dp[i + 1][left - 1][cnt + 1] =
              max(dp[i + 1][left - 1][cnt + 1], dp[i][left][cnt]);
        if (left > 0)
          dp[i + 1][left - 1][cnt] =
              max(dp[i + 1][left - 1][cnt], cnt + dp[i][left][cnt]);
        if (s[i] == p[0])
          dp[i + 1][left][cnt + 1] =
              max(dp[i + 1][left][cnt + 1], dp[i][left][cnt]);
        else if (s[i] == p[1])
          dp[i + 1][left][cnt] =
              max(dp[i + 1][left][cnt], cnt + dp[i][left][cnt]);
        dp[i + 1][left][cnt] = max(dp[i + 1][left][cnt], dp[i][left][cnt]);
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= m; ++i)
    for (long long j = 0; j <= n; ++j) ans = max(ans, dp[n][i][j]);
  cout << ans;
  return 0;
}
