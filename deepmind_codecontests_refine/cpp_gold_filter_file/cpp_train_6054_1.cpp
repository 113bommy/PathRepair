#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e6 + 5;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
long long dp[2000 + 5][1000 + 5];
long long ans = 0;
int main() {
  long long n;
  cin >> n;
  dp[0][0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n - i && j <= i; j++) {
      if (j == 0) {
        dp[i][j] = dp[i][j] + dp[i - 1][j + 1];
      } else {
        dp[i][j] = dp[i][j] + dp[i - 1][j + 1];
        dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
      }
      dp[i][j] %= mod;
      if (i % 2 == 1) {
        ans = ans + dp[i][j];
        ans = ans % mod;
      }
    }
  }
  printf("%I64d\n", ans);
}
