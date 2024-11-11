#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;
double dp[maxn][maxn][maxn], p[maxn];
int a[maxn];
int n, l, bag;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> l >> bag;
  for (int i = 0; i < n; i++) cin >> p[i], p[i] /= 100.;
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[0][0][bag + 200] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = -200; k <= 200; k++) {
        int kk = k + a[i];
        ((kk) = min((kk), (200)));
        dp[i + 1][j][k + 200] += dp[i][j][k + 200] * (1. - p[i]);
        dp[i + 1][j + 1][kk + 200] += dp[i][j][k + 200] * p[i];
      }
    }
  }
  double ans = 0;
  for (int j = l; j <= n; j++)
    for (int k = 0; k <= 200; k++) ans += dp[n][j][k + 200];
  cout.precision(10);
  cout << fixed << ans << endl;
  return 0;
}
