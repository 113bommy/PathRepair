#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;
const int MAXM = 100000;
const int MAXSIZE = 1048576;
int n, m;
int tab[MAXM + 3];
char r[MAXM + 3];
int ans[MAXSIZE + 3], dp[2][23][MAXSIZE];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", r + 1);
    for (int j = 1; j <= m; j++) tab[j] = (tab[j] << 1) + (r[j] - '0');
  }
  for (int i = 1; i <= m; i++) dp[0][0][tab[i]]++;
  for (int t = 1; t <= n; t++)
    for (int first = ((1 << n) - 1); first >= 0; first--)
      dp[0][t][first] = dp[0][t - 1][first];
  for (int k = 1; k <= n; k++) {
    for (int first = ((1 << n) - 1); first >= 0; first--)
      dp[k & 1][0][first] = 0;
    for (int t = 1; t <= n; t++)
      for (int first = ((1 << n) - 1); first >= 0; first--)
        dp[k & 1][t][first] = dp[k & 1][t - 1][first] +
                              dp[(k + 1) & 1][t - 1][first ^ (1 << (t - 1))];
    for (int first = ((1 << n) - 1); first >= 0; first--)
      ans[first] += dp[k & 1][n][first] * min(k, n - k);
  }
  int res = n * m;
  for (int first = ((1 << n) - 1); first >= 0; first--)
    res = min(res, ans[first]);
  printf("%d\n", res);
  return 0;
}
