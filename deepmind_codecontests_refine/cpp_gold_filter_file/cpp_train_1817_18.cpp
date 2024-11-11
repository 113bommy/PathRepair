#include <bits/stdc++.h>
using namespace std;
long double a[505][505 + 105], b[105][105];
int n, m, k;
int wz[505];
bool bz[505];
long double f[105];
void gauss() {
  for (int i = 1; i <= n; i++) {
    int nwz = 0;
    for (int j = i; j <= n; j++)
      if (fabs(a[j][i]) > 1e-10) {
        nwz = j;
        break;
      }
    if (nwz == 0) break;
    swap(a[i], a[nwz]);
    long double tmp = a[i][i];
    for (int j = 1; j <= n + wz[0]; j++) a[i][j] /= tmp;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      long double tmp = a[j][i];
      if (fabs(tmp) < 1e-10) continue;
      for (int k = 1; k <= n + wz[0]; k++) a[j][k] -= a[i][k] * tmp;
    }
  }
  for (int i = 1; i <= wz[0]; i++) f[i] = fabs(a[1][i + n]);
  for (int i = 1; i <= n; i++) {
    if (bz[i] == 0) continue;
    for (int j = 1; j <= wz[0]; j++) b[wz[i]][j] = fabs(a[i][j + n]);
  }
}
void mult() {
  long double g[105];
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= wz[0]; i++)
    for (int j = 1; j <= wz[0]; j++) g[j] += f[i] * b[i][j];
  memcpy(f, g, sizeof(f));
}
void mul1() {
  long double ret[105][105];
  memset(ret, 0, sizeof(ret));
  for (int i = 1; i <= wz[0]; i++)
    for (int j = 1; j <= wz[0]; j++)
      for (int k = 1; k <= wz[0]; k++) ret[i][j] += b[i][k] * b[k][j];
  memcpy(b, ret, sizeof(b));
}
void mul(int x) {
  while (x) {
    if (x % 2 == 1) mult();
    mul1();
    x /= 2;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x) {
      bz[i] = 1;
      wz[i] = ++wz[0];
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][x]--;
    a[y][y]--;
    if (bz[y])
      a[x][wz[y] + n]++;
    else
      a[x][y]++;
    if (bz[x])
      a[y][wz[x] + n]++;
    else
      a[y][x]++;
  }
  gauss();
  k -= 2;
  mul(k);
  double outp = f[wz[0]];
  printf("%.15lf", outp);
  return 0;
}
