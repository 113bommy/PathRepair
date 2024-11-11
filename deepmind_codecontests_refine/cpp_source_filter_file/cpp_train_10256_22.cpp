#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const double finf = 100000000000.0;
const int N = 100000 + 10;
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
struct LPSolver {
  int n, m;
  double a[3 + 1][100000 + 5 + 1], x[100000 + 5];
  int basis[3 + 1], out[100000 + 5 + 1];
  void init(int v, int e) {
    n = v, m = e;
    for (int i = 0; i <= m; i++) fill(a[i], a[i] + n + 1, 0);
  }
  void pivot(int p, int q) {
    for (int i = 0; i <= m; i++)
      if (i != p && dcmp(a[i][q]))
        for (int j = 0; j <= n; j++)
          if (j != q) a[i][j] -= a[p][j] * a[i][q] / a[p][q];
    for (int j = 0; j <= n; j++)
      if (j != q) a[p][j] /= a[p][q];
    for (int i = 0; i <= m; i++)
      if (i != p) a[i][q] /= -a[p][q];
    a[p][q] = 1 / a[p][q];
    swap(basis[p], out[q]);
  }
  double simplex() {
    for (int j = 0; j <= n - 1; j++) a[0][j] = -a[0][j];
    for (int i = 0; i <= m; i++) basis[i] = -i;
    for (int j = 0; j <= n; j++) out[j] = j;
    while (1) {
      int p = 1, q = 0;
      for (int i = 1; i <= m; i++)
        if (make_pair(a[i][n], basis[i]) < make_pair(a[p][n], basis[p])) p = i;
      if (a[p][n] >= 0) break;
      for (int j = 0; j <= n - 1; j++)
        if (a[p][j] < a[p][q]) q = j;
      if (a[p][q] >= 0) return -finf;
      pivot(p, q);
    }
    while (1) {
      int p = 1, q = 0;
      for (int j = 0; j <= n - 1; j++)
        if (make_pair(a[0][j], out[j]) < make_pair(a[0][q], out[q])) q = j;
      if (a[0][q] >= -eps) break;
      for (int i = 1; i <= m; i++)
        if (a[i][q] > 0)
          if (a[p][q] <= 0 || make_pair(a[i][n] / a[i][q], basis[i]) <
                                  make_pair(a[p][n] / a[p][q], basis[p]))
            p = i;
      if (a[p][q] <= 0) return +finf;
      pivot(p, q);
    }
    for (int j = 0; j <= n - 1; j++) x[j] = 0;
    for (int i = 1; i <= m; i++)
      if (basis[i] >= 0) x[basis[i]] = a[i][n];
    return a[0][n];
  }
} sol;
int n, p, q;
int a[100000 + 5], b[100000 + 5];
int main() {
  scanf("%d %d %d", &n, &p, &q);
  for (int i = 1; i <= n; i++) scanf("%d %d", &a[i], &b[i]);
  sol.init(n, 2);
  int l = 1;
  for (int i = 1; i <= n; i++) sol.a[l][i - 1] = -a[i];
  sol.a[l][sol.n] = -p;
  l++;
  for (int i = 1; i <= n; i++) sol.a[l][i - 1] = -b[i];
  sol.a[l][sol.n] = -q;
  for (int i = 1; i <= n; i++) sol.a[0][i - 1] = -1;
  double tmp = sol.simplex();
  printf("%.10lf\n", tmp + eps);
  return 0;
}
