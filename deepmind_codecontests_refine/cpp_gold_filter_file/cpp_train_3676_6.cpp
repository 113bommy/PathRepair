#include <bits/stdc++.h>
using namespace std;
const int N = 20, T = 11, X = 4;
long long dp[N][T][X][2];
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < X; i++)
    for (int j = i + 1; j < X; j++) dp[1][0][j][1]++;
  for (int i = 2; i < n; i++)
    for (int j = 0; j <= t; j++)
      for (int k = 0; k < X; k++) {
        for (int l = 0; l < k; l++)
          dp[i][j][k][1] += dp[i - 1][j][l][0] + dp[i - 1][j][l][1];
        for (int l = k + 1; l < X; l++)
          dp[i][j][k][0] +=
              dp[i - 1][j][l][0] + (j ? dp[i - 1][j - 1][l][1] : 0);
      }
  long long ans = 0;
  for (int i = 0; i < X; i++) ans += dp[n - 1][t][i][0];
  printf("%lld\n", ans);
  return 0;
}
