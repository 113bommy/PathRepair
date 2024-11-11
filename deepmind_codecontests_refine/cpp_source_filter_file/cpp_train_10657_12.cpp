#include <bits/stdc++.h>
using namespace std;
typedef int P[5005];
const double eps = 1e-8;
int n, m;
P u, v, w;
double Ans, mul, mtx[105][105];
inline void gs(int n) {
  for (int i = 1; i < n; ++i) {
    for (int k = i; k < n; ++k)
      if (!(fabs(mtx[k][i]) < eps)) {
        for (int j = 1; j <= n; ++j) swap(mtx[i][j], mtx[k][j]);
        break;
      }
    if ((fabs(mtx[i][i]) < eps)) continue;
    for (int j = n + 1; j >= i; --j) mtx[i][j] /= mtx[i][i];
    for (int j = 1; j < n; ++j)
      if (i ^ j && !(fabs(mtx[j][i]) < eps)) {
        double _ = -mtx[j][i];
        for (int k = 1; k <= n; ++k) mtx[j][k] += _ * mtx[i][k];
      }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", u + i, v + i, w + i);
    if (v[i] ^ 1 && v[i] ^ n) --mtx[v[i]][v[i]], ++mtx[v[i]][u[i]];
    if (u[i] ^ 1 && u[i] ^ n) ++mtx[u[i]][v[i]], --mtx[u[i]][u[i]];
  }
  mtx[n][n] = mtx[n][n + 1] = mtx[1][1] = 1;
  gs(n + 1);
  mul = 123456789101112131415.;
  for (int i = 1; i <= m; ++i) {
    double p = mtx[v[i]][n + 1] - mtx[u[i]][n + 1];
    mul = min(mul, fabs(w[i] / p));
  }
  if ((fabs(mul) < eps) || mul > 10000000000000000000.) mul = 0;
  for (int i = 1; i <= m; ++i)
    if (v[i] == 1 || u[i] == 1) Ans += mtx[u[i] * v[i]][n + 1] * mul;
  printf("%.7lf\n", Ans);
  for (int i = 1; i <= m; ++i)
    printf("%.7lf\n", (mtx[v[i]][n + 1] - mtx[u[i]][n + 1]) * mul);
}
