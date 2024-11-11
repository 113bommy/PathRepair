#include <bits/stdc++.h>
using namespace std;
long long mod;
struct Matrix {
  int dim;
  long long val[65][65];
  Matrix(int dim) {
    this->dim = dim;
    memset(val, 0, sizeof(val));
  }
  void identity() {
    memset(val, 0, sizeof(val));
    for (int i = 0; i < (int)dim; i++) val[i][i] = 1;
  }
  Matrix operator*(const Matrix &A);
  void print();
};
void multiply(const Matrix *A, const Matrix &B, Matrix &ret) {
  int dim = B.dim;
  for (int i = 0; i < (int)dim; i++)
    for (int j = 0; j < (int)dim; j++) {
      long long sum = 0;
      for (int k = 0; k < (int)dim; k++)
        sum = (sum + (A->val[i][k] * B.val[k][j]) % mod) % mod;
      ret.val[i][j] = sum;
    }
}
Matrix Matrix::operator*(const Matrix &A) {
  Matrix ret(A.dim);
  multiply(this, A, ret);
  return ret;
}
void Matrix::print() {
  for (int i = 0; i < (int)dim; i++) {
    for (int j = 0; j < (int)dim; j++) {
      if (j) printf(" ");
      printf("%d", val[i][j]);
    }
    puts("");
  }
}
Matrix bigmod_mat(Matrix A, long long pow) {
  Matrix ret(A.dim);
  ret.identity();
  while (pow > 0) {
    if (pow & 1) ret = ret * A;
    A = A * A;
    pow >>= 1;
  }
  return ret;
}
long long bigmod(long long x, long long pow) {
  long long ret = 1;
  while (pow > 0) {
    if (pow & 1) ret = (ret * x) % mod;
    x = (x * x) % mod;
    pow >>= 1;
  }
  return ret;
}
int main() {
  long long N, K, L, ret = 1, pw, fib;
  scanf("%lld%lld", &N, &K);
  scanf("%lld%lld", &L, &mod);
  if (L != 64 && K >= (1uLL << L)) {
    puts("0");
    return 0;
  }
  pw = bigmod(2, N);
  Matrix A(2);
  A.val[0][0] = A.val[0][1] = A.val[1][0] = 1;
  A = bigmod_mat(A, N);
  fib = (A.val[0][0] + A.val[0][1]) % mod;
  for (int i = 0; i < (int)L; i++) {
    ret *= ((K & (1LL << i)) ? (pw - fib) : fib);
    ret %= mod;
  }
  ret %= mod;
  if (ret < 0) ret += mod;
  printf("%lld\n", ret);
}
