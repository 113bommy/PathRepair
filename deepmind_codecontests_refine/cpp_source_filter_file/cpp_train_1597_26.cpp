#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 2e2 + 10;
double dp[N][N][N * 2];
double p[N];
int main() {
  int offset = 200;
  int maxv = 400;
  memset((dp), (0), sizeof(dp));
  int n, l, k;
  cin >> n >> l >> k;
  dp[0][0][200 + k] = 1;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < i; j++) {
      for (int k = maxv; k >= 0; k--) {
        if (dp[i - 1][j][k] < 1e-10) continue;
        dp[i][j + 1][min(maxv, k + x)] += dp[i - 1][j][k] * p[i] / 100.0;
        dp[i][j][k] += dp[i - 1][j][k] * (100 - p[i]) / 100;
      }
    }
  }
  double ans = 0;
  for (int i = l; i <= n; i++) {
    for (int j = offset; j <= maxv; j++) {
      ans += dp[n][i][j];
    }
  }
  printf("%.15f\n", ans);
  return 0;
}
