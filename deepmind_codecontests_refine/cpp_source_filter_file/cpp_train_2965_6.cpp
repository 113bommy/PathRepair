#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 35;
const int MAX_K = 105;
double dp[MAX_N][MAX_N][MAX_K];
int a[MAX_N];
int n, k;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i] > a[j]) {
        dp[i][j][0] = 1.0;
      }
    }
  }
  for (int t = 1; t <= k; t++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int l = 1; l <= n; l++) {
          for (int r = l; r <= n; r++) {
            int oldl = i, oldr = j;
            if (l <= i && i <= r) {
              oldl = l + r - i;
            }
            if (l <= j && j <= r) {
              oldr = l + r - j;
            }
            dp[i][j][t] += dp[oldl][oldr][t - 1] * 2.0 / n / (n + 1);
          }
        }
      }
    }
  }
  double res = 0.0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      res += dp[i][j][k];
    }
  }
  cout << fixed << setprecision(12) << res;
  return 0;
}
