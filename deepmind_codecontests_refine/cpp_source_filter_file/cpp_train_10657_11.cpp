#include <bits/stdc++.h>
using namespace std;
int x[5010], y[5010], w[5010], n, m;
double a[110][110], f[110];
double t;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x[i], &y[i], &w[i]);
    if ((x[i] != 1) && (x[i] != n)) {
      a[x[i]][y[i]]--;
      a[x[i]][x[i]]++;
    }
    if ((y[i] != 1) && (y[i] != n)) {
      a[y[i]][x[i]]--;
      a[y[i]][y[i]]++;
    }
  }
  a[1][1] = a[n][n] = a[n][n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    int j = i;
    while ((!a[j][i]) && (j <= n)) j++;
    if (j > n) continue;
    if (i != j) {
      for (int k = i; k <= n + 1; k++) swap(a[i][k], a[j][k]);
    }
    for (int j = i + 1; j <= n; j++) {
      t = a[j][j] / a[i][i];
      for (int k = i; k <= n + 1; k++) {
        a[j][k] -= t * a[i][k];
      }
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = i + 1; j <= n; j++) {
      a[i][n + 1] -= f[j] * a[i][j];
    }
    if (a[i][i] != 0) f[i] = a[i][n + 1] / a[i][i];
  }
  double Min = 1e16;
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    t = f[y[i]] - f[x[i]];
    Min = min(Min, abs(w[i] / t));
  }
  if (Min >= 10000000000000000.0) Min = 0;
  for (int i = 1; i <= m; i++) {
    if (x[i] == 1) {
      ans += Min * f[y[i]];
    } else if (y[i] == 1) {
      ans += Min * f[x[i]];
    }
  }
  printf("%.7lf\n", ans);
  for (int i = 1; i <= m; i++) {
    printf("%.7lf\n", (f[y[i]] - f[x[i]]) * Min);
  }
  return 0;
}
