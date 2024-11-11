#include <bits/stdc++.h>
const int N = 55;
const double inf = 1e17;
using namespace std;
int n;
struct node {
  int h, w;
  bool friend operator<(node a, node b) { return a.h > b.h; }
} a[N];
double f[N][N][N];
void upd(double &x, double y) {
  if (y < x) x = y;
}
bool Chk(double x) {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) f[0][i][j] = inf;
  f[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    double val = a[i].h - x * a[i].w;
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= n; ++k) f[i][j][k] = inf;
    if (i == 1 || a[i].h != a[i - 1].h) {
      for (int j = 0; j <= i - 1; ++j)
        for (int k = 0; k <= i - 1 - j; ++k) {
          upd(f[i][j + k][1], f[i - 1][j][k] + val);
          if (j + k - 1 >= 0) upd(f[i][j + k - 1][0], f[i - 1][j][k]);
        }
    } else {
      for (int j = 0; j <= i - 1; ++j)
        for (int k = 0; k <= i - 1 - j; ++k) {
          upd(f[i][j][k + 1], f[i - 1][j][k] + val);
          if (j - 1 >= 0) upd(f[i][j - 1][k], f[i - 1][j][k]);
        }
    }
  }
  for (int j = 0; j <= n; ++j)
    for (int k = 0; k <= n; ++k)
      if (f[n][j][k] < 0) return true;
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].h);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].w);
  sort(a + 1, a + n + 1);
  double l = 0, r = 0;
  for (int i = 1; i <= n; ++i) r += a[i].h;
  for (int t = 1; t <= 60; ++t) {
    double mid = (l + r) / 2;
    if (Chk(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.f\n", ceil(l * 1000));
  return 0;
}
