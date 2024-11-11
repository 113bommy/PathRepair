#include <bits/stdc++.h>
using namespace std;
const int N = 320 + 5, P = 1e9 + 7;
int dp[2][N][N] = {1};
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= min(i, n); j++) {
      dp[i & 1][j][0] =
          (i != x ? dp[i & 1 ^ 1][j][0] + dp[i & 1 ^ 1][j][1] : 0);
      for (int k = 1; k <= j; k++) {
        dp[i & 1][j][k] =
            (j ? dp[i & 1 ^ 1][j - 1][k] + dp[i & 1 ^ 1][j - 1][k - 1] : 0) % P;
        (dp[i & 1][j][k] +=
         (i != x ? dp[i & 1 ^ 1][j][k] + dp[i & 1 ^ 1][j][k + 1] : 0) % P) %= P;
      }
    }
  int ans = (n <= m ? dp[m & 1][n][0] + dp[m & 1][n][1] : 0) % P;
  for (int i = 1; i <= n; i++) ans = 1LL * ans * i % P;
  cout << ans << endl;
  return 0;
}
