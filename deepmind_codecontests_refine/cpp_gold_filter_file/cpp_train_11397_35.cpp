#include <bits/stdc++.h>
using namespace std;
long long dp[1002][102] = {{0}};
long long power1[1002];
int main() {
  int i, j, k, l, m, n, t;
  cin >> n, cin >> k, cin >> m;
  long long y = 1;
  power1[0] = 1;
  for (int i = 1; i <= 1000; i++) {
    y = (y * 10) % m;
    power1[i] = y;
  }
  if (m == 1) {
    cout << "0" << endl;
    return 0;
  }
  for (int i = 1; i <= 9; i++) {
    dp[1][i % k] += 1;
  }
  if (n == 1) {
    cout << dp[n][0] % m << "\n";
    return 0;
  }
  long long ans = (dp[1][0] * power1[n - 2]) % m;
  ans = (ans * 9) % m;
  dp[1][0] = 1;
  l = 1;
  for (int i = 2; i <= n; i++) {
    l = (l * 10) % k;
    int r;
    for (int t = 1; t <= 9; t++) {
      int temp = (l * t) % k;
      for (int r = 0; r <= k - 1; r++) {
        dp[i][(temp + r) % k] += dp[i - 1][r];
        dp[i][(temp + r) % k] %= m;
      }
    }
    long long mul;
    if (i == n)
      mul = 1;
    else {
      mul = (power1[n - i - 1] * 9) % m;
    }
    ans += (mul * dp[i][0]) % m;
    ans %= m;
    for (int t = 0; t <= k - 1; t++) {
      dp[i][t] += dp[i - 1][t];
      dp[i][t] %= m;
    }
    dp[i][0] = 1;
  }
  cout << ans << "\n";
}
