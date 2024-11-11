#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const double inf = 1e+10;
int x[505];
int n, max_dis, m;
double A[505][505];
long long d[505][505];
int u, v, val;
int bn;
int dcmp(double x) {
  if (x < -eps)
    return -1;
  else if (x > eps)
    return 1;
  else
    return 0;
}
int basis[505], out[505];
void pivot(int a, int b) {
  for (int i = 0; i <= m; i++) {
    if (i != a && dcmp(A[i][b])) {
      for (int j = 0; j <= n; j++) {
        if (j != b) {
          A[i][j] -= A[a][j] * A[i][b] / A[a][b];
        }
      }
    }
  }
  for (int j = 0; j <= n; j++) {
    if (j != b) A[a][j] /= A[a][b];
  }
  for (int i = 0; i <= m; i++) {
    if (i != a) A[i][b] /= -A[a][b];
  }
  A[a][b] = 1 / A[a][b];
  swap(basis[a], out[b]);
}
double simplex() {
  for (int i = 1; i <= n; i++) {
    A[0][i] = -A[0][i];
  }
  for (int i = 0; i <= m; i++) {
    basis[i] = -i;
  }
  for (int i = 0; i <= n; i++) {
    out[i] = i;
  }
  while (true) {
    int ii = 1, jj = 1;
    for (int i = 1; i <= m; i++) {
      if (make_pair(A[i][0], basis[i]) < make_pair(A[ii][0], basis[ii])) ii = i;
    }
    if (A[ii][0] >= 0) break;
    for (int j = 1; j <= n; j++) {
      if (A[ii][j] < A[ii][jj]) jj = j;
    }
    if (A[ii][jj] >= 0) return -inf;
    pivot(ii, jj);
  }
  while (true) {
    int ii = 1, jj = 1;
    for (int j = 1; j <= n; j++) {
      if (make_pair(A[0][j], out[j]) < make_pair(A[0][jj], out[jj])) jj = j;
    }
    if (A[0][jj] >= 0) break;
    for (int i = 1; i <= m; i++) {
      if (A[i][jj] > 0 &&
          (A[ii][jj] <= 0 || make_pair(A[i][n] / A[i][jj], basis[i]) <
                                 make_pair(A[ii][n] / A[ii][jj], basis[ii])))
        ii = i;
    }
    if (A[ii][jj] <= 0) return +inf;
    pivot(ii, jj);
  }
  return A[0][0];
}
int main() {
  cin >> n >> max_dis;
  m = n + 1;
  for (int i = 1; i <= n; i++) {
    d[i][i] = 0;
    for (int j = i + 1; j <= n; j++) {
      d[i][j] = d[j][i] = 1e+9 + 5;
    }
  }
  for (int i = 1; i <= n; i++) {
    int tmp;
    scanf("%d", &tmp);
    A[0][i] = tmp - 1;
    bn += tmp;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &u, &v, &val);
    d[u][v] = d[v][u] = val;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  A[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      A[i][j] = (d[i][j] - max_dis < eps);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      A[i][j] = -A[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    A[i][0] = -1;
  }
  for (int i = 1; i <= n; i++) {
    A[n + 1][i] = 1;
  }
  A[n + 1][0] = bn;
  double res = simplex();
  int ans;
  if (res == -inf) {
    ans = -1;
  } else {
    ans = -res + 0.5;
  }
  printf("%d\n", ans);
  return 0;
}
