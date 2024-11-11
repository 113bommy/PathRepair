#include <bits/stdc++.h>
using namespace std;
struct matrix {
  double num[510][510];
  int r, c;
};
matrix mult(const matrix &a, const matrix &b) {
  matrix res;
  memset(res.num, 0, sizeof(res.num));
  res.r = a.r;
  res.c = b.c;
  for (int i = 0; i < res.r; i++)
    for (int k = 0; k < a.c; k++)
      if (a.num[i][k] > 1e-10)
        for (int j = 0; j < res.c; j++)
          res.num[i][j] += a.num[i][k] * b.num[k][j];
  return res;
}
matrix A, T;
int deg[25];
vector<int> g[25];
double stay[25];
int ha[25][25];
int main() {
  int n, m, a, b;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    deg[u]++;
    g[v].push_back(u);
    deg[v]++;
  }
  for (int i = 1; i <= n; i++) scanf("%lf", &stay[i]);
  for (int i = 1; i <= n; i++) g[i].push_back(i);
  int idx = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) {
      ha[i][j] = idx++;
    }
  }
  A.r = idx;
  A.c = 1;
  A.num[ha[a][b]][0] = 1.0;
  if (a == b) A.num[ha[n + 1][a]][0] = 1.0;
  T.r = T.c = idx;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int u1 = 0; u1 < g[i].size(); u1++) {
        for (int v1 = 0; v1 < g[j].size(); v1++) {
          int u = g[i][u1];
          int v = g[j][v1];
          if (u == v) continue;
          double k1, k2;
          if (u == i)
            k1 = stay[i];
          else
            k1 = (1.0 - stay[u]) / (double)deg[u];
          if (v == j)
            k2 = stay[j];
          else
            k2 = (1.0 - stay[v]) / (double)deg[v];
          T.num[ha[i][j]][ha[u][v]] += k1 * k2;
        }
      }
    }
  }
  for (int j = 1; j <= n; j++) {
    T.num[ha[n + 1][j]][ha[n + 1][j]] = 1.0;
    for (int k = 0; k < idx; k++) {
      T.num[ha[n + 1][j]][k] += T.num[ha[j][j]][k];
    }
  }
  for (int i = 0; i < 16; i++) T = mult(T, T);
  A = mult(T, A);
  for (int j = 1; j <= n; j++) {
    printf("%.9f ", A.num[ha[n + 1][j]][0]);
  }
  cout << endl;
  return 0;
}
