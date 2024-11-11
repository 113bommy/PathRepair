#include <bits/stdc++.h>
using namespace std;
const int maxn = 2020;
int n, a, b;
double p[maxn], u[maxn];
double f[maxn][maxn];
int g[maxn][maxn];
const double eps = 1e-5;
void update(double &t, int &x, double f, int y) {
  if (f > t + eps) {
    t = f;
    x = y;
  }
}
void calc(double k) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= a; j++) {
      f[i][j] = 0;
      g[i][j] = 0;
      update(f[i][j], g[i][j], f[i - 1][j], g[i - 1][j]);
      update(f[i][j], g[i][j], f[i - 1][j] + u[i] - k, g[i - 1][j] + 1);
      if (j) update(f[i][j], g[i][j], f[i - 1][j - 1] + p[i], g[i - 1][j - 1]);
      if (j)
        update(f[i][j], g[i][j],
               f[i - 1][j - 1] + 1 - (1 - p[i]) * (1 - u[i]) - k,
               g[i - 1][j - 1] + 1);
    }
  }
}
int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    cin >> u[i];
  }
  double l = 0, r = 1e9;
  int T = 50;
  double ansf;
  while (T--) {
    double mid = (l + r) / 2;
    calc(mid);
    if (g[n][a] <= b)
      r = mid;
    else
      l = mid;
  }
  calc(l);
  printf("%.8f\n", f[n][a] + b * l);
  return 0;
}
