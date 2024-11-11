#include <bits/stdc++.h>
using namespace std;
double f[101][101][2], p[101];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; i++) f[i][0][0] = 1, f[i][0][1] = 0;
  double ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      double temp = f[i - 1][j - 1][0] * p[i] + f[i - 1][j - 1][1] * (1 - p[i]);
      if (temp < f[i - 1][j][1]) {
        f[i][j][1] = f[i - 1][j][1];
        f[i][j][0] = f[i - 1][j][0];
      } else
        f[i][j][1] = temp, f[i][j][0] = f[i - 1][j - 1][0] * (1 - p[i]);
      ans = max(ans, f[i][j][1]);
    }
  printf("%.10lf\n", ans);
  return 0;
}
