#include <bits/stdc++.h>
using namespace std;
double f[64][64][64];
double C[56][56];
int n, m;
int a[56];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 0; i <= 51; i++) C[i][0] = 1;
  for (int i = 1; i <= 51; i++)
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  for (int i = 0; i <= n; i++) f[0][0][i] = i;
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= n; k++)
        for (int c = 0; c <= i; c++) {
          int M = max(k, (c + a[j] - 1) / a[j]);
          f[i][j][k] +=
              pow(j - 1, i - c) / pow(j, i) * f[i - c][j - 1][M] * C[i][c];
        }
  printf("%.10lf\n", f[n][m][0]);
  return 0;
}
