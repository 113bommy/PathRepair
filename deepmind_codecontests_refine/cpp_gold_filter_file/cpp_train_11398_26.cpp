#include <bits/stdc++.h>
using namespace std;
int bigmod(int a, int p, int mod) {
  if (p == 0) {
    int ans = 1 % mod;
    return ans;
  }
  if (p == 1) {
    int ans = (1 * a) % mod;
    return ans;
  }
  int ans = bigmod(a, p / 2, mod);
  ans = (ans * ans) % mod;
  if (p % 2 == 1) {
    ans = (a * ans) % mod;
  }
  return ans;
}
int main() {
  int n, k;
  long long m;
  cin >> n >> k >> m;
  long long dp[n + 3][k + 3], dp2[n + 3][k + 3];
  if (n == 1) {
    int cnt = 0;
    for (int i = 1; i <= 9; i++) {
      if (i % k == 0) {
        cnt++;
      }
    }
    cout << cnt % m;
    return 0;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = 0;
      dp2[i][j] = 0;
    }
  }
  for (int i = 0; i <= 9; i++) {
    dp[1][i % k] = (dp[1][i % k] + 1) % m;
  }
  dp2[1][0] = 1 % m;
  for (int i = 2; i < n; i++) {
    dp[i][0] = (1LL * 10 * dp[i - 1][0]) % m;
    dp2[i][0] = 1 % m;
    int r = bigmod(10, i - 1, k);
    for (int j = 0; j <= 9; j++) {
      int x = (r * j) % k;
      for (int l = 1; l < k; l++) {
        dp[i][(x + l) % k] = (dp[i][(x + l) % k] + dp[i - 1][l]) % m;
      }
      for (int l = 0; l < k; l++) {
        if ((x + l) % k != 0) {
          dp2[i][(x + l) % k] = (dp2[i][(x + l) % k] + dp2[i - 1][l]) % m;
        }
      }
    }
  }
  dp[n][0] = (1LL * 9 * dp[n - 1][0]) % m;
  dp2[n][0] = 0;
  int r = bigmod(10, n - 1, k);
  for (int j = 1; j <= 9; j++) {
    int x = (r * j) % k;
    for (int l = 1; l < k; l++) {
      dp[n][(x + l) % k] = (dp[n][(x + l) % k] + dp[n - 1][l]) % m;
    }
    for (int l = 0; l < k; l++) {
      if ((x + l) % k != 0) {
        dp2[n][(x + l) % k] = (dp2[n][(x + l) % k] + dp2[n - 1][l]) % m;
      }
    }
  }
  long long ans = dp[n][0];
  for (int i = 0; i < k; i++) {
    ans = (ans + m - dp2[n][i]) % m;
  }
  cout << ans;
  return 0;
}
