#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
struct Matrix {
  int rw, cl;
  int s[110][110];
};
Matrix Mul(Matrix A, Matrix B) {
  Matrix R;
  R.rw = A.rw;
  R.cl = B.cl;
  for (int i = 0; i < R.rw; i++)
    for (int j = 0; j < R.cl; j++) {
      R.s[i][j] = 0;
      for (int k = 0; k < A.cl; k++)
        R.s[i][j] = (R.s[i][j] + (long long)1 * A.s[i][k] * B.s[k][j]) % MOD;
    }
  return R;
}
Matrix Pow(Matrix A, long long k) {
  Matrix R = A;
  k--;
  while (k > 0) {
    if (k % 2 == 1) R = Mul(R, A);
    A = Mul(A, A);
    k /= 2;
  }
  return R;
}
int d[110];
int main() {
  int n, x, tmp, P = 101;
  scanf("%d%d", &n, &x);
  for (int i = 0; i <= P; i++) d[i] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    d[tmp]++;
  }
  Matrix A;
  A.rw = P + 1;
  A.cl = P + 1;
  for (int i = 0; i <= P; i++)
    for (int j = 0; j <= P; j++) A.s[i][j] = 0;
  for (int i = 1; i < P; i++) A.s[i - 1][i] = 1;
  A.s[P][P] = A.s[0][P] = 1;
  for (int i = 1; i <= P; i++) A.s[i - 1][0] = d[i];
  A = Pow(A, x + 1);
  cout << A.s[0][P];
}
