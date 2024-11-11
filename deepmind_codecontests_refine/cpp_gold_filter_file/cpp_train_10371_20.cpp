#include <bits/stdc++.h>
using namespace std;
int n, truen, a[70][70];
double wwin[10][70], g[10][70], ltke;
int main() {
  scanf("%d", &n);
  truen = 1 << n;
  for (int i = 0; i < truen; i++)
    for (int j = 0; j < truen; j++) scanf("%d", &a[i][j]);
  for (int j = 0; j < truen; j++) wwin[0][j] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < truen; j++) {
      double tmp = 0;
      for (int k = (j ^ (1 << i - 1)) >> i - 1 << i - 1;
           k >> i == j >> i && k >> i - 1 != j >> i - 1; k++) {
        if (k != j)
          wwin[i][j] += wwin[i - 1][j] * wwin[i - 1][k] * (a[j][k] / 100.0);
        g[i][j] +=
            wwin[i - 1][j] * wwin[i - 1][k] * a[j][k] / 100.0 * (1 << i - 1);
        tmp = max(tmp, g[i - 1][k]);
      }
      g[i][j] += tmp + g[i - 1][j];
    }
  ltke = g[n][0];
  for (int j = 1; j < truen; j++)
    if (g[n][j] > ltke) ltke = g[n][j];
  printf("%.20lf", ltke);
}
