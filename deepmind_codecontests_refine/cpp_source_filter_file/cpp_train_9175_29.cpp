#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const double eps = 1e-8;
double A[N][N];
void Gauss(int n, int m) {
  int i = 0, x = 0;
  for (; i < n && x < m; i++, x++) {
    int r = i;
    for (int j = i + 1; j < n; j++)
      if (fabs(A[j][x]) > fabs(A[r][x])) {
        r = j;
      }
    if (fabs(A[r][x]) < eps)
      --i;
    else {
      if (r != i)
        for (int j = 0; j < m + 1; j++) swap(A[r][j], A[i][j]);
      for (int j = m; j >= x; j--) A[i][j] /= A[i][x];
      for (int j = 0; j < n; j++)
        if (i != j && fabs(A[j][x]) >= eps)
          for (int k = m; k >= x; k--) A[j][k] -= A[i][k] * A[j][x];
    }
  }
}
int n, a, b, m;
int g[25][25], d[25];
double p[25][25];
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  a--;
  b--;
  int u, v;
  while (m--) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u][v] = g[v][u] = 1;
    d[u]++;
    d[v]++;
  }
  for (int i = 0; i < n; i++) scanf("%lf", &p[i][i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j && g[i][j]) p[i][j] = (1 - p[i][i]) / d[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i * n + j][i * n + j] -= 1;
      if (i == j) continue;
      for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++)
          A[k * n + l][i * n + j] += p[i][k] * p[j][l];
    }
  }
  A[a * n + b][n * n] -= 1.0;
  Gauss(n * n, n * n);
  for (int i = 0; i < n; i++) printf("%.10f ", A[i * n + i][n * n]);
  printf("\n");
  return 0;
}
