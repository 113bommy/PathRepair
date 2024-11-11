#include <bits/stdc++.h>
using namespace std;
int n, L;
int a[55];
long long dp[2][55][55];
double res;
long long c[55][55];
void preCalc() {
  c[0][0] = 1;
  for (int i = 0; i <= 50; i++)
    for (int j = 0; j <= 50; j++) {
      if (i) c[i][j] += c[i - 1][j];
      if (i && j) c[i][j] += c[i - 1][j - 1];
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &L);
  preCalc();
  res = 0;
  int v = 0;
  memset(dp[v], 0, sizeof(dp[v]));
  dp[v][0][0] = 1;
  v ^= 1;
  for (int nn = 1; nn <= n; nn++) {
    memset(dp[v], 0, sizeof(dp[v]));
    for (int kk = 0; kk <= nn; kk++) {
      for (int LL = 0; LL <= L; LL++) {
        if (dp[1 ^ v][kk][LL]) {
          if (LL + a[nn] <= L) {
            dp[v][kk + 1][LL + a[nn]] += dp[1 ^ v][kk][LL];
          }
          dp[v][kk][LL] += dp[1 ^ v][kk][LL];
        }
      }
    }
    v ^= 1;
  }
  for (int kk = 0; kk <= n; kk++) {
    long long t = 0;
    for (int LL = 0; LL <= L; LL++) {
      t += dp[1 ^ v][kk][LL];
    }
    res += t * 1.0 / c[n][kk];
  }
  printf("%f\n", res);
  return 0;
}
