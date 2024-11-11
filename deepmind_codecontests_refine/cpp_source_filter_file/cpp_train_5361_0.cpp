#include <bits/stdc++.h>
using namespace std;
const int N = 12e5 + 4;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
int dp[4002][2002];
int main() {
  int n;
  scanf("%d", &n);
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][1] = dp[i - 1][i - 1];
    for (int j = 2; j <= n; j++) {
      dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[n][i];
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
