#include <bits/stdc++.h>
using namespace std;
const int MXN = 1010;
double dp[MXN][MXN];
double rec(int n, int m) {
  if (dp[n][m] >= 0) return dp[n][m];
  if (n == 0) return dp[n][m] = 1.0 / (m + 1);
  if (m == 0) return dp[n][m] = 1;
  double pa1 = 1.0;
  double pa2 = 1.0 - rec(m, n - 1);
  double pa3 = m / (m + 1.0) * (1 - rec(m - 1, n));
  double pa4 = 1.0 - m / (m + 1.0) * rec(m - 1, n);
  double p = (pa4 - pa2) / (pa1 + pa4 - pa2 - pa3);
  return dp[n][m] = pa1 * p + (1 - p) * pa2;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < MXN; i++)
    for (int j = 0; j < MXN; j++) dp[i][j] = -1;
  double ans = rec(n, m);
  printf("%.10lf %.10lf\n", ans, 1 - ans);
  return 0;
}
