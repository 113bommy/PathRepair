#include <bits/stdc++.h>
using namespace std;
int n;
long double p[110], ans, f[5000 | 10][110 * 3];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) scanf("%Lf", &p[i]);
  for (int i = 0; i <= 5000 + 1; ++i)
    for (int j = 0; j <= 2 * n; ++j) f[i][j] = -1;
  f[0][n] = 0;
  for (int i = 0; i < 5000; ++i)
    for (int j = 0; j <= 2 * n; ++j) {
      if (f[i][j] >= 0)
        for (int k = 0; k <= n; ++k)
          if (j + n >= (k << 1) && f[i + 1][j + n - k * 2] < f[i][j] + p[k])
            f[i + 1][j + n - k * 2] = f[i][j] + p[k];
    }
  for (int i = 1; i <= 5000; ++i) ans = max(ans, f[i][n] / i);
  printf("%.10Lf", ans);
}
