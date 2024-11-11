#include <bits/stdc++.h>
using namespace std;
double f[1001][1001];
int n, m, x, y;
int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  n = n - x + 1;
  for (int i = 2; i <= n; i++)
    for (int time = 1; time <= 20; time++)
      if (m == 1)
        f[i][1] = (f[i][1] + f[i - 1][1]) / 2.0 + 1;
      else {
        f[i][1] = (f[i][1] + f[i][2] + f[i - 1][1]) / 3.0 + 1;
        f[i][m] = (f[i][m] + f[i][m - 1] + f[i - 1][m]) / 3.0 + 1;
        for (int j = 2; j < m; ++j)
          f[i][j] =
              (f[i][j] + f[i][j - 1] + f[i][j + 1] + f[i - 1][j]) / 4.0 + 1;
      }
  printf("%.9lf", f[n][y]);
  return 0;
}
