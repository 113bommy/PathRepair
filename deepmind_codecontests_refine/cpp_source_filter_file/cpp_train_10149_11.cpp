#include <bits/stdc++.h>
using namespace std;
int n, m, b, mod;
int a[509] = {0};
int dp[2][509][509] = {0};
int main() {
  cin >> n >> m >> b >> mod;
  int c = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[0][0][0] = 1;
  int act = 0, pas = 1;
  for (int i = 1; i <= n; i++) {
    act = act + pas;
    pas = act - pas;
    act = act - pas;
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= b; k++) {
        dp[act][j][k] = dp[pas][j][k] % mod;
        if (k >= a[i]) {
          dp[act][j][k] += dp[act][j - 1][k - a[i]];
          dp[act][j][k] %= mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= b; i++) ans = (ans + dp[act][m][i]) % mod;
  cout << ans << endl;
  return 0;
}
