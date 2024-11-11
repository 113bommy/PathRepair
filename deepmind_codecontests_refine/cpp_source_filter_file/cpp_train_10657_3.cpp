#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 5005;
const double eps = 1e-6;
int n, m;
int a[M], b[M], c[M];
vector<int> g[N];
double A[N][N], x[N];
void gauss(int n, int m) {
  int i = 0, x = 0;
  for (; i < n && x < m; i++, x++) {
    int r = i;
    for (int j = i + 1; j < n; j++)
      if (fabs(A[j][x]) > fabs(A[r][x])) {
        r = j;
      }
    if (fabs(A[r][x]) < eps) {
    } else {
      if (r != i)
        for (int j = 0; j <= m; j++) swap(A[r][j], A[i][j]);
      for (int j = m; j >= x; j--) A[i][j] /= A[i][x];
      for (int j = 0; j < n; j++)
        if (i != j && fabs(A[j][x]) >= eps)
          for (int k = m; k >= x; k--) A[j][k] -= A[i][k] * A[j][x];
    }
  }
}
double ans[M];
int fa[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  memset(A, 0, sizeof(A));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) fa[i] = i;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    a[i]--;
    b[i]--;
    int pu = find(a[i]);
    int pv = find(b[i]);
    if (pu != pv) fa[pu] = pv;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  if (find(0) != find(n - 1)) {
    for (int i = 0; i <= m; i++) printf("%.12f\n", 0.0);
    return 0;
  }
  A[0][0] = A[n - 1][n - 1] = 1.0;
  A[0][n] = 1.0;
  A[n - 1][n] = 2.0;
  for (int i = 1; i < n - 1; i++) {
    int sz = g[i].size();
    for (int j = 0; j < sz; j++) {
      int v = g[i][j];
      A[i][v] -= 1.0;
    }
    A[i][i] += sz;
  }
  gauss(n, n);
  for (int i = 0; i < n; i++) x[i] = A[i][n];
  double Min = 1e50;
  for (int i = 0; i < m; i++) Min = min(Min, c[i] / fabs(x[a[i]] - x[b[i]]));
  double tot = 0;
  for (int i = 0; i < m; i++) {
    ans[i] = Min * (x[b[i]] - x[a[i]]);
    if (!a[i] || !b[i]) tot += fabs(ans[i]);
  }
  printf("%.12f\n", tot);
  for (int i = 0; i < m; i++) printf("%.12f\n", ans[i]);
  return 0;
}
