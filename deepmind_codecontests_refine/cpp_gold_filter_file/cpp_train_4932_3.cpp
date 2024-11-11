#include <bits/stdc++.h>
using namespace std;
int a[51];
int p;
int top;
double dp[61][61][2501];
double nfact[61];
double rfact[61];
double exceed[61];
double cnk[51][51];
int main() {
  for (int i = 0; i < (51); i++) {
    cnk[i][0] = 1;
    for (int j = 1; j < i; j++) cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
    cnk[i][i] = 1;
  }
  int n;
  scanf("%d", &n);
  nfact[0] = 1;
  rfact[n] = 1;
  for (int i = 0; i < (50); i++) nfact[i + 1] = nfact[i] * (i + 1);
  for (int i = n - 1; i >= 0; i--) rfact[i] = rfact[i + 1] * (i + 1);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  scanf("%d", &p);
  if (sum <= p) {
    printf("%.10lf\n", (double)n);
    return 0;
  }
  dp[0][0][0] = 1;
  double res = 0;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (n); j++) {
      for (int k = 2500; k >= 0; k--) {
        if (dp[i][j][k]) {
          dp[i + 1][j][k] += dp[i][j][k];
          if (k + a[i] > p) exceed[j + 1] += dp[i][j][k];
          dp[i + 1][j + 1][k + a[i]] += dp[i][j][k];
        }
      }
    }
  }
  for (int i = 0; i < (n + 1); i++) exceed[i] /= cnk[n][i];
  for (int i = n - 1; i >= 0; i--) {
    exceed[i + 1] -= exceed[i];
  }
  for (int i = 0; i < (n); i++) {
    res += i * exceed[i + 1];
  }
  printf("%.9lf\n", res);
}
