#include <bits/stdc++.h>
using namespace std;
int iin() {
  int x;
  scanf("%d", &x);
  return x;
}
const int Max = 900;
const int N = 101;
double dp[N][N], ddp[N][N];
int a[N];
int main() {
  int n = iin(), K = min(Max - 1, iin());
  for (int i = 0; i < n; i++) a[i] = iin();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) dp[i][j] = (a[i] > a[j]);
  for (int k = 0; k < K; k++) {
    for (int p = 1; p < n; p++) {
      for (int i = 0; i + p < n; i++) {
        int j = i + p;
        ddp[i][j] = ((i * (i + 1)) / 2 + ((n - j - 1) * (n - j)) / 2 +
                     (j - i - 1) * (j - i) / 2) *
                    dp[i][j];
        for (int m = 0; m < j; m++) {
          ddp[i][j] += dp[m][j] * min(min(i + 1, m + 1), j - max(m, i));
          int ii = (j + m) - i;
          if (ii < n && m < i + 1)
            ddp[i][j] +=
                (1 - dp[m][ii]) * min(min(m + 1, i + 1), n - max(j, ii));
        }
        for (int m = i + 1; m < n; m++) {
          ddp[i][j] += dp[i][m] * min(min(j, m) - i, n - max(m, j));
          int ii = (j + m) - i;
          if (ii < n)
            ddp[i][j] +=
                (1 - dp[m][ii]) * min(min(m + 1, i + 1), n - max(j, ii));
        }
        ddp[i][j] = ddp[i][j] / ((n * (n + 1)) / 2);
      }
    }
    swap(ddp, dp);
  }
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) ans += dp[i][j];
  printf("%.17f\n", ans);
}
