#include <bits/stdc++.h>
using namespace std;
int a[55];
double dp[55][55];
int n, p;
void init() {
  for (int i = 0; i <= p; ++i) {
    for (int j = 0; j <= p; ++j) {
      dp[i][j] = 0.0;
    }
  }
  dp[0][0] = 1.0;
}
double A[55];
int main() {
  A[0] = 1;
  for (int i = 1; i <= 50; ++i) A[i] = A[i - 1] * (double)(i);
  while (~scanf("%d", &n)) {
    int s0 = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      s0 += a[i];
    }
    scanf("%d", &p);
    if (s0 <= p) {
      printf("%d\n", n);
      continue;
    }
    double ret = 0;
    for (int i = 0; i < n; ++i) {
      init();
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        for (int k = 0; k <= j; ++k) {
          for (int l = a[j]; l <= p; ++l) {
            if (dp[k][l - a[j]] > 0) {
              dp[k + 1][l] += dp[k][l - a[j]];
            }
          }
        }
      }
      for (int j = p - a[i] + 1; j <= p; ++j) {
        for (int k = 1; k <= n - 1; ++k) {
          ret += dp[k][j] * A[k] * k * A[n - k - 1];
        }
      }
    }
    ret /= A[n];
    printf("%.10lf\n", ret);
  }
  return 0;
}
