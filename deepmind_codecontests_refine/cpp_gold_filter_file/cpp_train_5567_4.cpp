#include <bits/stdc++.h>
using namespace std;
int dp[30004][505], gem[30004];
int main() {
  int i, j, n, d, x, m, p, ans = 0;
  cin >> n >> d;
  for (i = 1; i <= n; i++) {
    cin >> x;
    gem[x]++;
  }
  for (i = 0; i <= 30000; i++)
    for (j = 0; j <= 500; j++) dp[i][j] = -1;
  ans = dp[d][250] = gem[d];
  for (i = d + 1; i <= 30000; i++) {
    for (j = 1; j < 500; j++) {
      m = j + d - 250;
      if (m <= 0)
        continue;
      else if (m == 1) {
        p = i - 1;
        dp[i][j] = max(dp[p][j], dp[p][j + 1]);
      } else {
        p = i - m;
        if (p < 0) continue;
        dp[i][j] = max(dp[p][j], max(dp[p][j - 1], dp[p][j + 1]));
      }
      if (dp[i][j] == -1)
        continue;
      else
        dp[i][j] += gem[i];
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
