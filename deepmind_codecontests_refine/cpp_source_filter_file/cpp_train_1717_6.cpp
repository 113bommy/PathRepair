#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  long long mat[2][2];
  Matrix() { memset(mat, 0, sizeof(mat)); }
  Matrix operator*(const Matrix &o) const {
    Matrix ret;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) ret.mat[i][j] += mat[i][k] * o.mat[k][j];
    return ret;
  }
  Matrix operator%(long long m) const {
    Matrix ret;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) ret.mat[i][j] = mat[i][j] % m;
    return ret;
  }
};
Matrix powmod(Matrix a, long long e, long long m) {
  Matrix ret;
  ret.mat[0][0] = ret.mat[1][1] = 1;
  for (; e; e >>= 1, a = a * a % m)
    if (e & 1) ret = ret * a % m;
  return ret;
}
long long powmod(long long a, long long e, long long m) {
  long long ret = 1;
  for (; e; e >>= 1, a = a * a % m)
    if (e & 1) ret = ret * a % m;
  return ret;
}
int main() {
  long long n, k, l, m;
  cin >> n >> k >> l >> m;
  if (l < 64 && k >> l > 0) {
    cout << 0 << endl;
    return 0;
  }
  Matrix M;
  M.mat[0][0] = M.mat[0][1] = M.mat[1][0] = 1;
  M = powmod(M, n, m);
  long long fib = (M.mat[0][0] + M.mat[0][1]) % m;
  long long p2 = powmod(2LL, n, m) - fib;
  if (p2 < 0) p2 += m;
  long long ans = 1;
  for (int i = 0; i < l; i++) {
    if ((k >> i) & 1)
      ans = ans * p2 % m;
    else
      ans = ans * fib % m;
  }
  cout << ans << endl;
}
