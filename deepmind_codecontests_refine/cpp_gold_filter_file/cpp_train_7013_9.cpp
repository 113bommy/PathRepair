#include <bits/stdc++.h>
using namespace std;
int n, L;
int a[55];
long long dp[55][55][55][55];
double res;
double sk[55];
void preCalc() {
  sk[0] = 1.0 / n;
  sk[n - 1] = sk[0];
  for (int i = 1; i < n - 1; i++) {
    sk[i] = sk[i - 1] * i / (n - i);
  }
}
int main() {
  memset(dp, 0, sizeof(dp));
  scanf("%d", &n);
  int r = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    r += a[i];
  }
  scanf("%d", &L);
  if (r <= L) {
    printf("%f\n", (double)n);
    return 0;
  }
  preCalc();
  res = 0;
  for (int ms = 1; ms <= n; ms++) {
    dp[ms][0][0][0] = 1;
    for (int nn = 1; nn <= n; nn++) {
      for (int kk = 0; kk <= n - 1; kk++) {
        for (int LL = 0; LL <= L; LL++) {
          if (dp[ms][nn - 1][kk][LL]) {
            if (LL + a[nn] <= L && nn != ms) {
              dp[ms][nn][kk + 1][LL + a[nn]] += dp[ms][nn - 1][kk][LL];
            }
            dp[ms][nn][kk][LL] += dp[ms][nn - 1][kk][LL];
          }
        }
      }
    }
    for (int kk = 0; kk <= n - 1; kk++) {
      for (int LL = max(0, L - a[ms] + 1); LL <= L; LL++) {
        res += sk[kk] * dp[ms][n == ms ? n - 1 : n][kk][LL] * kk;
      }
    }
  }
  printf("%f\n", res);
  return 0;
}
