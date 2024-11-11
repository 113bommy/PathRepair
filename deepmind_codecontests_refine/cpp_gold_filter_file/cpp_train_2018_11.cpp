#include <bits/stdc++.h>
using namespace std;
const int MAXN = 51;
int a[MAXN];
long double dp[51][51][51];
long double POW1[51][51], POWnsub1[51][51];
long long C[51][51];
void init() {
  for (int i = 0; i <= 50; i++) {
    for (int j = 0; j <= 50; j++) {
      POW1[i][j] = pow(1.0 / i, j + 0.0);
      POWnsub1[i][j] = pow(1.0 - 1.0 / i, j + 0.0);
    }
  }
  C[0][0] = 1;
  for (int i = 1; i <= 50; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j <= 50; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}
int main() {
  init();
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= j; k++) {
          for (int jj = j; jj <= n; jj++) {
            int x = (jj - j) / a[i + 1] + (((jj - j) % a[i + 1]) > 0);
            int kk;
            if (x <= k)
              kk = k;
            else
              kk = x;
            long double p = POW1[m][jj - j] * C[n - j][jj - j];
            dp[i + 1][jj][kk] += dp[i][j][k] * p;
          }
        }
      }
    }
    double ans = 0.0;
    for (int k = 1; k <= n; k++) {
      ans += dp[m][n][k] * (k + 0.0);
    }
    printf("%.15f\n", ans);
  }
  return 0;
}
