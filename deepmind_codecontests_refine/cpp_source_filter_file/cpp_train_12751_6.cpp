#include <bits/stdc++.h>
using namespace std;
int n, m, b, mod, ans = 0;
int dp[505][505];
int main() {
  cin >> n >> m >> b >> mod;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= m; j++) {
      for (int k = x; k <= b; k++) (dp[j][k] += dp[j - 1][k - x]) %= mod;
    }
  }
  for (int i = 1; i <= b; i++) {
    (ans += dp[m][i]) %= mod;
  }
  cout << ans << endl;
  return 0;
}
