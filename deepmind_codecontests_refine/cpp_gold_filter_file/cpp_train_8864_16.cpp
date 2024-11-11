#include <bits/stdc++.h>
using namespace std;
long long n, m;
pair<long long, long long> seg[500000 + 1];
long long dp[20 + 1][500000 + 1];
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 1; i < n + 1; i++) {
    long long l, r;
    cin >> l >> r;
    seg[i] = {l, r};
    if (dp[0][l] < r) {
      dp[0][l] = r;
    }
  }
  for (long long i = 1; i < 500000 + 1; i++) {
    dp[0][i] = max(dp[0][i], dp[0][i - 1]);
    if (dp[0][i] < i) dp[0][i] = 0;
  }
  for (long long i = 1; i < 20 + 1; i++) {
    for (long long j = 0; j < 500000 + 1; j++) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
      if (dp[i][j] < j) dp[i][j] = 0;
    }
  }
  for (long long j = 1; j < m + 1; j++) {
    long long x, y;
    cin >> x >> y;
    long long ans = 0;
    for (long long i = 20; i >= 0; i--) {
      if (dp[i][x] < y and dp[i][x] != 0) {
        ans += (1 << i);
        x = dp[i][x];
      }
    }
    if (dp[0][x] >= y)
      cout << ans + 1 << '\n';
    else
      cout << -1 << '\n';
  }
}
