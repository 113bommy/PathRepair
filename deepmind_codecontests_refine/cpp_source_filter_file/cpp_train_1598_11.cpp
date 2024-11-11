#include <bits/stdc++.h>
using namespace std;
double dp[222][444];
int p[222];
int a[222];
int main() {
  int n, l, k;
  scanf("%d%d%d", &n, &l, &k);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  for (int j = 0; j < n; j++) scanf("%d", &a[j]);
  for (int i = 0; i <= 200; i++) {
    for (int j = 0; j <= 400; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][k + 200] = 1;
  for (int ii = 0; ii < n; ii++) {
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 400; j > 0; j--) {
        if (dp[i][j]) {
          dp[i][j] = dp[i][j];
        }
        if (a[ii] == -1) {
          dp[i + 1][j - 1] += dp[i][j] * p[ii] / 100;
        } else {
          int kk = j + a[ii];
          if (kk >= 400) kk = 400;
          dp[i + 1][400] += dp[i][j] * p[ii] / 100;
        }
        dp[i][j] = dp[i][j] * (100 - p[ii]) / 100;
      }
    }
  }
  double sum = 0;
  for (int i = l; i <= n; i++) {
    for (int j = 200; j <= 400; j++) {
      sum += dp[i][j];
    }
  }
  printf("%.10lf\n", sum);
  return 0;
}
