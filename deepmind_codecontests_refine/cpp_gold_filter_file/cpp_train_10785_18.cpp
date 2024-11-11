#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e3 + 10;
const double eps = 1e-6;
int dp[MAX][MAX];
int main() {
  int n, m, aim, i, j, a[MAX], b[MAX];
  cin >> n >> m >> aim;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  memset(dp, 0, sizeof(dp));
  for (i = 1; i <= n; i++)
    for (j = i; j <= m; j++) {
      if (i == j)
        dp[i][j] = max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - aim));
      else
        dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1],
                                         abs(a[i] - b[j]) + abs(b[j] - aim)));
    }
  cout << dp[n][m] << endl;
}
