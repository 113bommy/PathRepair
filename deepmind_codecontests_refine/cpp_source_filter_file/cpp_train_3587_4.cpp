#include <bits/stdc++.h>
using namespace std;
int n, m, k, nk;
long long dp[1505][1505], Q[1505][3005], s[1505][1505], ans;
void upd(int i, int j, int k) {
  j += m;
  Q[i][j] = k;
  for (j >>= 1; j > 0; j >>= 1) Q[i][j] = max(Q[i][j + j], Q[i][j + j + 1]);
}
long long getMax(int i, int l, int r) {
  long long res = -((long long)1e18);
  for (l += m, r += m; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
    if (l & 1) res = max(res, Q[i][l]);
    if (!(r & 1)) res = max(res, Q[i][r]);
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m + m; ++j) Q[i][j] = -((long long)1e18);
    for (int j = 0; j < m; ++j)
      scanf("%d", &k), s[i][j] = k + (j > 0 ? s[i][j - 1] : 0),
                       upd(i, j, s[i][j]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = s[i][j];
      if (i > 0)
        if (i & 1)
          dp[i][j] += getMax(i - 1, j + 1, m - 1);
        else
          dp[i][j] += getMax(i - 1, 0, j - 1);
      upd(i, j, dp[i][j]);
    }
  }
  ans = -((long long)1e18);
  for (int i = 0; i < m; ++i) {
    if (n % 2 == 0 && i + 1 == m) continue;
    ans = max(dp[n - 1][i], ans);
  }
  printf("%I64d", ans);
  return 0;
}
