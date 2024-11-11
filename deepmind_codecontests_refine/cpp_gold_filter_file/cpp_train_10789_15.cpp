#include <bits/stdc++.h>
using namespace std;
const double PI = 4 * atan(1);
const int MOD = 1000000007;
const long long LINF = 1ll << 60;
const int INF = 1 << 30;
long long n, W, B, X;
long long c[1005], cost[1005];
long long tot = 0;
long long dp[1005][10005];
int main() {
  cin >> n >> W >> B >> X;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    tot += c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  for (int i = 0; i <= n; i++) {
    for (long long j = 0; j <= tot; j++) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = W;
  for (int i = 0; i < n; i++) {
    for (long long j = 0; j <= tot && dp[i][j] != -1; j++) {
      for (int k = 0; k <= c[i] && dp[i][j] - cost[i] * k >= 0; k++) {
        dp[i + 1][j + k] = max(
            dp[i + 1][j + k], min(W + B * (j + k), dp[i][j] + X - cost[i] * k));
      }
    }
  }
  long long ans = 0;
  for (long long j = 0; j <= tot; j++) {
    if (dp[n][j] != -1) ans = max(ans, j);
  }
  cout << ans << endl;
}
