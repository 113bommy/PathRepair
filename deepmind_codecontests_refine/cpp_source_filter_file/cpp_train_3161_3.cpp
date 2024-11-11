#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 50;
long long n, m, x, y, sum[maxn], dp[maxn][2];
char c[maxn][maxn];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> x >> y;
  for (long long i = 1; i <= n; i++) {
    cin >> (c[i] + 1);
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      sum[i] += (c[j][i] == '#');
    }
  }
  for (long long i = 1; i <= m; i++) {
    sum[i] += sum[i - 1];
  }
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0][0] = dp[0][1] = 0LL;
  for (long long i = 1; i <= x; i++) {
    dp[i][0] = n * i - sum[i];
    dp[i][1] = sum[i];
  }
  for (long long i = x + 1; i <= m; i++) {
    for (long long j = i - x + 1; j >= max(i - y + 1, 1LL); j--) {
      dp[i][0] =
          min(dp[i][0], dp[j - 1][1] + n * (i - j + 1) - sum[i] + sum[j - 1]);
      dp[i][1] = min(dp[i][1], dp[j - 1][0] + sum[i] - sum[j - 1]);
    }
  }
  cout << min(dp[m][0], dp[m][1]);
}
