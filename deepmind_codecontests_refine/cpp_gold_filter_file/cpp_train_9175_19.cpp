#include <bits/stdc++.h>
using namespace std;
const int maxN = 30, maxRow = maxN * maxN;
int n, m, a, b, d[maxN], g[maxN][maxN];
double A[maxRow][maxRow], p[maxN][maxN];
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  --a, --b;
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    ++d[x], ++d[y], g[x][y] = g[y][x] = 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &p[i][i]);
    for (int j = 0; j < n; ++j)
      if (g[i][j]) p[i][j] = (1.0 - p[i][i]) / d[i];
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int now = i * n + j;
      A[now][now] = -1.0;
      for (int x = 0; x < n; ++x)
        for (int y = 0; y < n; ++y)
          if (x != y) {
            int that = x * n + y;
            A[now][that] += p[x][i] * p[y][j];
          }
    }
  int N = n * n;
  A[a * n + b][N] = -1.0;
  for (int i = 0; i < N; ++i) {
    int r = i;
    for (int j = i + 1; j < N; ++j)
      if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
    if (r != i)
      for (int j = 0; j < N + 1; ++j) swap(A[i][j], A[r][j]);
    for (int k = i + 1; k < N; ++k) {
      double f = A[k][i] / A[i][i];
      for (int j = i; j <= N; ++j) A[k][j] -= A[i][j] * f;
    }
  }
  for (int i = N - 1; i >= 0; --i) {
    for (int j = i + 1; j < N; ++j) A[i][N] -= A[j][N] * A[i][j];
    A[i][N] /= A[i][i];
  }
  for (int i = 0; i < n; ++i) printf("%.7lf\n", A[i * n + i][N]);
  return 0;
}
