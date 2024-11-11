#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101, MAX_M = 1001;
double dp[2][MAX_N * MAX_M], eps = 1e-10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, s, i, a, j;
  double cs;
  cin >> n >> m >> s;
  for (i = 1; i < s; i++) dp[0][i] = 1.0;
  for (i = s + 1; i <= m; i++) dp[0][i] = 1.0;
  if (m == 1) {
    cout << 1 << '\n';
    return 0;
  }
  for (i = 1; i < n; i++) {
    cin >> a;
    s += a;
    cs = 0.0;
    for (j = 1; j <= (i + 1) * m; j++) {
      dp[i & 1][j] = cs;
      if (j > a) dp[i & 1][j] -= dp[(i - 1) & 1][j - a];
      dp[i & 1][j] /= double(m - 1);
      cs += dp[(i - 1) & 1][j];
      if (j > m) cs -= dp[(i - 1) & 1][j - m];
    }
  }
  cs = 1.0;
  i--;
  for (j = 1; j < s; j++) cs += dp[i & 1][j];
  printf("%.9lf\n", cs);
}
