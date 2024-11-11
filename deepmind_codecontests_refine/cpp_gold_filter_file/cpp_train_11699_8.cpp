#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-9;
int n, m, k, lo, hi;
double dp[2][200015], ans;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  dp[0][k] = 1.0;
  lo = hi = k;
  for (int(ii) = (0); (ii) < (n + m); (ii)++) {
    int i = ii & 1;
    while (dp[i][lo] < eps && lo < hi) lo++;
    while (dp[i][hi] < eps && lo < hi) hi--;
    for (int(j) = (lo); (j) <= (hi); (j)++) {
      if ((ii - (j - k)) % 2) continue;
      int n0 = (ii - (j - k)) / 2, n1 = (ii - n0);
      if (n0 < 0 || n1 < 0 || n0 > m || n1 > n) continue;
      if (n0 < m && j > 0)
        dp[i ^ 1][j - 1] += dp[i][j] * (m - n0) / (double)(n + m - ii);
      if (n1 < n)
        dp[i ^ 1][j + 1] += dp[i][j] * (n - n1) / (double)(n + m - ii);
      dp[i][j] = 0.0;
    }
    lo = max(lo - 1, 0);
    hi = hi + 1;
  }
  for (int(i) = (lo); (i) <= (hi); (i)++) ans += dp[(n + m) & 1][i];
  printf("%.12lf\n", ans);
  return 0;
}
