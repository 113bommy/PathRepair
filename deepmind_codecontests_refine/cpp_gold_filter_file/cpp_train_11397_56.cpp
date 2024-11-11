#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans;
long long dp[1100][110];
int main() {
  cin >> n >> k >> m;
  for (int i = 1; i < 10; i++) dp[1][i % k]++;
  long long f = 1;
  for (int i = 1; i < n; i++) {
    f = f * 10 % k;
    for (int j = 0; j < k; j++) {
      int add = j == 0 ? 1 : dp[i][j];
      for (int p = 1; p < 10; p++) {
        dp[i + 1][(j + p * f) % k] += add;
        dp[i + 1][(j + p * f) % k] %= m;
      }
    }
    for (int j = 1; j < k; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= m;
    }
  }
  ans = dp[n][0] % m;
  f = 9;
  for (int i = n - 1; i > 0; i--) {
    ans += dp[i][0] * f % m;
    ans %= m;
    f = f * 10 % m;
  }
  cout << ans << endl;
  return 0;
}
