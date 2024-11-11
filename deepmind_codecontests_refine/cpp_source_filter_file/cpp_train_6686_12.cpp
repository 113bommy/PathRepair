#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
int dp[53][maxn], mxp[53][maxn], mxs[53][maxn], n, m, a[53][maxn], k,
    sum[53][maxn], h1, h2, t1, t2;
pair<int, int> q1[maxn], q2[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]), sum[i][j] = sum[i][j - 1] + a[i][j];
  for (int i = 1; i <= m; ++i)
    dp[1][i] = sum[1][min(i + k - 1, m)] - sum[1][i - 1];
  for (int i = 1; i <= m; ++i)
    mxp[1][i] = max(mxp[1][i - 1],
                    dp[1][i] + sum[2][min(i + k - 1, m)] - sum[2][i - 1]);
  for (int i = m; i >= 1; --i)
    mxs[1][i] = max(mxs[1][i + 1],
                    dp[1][i] + sum[2][min(i + k - 1, m)] - sum[2][i - 1]);
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (j + k <= m)
        dp[i][j] = max(dp[i][j], mxs[i - 1][j + k] + sum[i][min(j + k - 1, m)] -
                                     sum[i][j - 1]);
      if (j - k >= 1)
        dp[i][j] = max(dp[i][j], mxp[i - 1][j - k] + sum[i][min(j + k - 1, m)] -
                                     sum[i][j - 1]);
    }
    h1 = h2 = 1;
    t1 = t2 = 0;
    for (int j = 1; j <= m; ++j) {
      while (h1 <= t1 && q1[h1].first < j - k + 1) h1++;
      int num = dp[i - 1][j] - sum[i][j - 1];
      while (h1 <= t1 && q1[t1].second <= num) t1--;
      q1[++t1] = {j, num};
      if (h1 <= t1)
        dp[i][j] = max(dp[i][j], q1[h1].second + sum[i][min(m, j + k - 1)]);
    }
    for (int j = m; j >= 1; --j) {
      while (h2 <= t2 && q2[h2].first > j + k - 1) h2++;
      if (h2 <= t2) dp[i][j] = max(dp[i][j], q2[h2].second - sum[i][j - 1]);
      int num = dp[i - 1][j] + sum[i][min(j + k - 1, m)];
      while (h2 <= t2 && q2[t2].second <= num) t2--;
      q2[++t2] = {j, num};
    }
    for (int j = 1; j <= m; ++j) {
      mxp[i][j] = max(mxp[i][j - 1], dp[i][j] + sum[i + 1][min(m, j + k - 1)] -
                                         sum[i + 1][j - 1]);
    }
    for (int j = m; j >= 1; --j) {
      mxs[i][j] = max(mxs[i][j + 1], dp[i][j] + sum[i + 1][min(m, j + k - 1)] -
                                         sum[i + 1][j - 1]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i + k - 1 > m) break;
    ans = max(ans, dp[n][i]);
  }
  cout << ans << "\n";
  return 0;
}
