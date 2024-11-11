#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-7;
using namespace std;
const int N = 55;
int n, m;
int a[N];
double pw[N], c[N][N], dp[N][N][N];
void solve() {
  cin >> n >> m;
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * (1 / (double)m);
  for (int i = 0; i < N; i++) c[i][0] = 1.0;
  for (int i = 1; i < N; i++)
    for (int j = 1; j < N; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  for (int i = 1; i <= m; i++) cin >> a[i];
  dp[0][0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        double v = dp[i - 1][j][k];
        if (abs(v) < eps) continue;
        for (int t = 0; t <= n - j; t++) {
          int my_mx = (t + a[i] - 1) / a[i];
          dp[i][j + t][max(k, my_mx)] += c[n - j][t] * pw[t] * v;
        }
      }
    }
  }
  double ans = 0.0;
  for (int i = 1; i <= n; i++) {
    ans += dp[m][n][i] * (double)i;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(10);
  int step;
  step = 1;
  for (int i = 1; i <= step; i++) {
    solve();
  }
}
