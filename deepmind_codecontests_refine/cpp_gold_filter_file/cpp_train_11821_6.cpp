#include <bits/stdc++.h>
using namespace std;
const int N = 500000;
int n, i, j, k;
double p[20][20], f[N][20];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%lf", &p[i][j]);
  f[1][1] = 1;
  for (i = 1; i <= (1 << n) - 1; i++) {
    for (j = 1; j <= n; j++)
      if (((1 << (j - 1)) | i) == i)
        for (k = 1; k <= n; k++)
          if (j != k)
            if (((1 << (k - 1)) | i) == i)
              f[i][j] = max(f[i][j], f[i - (1 << (j - 1))][k] * p[k][j] +
                                         f[i - (1 << (k - 1))][j] * p[j][k]);
  }
  double ans = 0;
  for (i = 1; i <= n; i++) ans = max(ans, f[(1 << n) - 1][i]);
  printf("%.8lf\n", ans);
}
