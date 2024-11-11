#include <bits/stdc++.h>
using namespace std;
long long n, m, dp[507][507], ans = 0;
pair<long long, long long> red[507], blue[507];
long long cal(long long a, long long b, long long c) {
  long long res =
      (red[b].second - red[a].second) * (blue[c].first - red[b].first) -
      (red[b].first - red[a].first) * (blue[c].second - red[b].second);
  if (res > 0)
    return 1;
  else if (res == 0)
    return 0;
  else
    return -1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> red[i].first >> red[i].second;
  }
  for (long long i = 1; i <= m; i++) {
    cin >> blue[i].first >> blue[i].second;
  }
  sort(red + 1, red + 1 + n);
  sort(blue + 1, blue + 1 + m);
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      for (long long k = 1; k <= m; k++) {
        if (blue[k].first >= red[i].first && blue[k].first <= red[j].first &&
            cal(i, j, k) == -1)
          dp[i][j]++;
      }
      dp[j][i] = -dp[i][j];
    }
  }
  for (long long i = 1; i <= n - 2; i++) {
    for (long long j = i + 1; j <= n - 1; j++) {
      for (long long k = j + 1; k <= n; k++) {
        if (dp[i][j] + dp[j][k] + dp[k][i] == 0) ans++;
      }
    }
  }
  cout << ans;
}
