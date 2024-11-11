#include <bits/stdc++.h>
using namespace std;
const int NR = 505;
const int MR = 105;
const int ED = 1e5 + 10;
const double eps = 1e-12;
int n, m, K;
double a[NR][NR], f[NR][NR], p[NR][NR];
int d[NR], col[NR];
int to[ED << 1], nxt[ED << 1];
int head[NR];
int tt = 1;
void add(int x, int y) {
  to[tt] = y;
  nxt[tt] = head[x];
  head[x] = tt++;
}
int tot;
int id[NR], rk[NR];
struct Matrix {
  double a[MR][MR];
  void Init() {
    memset(a, 0, sizeof(a));
    return;
  }
} F, G;
Matrix operator*(Matrix a, Matrix b) {
  Matrix c;
  c.Init();
  for (int i = 1; i <= tot; i++)
    for (int j = 1; j <= tot; j++)
      for (int k = 1; k <= tot; k++) c.a[i][j] += a.a[i][k] * b.a[k][j];
  return c;
}
Matrix ksm(Matrix a, int b) {
  Matrix ans = a;
  b--;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a, b >>= 1;
  }
  return ans;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read(), m = read(), K = read();
  for (int i = 1; i <= n; i++) col[i] = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    d[x]++, d[y]++;
    add(x, y), add(y, x);
  }
  for (int x = 1; x <= n; x++) {
    f[x][x] = a[x][x] = 1;
    if (col[x]) continue;
    for (int i = head[x]; i; i = nxt[i]) a[to[i]][x] -= 1. / d[x];
  }
  for (int i = 1; i <= n; i++) {
    int pos = -1;
    for (int j = i; j <= n; j++)
      if (a[j][i]) {
        pos = j;
        break;
      }
    for (int j = 1; j <= n; j++)
      swap(a[i][j], a[pos][j]), swap(f[i][j], f[pos][j]);
    for (int j = 1; j <= n; j++) {
      if (i == j || fabs(a[j][i]) < eps) continue;
      double res = a[j][i] / a[i][i];
      for (int k = 1; k <= n; k++)
        a[j][k] -= a[i][k] * res, f[j][k] -= f[i][k] * res;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) p[i][j] = f[j][i] / a[j][j];
  for (int i = 1; i <= n; i++)
    if (col[i]) id[++tot] = i, rk[i] = tot;
  for (int i = 1; i <= tot; i++)
    for (int j = 1; j <= tot; j++) {
      double res = 0;
      for (int t = head[id[i]]; t; t = nxt[t]) {
        int k = to[t];
        if (col[k] && k == id[j]) res += 1. / d[id[i]];
        if (!col[k]) res += 1. / d[id[i]] * p[k][id[j]];
      }
      p[id[i]][id[j]] = res;
    }
  if (K == 2) {
    printf("%.10lf\n", p[1][n]);
    return 0;
  }
  for (int i = 1; i <= tot; i++)
    for (int j = 1; j <= tot; j++) F.a[i][j] = p[id[i]][id[j]];
  G = ksm(F, K - 2);
  double ans = 0;
  for (int i = 1; i <= n; i++)
    if (col[i]) ans += p[1][i] * G.a[rk[i]][tot];
  printf("%.10lf\n", ans);
  return 0;
}
