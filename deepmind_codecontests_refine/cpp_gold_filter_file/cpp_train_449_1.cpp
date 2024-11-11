#include <bits/stdc++.h>
using namespace std;
int64_t t[2002], c[2002], dp[2002][2 * 2002];
void knapsack(int64_t n) {
  int64_t i, j;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= 2 * n; j++) {
      if (j == 0)
        dp[i][j] = 0;
      else if (i == 0)
        dp[i][j] = 100000000000000;
      else if (j >= t[i] + 1)
        dp[i][j] = min(dp[i - 1][j - t[i] - 1] + c[i], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
}
signed main() {
  int64_t n, i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> t[i] >> c[i];
  knapsack(n);
  int64_t ma = 1000000000000000;
  for (i = n; i <= 2 * n; i++)
    if (dp[n][i] <= ma) ma = dp[n][i];
  cout << ma << "\n";
}
