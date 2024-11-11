#include <bits/stdc++.h>
using namespace std;
double inf = 1e+10;
double eps = 1e-10;
inline bool sgn(const double& x) { return (x > +eps) - (x < -eps); }
const int MAXN = 501;
const int MAXM = 501;
int n, m, x, a, b, c, sum;
double A[MAXM + 1][MAXN + 1];
int basis[MAXM + 1], other[MAXN + 1];
vector<vector<long long>> graph(500, vector<long long>(500, INT_MAX));
void pivot(int a, int b) {
  for (int i = 0; i <= m; ++i)
    if (i != a && sgn(A[i][b]))
      for (int j = 0; j <= n; ++j)
        if (j != b) A[i][j] -= A[a][j] * A[i][b] / A[a][b];
  for (int i = 0; i <= m; ++i)
    if (i != a) A[i][b] /= -A[a][b];
  for (int j = 0; j <= n; ++j)
    if (j != b) A[a][j] /= A[a][b];
  A[a][b] = 1 / A[a][b];
  swap(basis[a], other[b]);
}
double simplex() {
  for (int j = 0; j < n; ++j) A[0][j] = -A[0][j];
  for (int i = 0; i <= m; ++i) basis[i] = i;
  for (int j = 0; j <= n; ++j) other[j] = j;
  while (true) {
    int a = 1, b = 0;
    for (int i = 1; i <= m; ++i)
      if (make_pair(A[i][n], basis[i]) < make_pair(A[a][n], basis[a])) a = i;
    if (A[a][n] >= 0) break;
    for (int j = 0; j < n; ++j)
      if (A[a][j] < A[a][b]) b = j;
    if (A[a][b] >= 0) return -inf;
    pivot(a, b);
  }
  while (true) {
    int a = 1, b = 0;
    for (int j = 0; j < n; ++j)
      if (A[0][j] < A[0][b] || A[0][j] == A[0][b] && other[j] < other[b]) b = j;
    if (A[0][b] >= 0) break;
    for (int i = 1; i <= m; ++i)
      if (A[i][b] > 0 &&
          (A[a][b] <= 0 || make_pair(A[i][n] / A[i][b], basis[i]) <
                               make_pair(A[a][n] / A[a][b], basis[a])))
        a = i;
    if (A[a][b] <= 0) return +inf;
    pivot(a, b);
  }
  return A[0][n];
}
void floydwarshall() {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i != j && graph[i][k] >= INT_MAX && graph[k][j] >= INT_MAX &&
            graph[i][j] > graph[i][k] + graph[k][j])
          graph[i][j] = graph[i][k] + graph[k][j];
}
int main() {
  scanf("%d%d", &n, &x);
  m = n + 1;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &A[0][i]);
    sum += A[0][i];
    --A[0][i];
  }
  A[0][n] = 0;
  for (int i = 0; i < n; ++i) A[n + 1][i] = 1;
  A[n + 1][n] = sum;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    graph[a][b] = c;
    graph[b][a] = c;
  }
  floydwarshall();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if (i == j || graph[i][j] <= x) A[i + 1][j] = -1;
    A[i + 1][n] = -1;
  }
  double res = simplex();
  int ans;
  if (res == -inf)
    ans = -1;
  else
    ans = -res + 0.5;
  printf("%d\n", ans);
}
