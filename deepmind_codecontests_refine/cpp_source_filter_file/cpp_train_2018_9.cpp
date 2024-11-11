#include <bits/stdc++.h>
using namespace std;
int n, m, a[55], c[55][55];
double f[55][55][55], aa = 0, bb = 0;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }
  f[0][0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        for (int l = j; l <= n; l++) {
          f[i + 1][l][max(k, (l - j + a[i] - 1) / a[i])] +=
              c[l][j] * f[i][j][k];
        }
  }
  for (int i = 1; i <= n; i++) {
    aa += i * f[m][n][i];
    bb += f[m][n][i];
  }
  printf("%.10lf\n", aa / bb);
}
