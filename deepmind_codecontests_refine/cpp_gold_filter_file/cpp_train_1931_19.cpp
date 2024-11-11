#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 7;
int n, m, k;
int dp[MAXN][MAXN][15][2];
char s1[MAXN], s2[MAXN];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i] == s2[j])
        for (int t = 1; t <= k; t++)
          dp[i][j][t][0] =
              max(dp[i - 1][j - 1][t][0], dp[i - 1][j - 1][t - 1][1]) + 1;
      for (int t = 1; t <= k; t++)
        dp[i][j][t][1] = max(max(dp[i - 1][j - 1][t][1], dp[i - 1][j][t][1]),
                             max(dp[i][j - 1][t][1], dp[i][j][t][0]));
    }
  }
  printf("%d\n", dp[n][m][k][1]);
  return 0;
}
