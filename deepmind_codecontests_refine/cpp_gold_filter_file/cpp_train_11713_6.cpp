#include <bits/stdc++.h>
using namespace std;
int a[110];
double dp[2][100200];
double sum[100200];
int main() {
  int n, m;
  cin >> n >> m;
  int M = n * m;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt += a[i];
  }
  if (m == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int j = 1; j <= m; j++) {
    if (j != a[1])
      dp[1][j] = 1.0;
    else
      dp[1][j] = 0;
  }
  for (int i = 2; i <= n; i++) {
    double *s = dp[(i - 1) & 1];
    double *t = dp[i & 1];
    for (int j = 1; j <= M; j++) sum[j] = sum[j - 1] + s[j];
    for (int j = 1; j <= M; j++) {
      t[j] = sum[j - 1];
      if (j > m) t[j] -= sum[j - m - 1];
      if (j >= a[i]) t[j] -= s[j - a[i]];
      t[j] /= (m - 1);
    }
  }
  double ans = 0;
  for (int j = 1; j < cnt; j++) {
    ans += dp[n & 1][j];
  }
  printf("%.13lf\n", ans + 1);
}
