#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  char s1[5005], s2[5005];
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= m; u++) {
      if (s1[i] == s2[u]) {
        dp[i][u] = max(0, dp[i - 1][u - 1] + 2);
      } else {
        dp[i][u] = max(dp[i - 1][u], dp[i][u - 1]) - 1;
      }
      ans = max(ans, dp[i][u]);
    }
  }
  printf("%d\n", ans);
}
