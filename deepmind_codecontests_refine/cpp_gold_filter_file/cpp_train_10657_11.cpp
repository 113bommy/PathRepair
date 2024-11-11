#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct edge {
  int a, b;
  double c;
} e[N * 100];
int n, m;
double ans;
double a[N][N];
void gauss() {
  for (int i = 1; i <= n; ++i) {
    int now = i, pos = i;
    while (now <= n) {
      if (fabs(a[now][i]) > fabs(a[pos][i])) pos = now;
      ++now;
    }
    for (int j = 1; j <= n + 1; ++j) swap(a[i][j], a[pos][j]);
    if (fabs(a[i][i]) < 1e-10) continue;
    double x = a[i][i];
    for (int j = 1; j <= n + 1; ++j) a[i][j] /= x;
    for (int j = 1; j <= n; ++j)
      if (j != i && fabs(a[j][i]) > 1e-10) {
        double x = a[j][i] / a[i][i];
        for (int k = 1; k <= n + 1; ++k) a[j][k] -= x * a[i][k];
      }
  }
}
bool C(double x) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n + 1; ++j) a[i][j] = 0.0;
  for (int i = 1; i <= m; ++i) {
    if (e[i].b != 1 && e[i].b != n) {
      a[e[i].b][e[i].b] += 1.0;
      a[e[i].b][e[i].a] -= 1.0;
    }
    if (e[i].a != 1 && e[i].a != n) {
      a[e[i].a][e[i].a] += 1.0;
      a[e[i].a][e[i].b] -= 1.0;
    }
  }
  a[1][1] = 1.0;
  a[n][n] = 1.0;
  a[n][n + 1] = x;
  gauss();
  for (int i = 1; i <= m; ++i) {
    if (fabs(a[e[i].b][n + 1] - a[e[i].a][n + 1]) > e[i].c) return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%lf", &e[i].a, &e[i].b, &e[i].c);
  }
  double l = 0, r = 1e9 + 1;
  while (r - l > 1e-10) {
    double mid = (l + r) / 2.0;
    if (C(mid))
      l = ans = mid;
    else
      r = mid;
  }
  C(ans);
  ans = 0;
  for (int i = 1; i <= m; ++i) {
    if (e[i].b == n || e[i].a == n)
      ans += fabs(a[e[i].b][n + 1] - a[e[i].a][n + 1]);
  }
  printf("%.6f\n", ans);
  for (int i = 1; i <= m; ++i)
    printf("%.6f\n", a[e[i].b][n + 1] - a[e[i].a][n + 1]);
  return 0;
}
