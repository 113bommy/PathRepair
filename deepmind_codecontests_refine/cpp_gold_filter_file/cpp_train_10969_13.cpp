#include <bits/stdc++.h>
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1);
using namespace std;
int d[N][N], rk[N][N], val[N], n;
void floyd() {
  int i, j, k;
  for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
}
int cmp(int x, int y) { return val[x] < val[y]; }
int u[N * N], v[N * N], w[N * N];
int main() {
  int m, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) d[i][j] = (i == j ? 0 : inf);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    d[u[i]][v[i]] = min(d[u[i]][v[i]], w[i]);
    d[v[i]][u[i]] = min(d[v[i]][u[i]], w[i]);
  }
  floyd();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      rk[i][j] = j;
      val[j] = d[i][j];
    }
    sort(rk[i] + 1, rk[i] + n + 1, cmp);
  }
  int ans = inf;
  for (i = 1; i <= n; i++) ans = min(ans, d[i][rk[i][n]] * 2);
  for (i = 1; i <= m; i++) {
    for (k = n, j = n - 1; j >= 1; j--) {
      if (d[v[i]][rk[u[i]][j]] > d[v[i]][rk[u[i]][k]]) {
        ans = min(ans, d[u[i]][rk[u[i]][j]] + d[v[i]][rk[u[i]][k]] + w[i]);
        k = j;
      }
    }
  }
  printf("%.9lf\n", ans * 1.0 / 2);
  return 0;
}
