#include <bits/stdc++.h>
using namespace std;
const long long ts = 100005;
int dp[51][51][51];
int Left[50], Right[50], x[50], cost[50], Price[50];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, h, m;
  cin >> n >> h >> m;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= m; i++) {
    cin >> Left[i] >> Right[i] >> x[i] >> cost[i];
  }
  for (int l = n; l >= 1; l--) {
    for (int r = l; r <= n; r++) {
      for (int k = l; k <= r; k++) {
        memset(Price, 0, sizeof(Price));
        for (int f = 1; f <= m; f++) {
          int L = Left[f];
          int R = Right[f];
          if (L <= k && k <= R && l <= L && R <= r) {
            Price[x[f] + 1] += cost[f];
          }
        }
        for (int f = 1; f <= h; f++) Price[f] += Price[f - 1];
        for (int f = 0; f <= h; f++) {
          dp[l][r][f] =
              max(dp[l][k - 1][f] + dp[k + 1][r][f] - Price[f] + f * f,
                  dp[l][r][f]);
          if (f) {
            dp[l][r][f] = max(dp[l][r][f], dp[l][r][f - 1]);
          }
        }
      }
    }
  }
  cout << dp[1][n][h];
}
