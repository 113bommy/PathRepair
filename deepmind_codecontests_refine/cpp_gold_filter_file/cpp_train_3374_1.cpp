#include <bits/stdc++.h>
using namespace std;
const int inf = (int)(2e+9) + 31;
int n, m, a[21], b[21], d[42][42], r[42][42], matrix[42][42], t[42][42];
void multiply(int x[42][42], int y[42][42], int z[42][42]) {
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++) {
      t[i][j] = inf;
      for (int k = 0; k <= 2 * n; k++)
        if (x[i][k] != inf && y[k][j] != inf)
          t[i][j] = min(t[i][j], x[i][k] + y[k][j]);
    }
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++) z[i][j] = t[i][j];
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int start = 0; start <= 2 * n; start++) {
    for (int i = 0; i <= 2 * n; i++)
      for (int j = 0; j <= 2 * n; j++) d[i][j] = inf;
    d[0][start] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= 2 * n; j++)
        if (d[i][j] != inf) {
          if (j + 1 <= 2 * n)
            d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + a[i]);
          if (j - 1 >= 0)
            d[i + 1][j - 1] = min(d[i + 1][j - 1], d[i][j] + b[i]);
        }
    for (int i = 0; i <= 2 * n; i++) matrix[start][i] = d[n][i];
  }
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++) r[i][j] = inf;
  r[0][0] = 0;
  while (m > 0) {
    if (m & 1) multiply(r, matrix, r);
    multiply(matrix, matrix, matrix);
    m >>= 1;
  }
  cout << r[0][0];
}
