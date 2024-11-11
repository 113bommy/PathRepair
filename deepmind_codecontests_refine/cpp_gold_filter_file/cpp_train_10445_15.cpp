#include <bits/stdc++.h>
using namespace std;
double dp[222][222][222];
double p[222];
int a[222];
int main() {
  int n, l, k;
  cin >> n >> l >> k;
  int i, j;
  for (i = 1; i <= n; i++) {
    cin >> p[i];
    p[i] /= 100.0;
  }
  a[0] = k;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++;
  }
  dp[0][0][k] = 1.0;
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      for (int kk = 0; kk <= 200; kk++) {
        if (dp[i][j][kk] > 0) {
          int bb = min(200, kk + a[i + 1]);
          dp[i + 1][j + 1][bb] += dp[i][j][kk] * p[i + 1];
          dp[i + 1][j][kk] += dp[i][j][kk] * (1 - p[i + 1]);
        }
      }
    }
  }
  double ans = 0.0;
  for (i = l; i <= 200; i++) {
    for (j = i; j <= 200; j++) {
      ans += dp[n][i][j];
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
