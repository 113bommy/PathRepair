#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[1005][1005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= max(m, n); i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 1) {
        dp[i][j] = i;
        continue;
      }
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      dp[i][j] %= mod;
    }
  }
  cout << 1LL * dp[n - 1][2 * k] * dp[m - 1][2 * k];
}
