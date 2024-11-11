#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int MOD = 998244353;
int dp[maxn][maxn << 1][4];
int main() {
  dp[1][1][0] = 1;
  dp[1][1][3] = 1;
  dp[1][2][2] = 1;
  dp[1][2][1] = 1;
  for (int i = 2; i <= 1000; i++) {
    for (int j = 1; j <= i * 2; j++) {
      for (int k = 0; k <= 3; k++) {
        dp[i][j][k] += dp[i - 1][j][k];
        if (k == 0 || k == 3) {
          dp[i][j][k] += dp[i - 1][j][k ^ 1];
          dp[i][j][k] += dp[i - 1][j][k ^ 2];
        }
        if (k == 0 || k == 3) {
          dp[i][j][k] += dp[i - 1][j - 1][k ^ k];
        } else {
          dp[i][j][k] += dp[i - 1][j - 1][0];
          dp[i][j][k] += dp[i - 1][j - 1][3];
        }
        if (k == 1 || k == 2) {
          if (j >= 2) dp[i][j][k] += dp[i - 1][j - 2][k ^ 3];
        }
        dp[i][j][k] %= MOD;
      }
    }
  }
  int N, K;
  while (cin >> N >> K) {
    long long ans = 0;
    for (int sta = 0; sta <= 3; sta++) {
      ans += dp[N][K][sta];
    }
    ans %= MOD;
    cout << ans << endl;
  }
}
