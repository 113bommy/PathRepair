#include <bits/stdc++.h>
using namespace std;
double f[2005][2005];
int g[2005][2005];
int n, a, b;
double pa[2005], pb[2005];
double effect;
const double eps = 1e-8;
void cmax(double& a, int& b, double c, int d) {
  if (a + eps < c) {
    a = c;
    b = d;
  }
}
int check(double k) {
  effect = 0;
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= a; ++j) {
      if (j) {
        cmax(f[i][j], g[i][j], f[i - 1][j - 1] + pa[i], g[i - 1][j - 1]);
        cmax(f[i][j], g[i][j],
             f[i - 1][j - 1] + pb[i] - k + pa[i] - pa[i] * pb[i],
             g[i - 1][j - 1] + 1);
      }
      cmax(f[i][j], g[i][j], f[i - 1][j] + pb[i] - k, g[i - 1][j] + 1);
      cmax(f[i][j], g[i][j], f[i - 1][j], g[i - 1][j]);
    }
  }
  return g[n][a];
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%lf", &pa[i]);
  for (int i = 1; i <= n; ++i) scanf("%lf", &pb[i]);
  double l = -1e4, r = 1e4;
  while (r - l > eps) {
    double mid = (l + r) / 2.0;
    if (check(mid) < b)
      r = mid;
    else
      l = mid;
  }
  printf("%f\n", f[n][a] + l * b);
}
