#include <bits/stdc++.h>
using namespace std;
const int maxn = 501;
int dp[2][maxn][maxn], a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, b, Mod, cnt = 0;
  cin >> n >> m >> b >> Mod;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int l = i % 2, l_ = 1 - l;
    for (int j = 0; j <= m; j++) {
      for (int t = 0; t <= b; t++) {
        if (i == 1) {
          if (a[1] * j <= t) {
            dp[l][j][t] = 1;
            continue;
          }
        }
        dp[l][j][t] = dp[l_][j][t];
        if (a[i] <= t && j >= 1) dp[l][j][t] += dp[l][j - 1][t - a[i]];
        dp[l][j][t] %= Mod;
      }
    }
  }
  cout << dp[n % 2][m][b];
}
