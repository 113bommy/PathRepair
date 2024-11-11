#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long inf = 1LL << 40;
const int N = 2000;
long long dp[N * 2][N + 2];
int agg[N];
long long costs[N];
long long acosts[N * 2];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  fill(&dp[0][0], &dp[0][0] + N * 2 * (N + 2), -inf);
  for (int i = 0; i < n; i++) {
    cin >> agg[i];
    agg[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> costs[i];
  }
  for (int i = 0; i < n + m; i++) {
    cin >> acosts[i];
  }
  for (int i = 0; i < n + m; i++) {
    dp[i][0] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int cnt = n; cnt > 0; cnt--) {
      if (dp[agg[i]][cnt - 1] > -inf) {
        dp[agg[i]][cnt] = max(dp[agg[i]][cnt],
                              dp[agg[i]][cnt - 1] - costs[i] + acosts[agg[i]]);
      }
    }
    int curr = n / 2;
    for (int ag = agg[i] + 1; ag < n + m; ag++) {
      for (int cnt = curr; cnt >= 0; cnt--) {
        dp[ag][cnt] =
            max(dp[ag][cnt], max(dp[ag - 1][cnt * 2], dp[ag - 1][cnt * 2 + 1]) +
                                 acosts[ag] * cnt);
      }
      curr /= 2;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n + m; i++) {
    ans = max(ans, dp[i][1]);
  }
  cout << ans << '\n';
}
