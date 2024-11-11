#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
const int MAXC = 16;
const int MOD = 1e9 + 7;
int n, dim;
int c[MAXN], dp[MAXN][MAXC];
int last_dim;
long long last_w;
long long k;
long long a[MAXN], b[MAXN];
int add(int a, int b) {
  a += b;
  while (a < 0) a += MOD;
  return a % MOD;
}
int mul(int a, int b) { return (long long)a * b % MOD; }
struct Matrix {
  int mat[MAXC][MAXC];
  Matrix() { memset(mat, 0, sizeof mat); }
  void trace() {
    fprintf(stderr, "---\n");
    for (int i = 0; i < dim; ++i) {
      for (int j = 0; j < dim; ++j) {
        fprintf(stderr, "%d ", mat[i][j]);
      }
      fprintf(stderr, "\n");
    }
    fprintf(stderr, "---\n");
  }
} B, X, sol;
Matrix operator*(const Matrix &A, const Matrix &B) {
  Matrix ret;
  for (int i = 0; i < dim; ++i)
    for (int j = 0; j < dim; ++j)
      for (int k = 0; k < dim; ++k)
        ret.mat[i][j] = add(ret.mat[i][j], mul(A.mat[i][k], B.mat[k][j]));
  return ret;
}
inline void init(int r) {
  memset(B.mat, 0, sizeof B.mat);
  memset(X.mat, 0, sizeof X.mat);
  memset(sol.mat, 0, sizeof sol.mat);
  for (int i = 0; i < dim; ++i) B.mat[0][i] = dp[r][i];
  for (int i = 0; i < dim; ++i) sol.mat[i][i] = 1;
  for (int i = 0; i < dim; ++i) {
    X.mat[i][i] = 1;
    if (i - 1 >= 0) X.mat[i - 1][i] = 1;
    if (i + 1 < dim) X.mat[i + 1][i] = 1;
  }
}
void find_ways(int i, int _dim, long long w) {
  dim = _dim;
  init(i);
  while (w > 0) {
    if (w & 1) sol = sol * X;
    X = X * X;
    w >>= 1;
  }
  sol = B * sol;
}
int main(void) {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld%d", &a[i + 1], &b[i + 1], &c[i + 1]);
    a[i + 1] = min(a[i + 1], k);
    b[i + 1] = min(b[i + 1], k);
  }
  c[0] = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    find_ways(i - 1, c[i] + 1, b[i] - a[i]);
    for (int j = 0; j <= c[i]; ++j) dp[i][j] = sol.mat[0][j];
  }
  printf("%d\n", dp[n][0]);
  return 0;
}
