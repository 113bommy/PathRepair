#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 3;
char s[N], t[N];
int dp[N][N];
int main() {
  int n, m, ans = 0;
  scanf("%d%d%s%s", &n, &m, s, t);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
      if (s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
      ans = max(ans, dp[i][j] = max(dp[i][j], -2));
    }
  printf("%d\n", ans);
  return 0;
}
