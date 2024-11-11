#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using db = long double;
const int N = 1e5 + 5, MOD = 1e9 + 7;
using ii = pair<int, int>;
int pwr[505];
int dp[2][505][505];
int n, k;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  pwr[0] = 1;
  for (int i = 1; i < 505; i++) {
    pwr[i] = (pwr[i - 1] + pwr[i - 1]) % MOD;
  }
  dp[1][0][0] = 1;
  for (int r = 1; r <= n; r++) {
    memset(dp[r & 1 ^ 1], 0, sizeof dp[r & 1 ^ 1]);
    for (int l = 0; l < r; l++) {
      for (int cnt = 0; cnt <= k; cnt++) {
        int val = dp[r & 1][l][cnt];
        int lS = pwr[l];
        int rS = (pwr[r - l] - 1);
        dp[r & 1 ^ 1][l][cnt] = (dp[r & 1 ^ 1][l][cnt] + 1ll * val * lS) % MOD;
        dp[r & 1 ^ 1][r][cnt + 1] =
            (dp[r & 1 ^ 1][r][cnt + 1] + 1ll * val * lS % MOD * rS) % MOD;
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= n; j++) {
    ans += dp[n & 1 ^ 1][j][k];
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << '\n';
  return 0;
}
