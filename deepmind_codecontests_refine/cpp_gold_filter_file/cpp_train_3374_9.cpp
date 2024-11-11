#include <bits/stdc++.h>
using namespace std;
const int maxL = 45;
const long long inf = 1e18;
int n, m;
int a[22], b[22];
int L;
struct Matrix {
  long long x[maxL][maxL];
} I, INF, ansmat, A;
Matrix operator*(const Matrix a, const Matrix b) {
  Matrix ret = INF;
  for (int i = 1; i <= L; i++)
    for (int j = 1; j <= L; j++)
      for (int k = 1; k <= L; k++)
        ret.x[i][j] = min(ret.x[i][j], a.x[i][k] + b.x[k][j]);
  return ret;
}
Matrix operator^(const Matrix a, const int p) {
  Matrix ret = I, x = a;
  int o = p;
  while (o) {
    if (o & 1) ret = ret * x;
    x = x * x;
    o >>= 1;
  }
  return ret;
}
void MatrixInit() {
  for (int i = 1; i <= L; i++)
    for (int j = 1; j <= L; j++) I.x[i][j] = INF.x[i][j] = inf;
  for (int i = 1; i <= L; i++) I.x[i][i] = 0;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  L = 2 * n + 1;
  MatrixInit();
  ansmat = INF;
  A = I;
  ansmat.x[1][1] = 0;
  for (int i = 1; i <= n; i++) {
    Matrix temp = INF;
    for (int j = 1; j <= L; j++) {
      temp.x[j - 1][j] = a[i];
      temp.x[j + 1][j] = b[i];
    }
    A = A * temp;
  }
  ansmat = ansmat * (A ^ m);
  printf("%lld\n", ansmat.x[1][1]);
  return 0;
}
