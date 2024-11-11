#include <bits/stdc++.h>
const int MAX = 1e5 + 11;
using namespace std;
const int MOD = (const int)(1e9 + 7);
const int INF = (const int)1e9;
struct Matrix {
  int A_[111][111];
  int N_, M_;
  Matrix(int N, int M) : N_(N), M_(M) { memset(A_, 0, sizeof(A_)); }
};
Matrix operator*(const Matrix &a, const Matrix &b) {
  assert(a.M_ == b.N_);
  Matrix c(a.N_, b.N_);
  for (int i = 0; i < a.N_; ++i) {
    for (int j = 0; j < b.N_; ++j) {
      for (int k = 0; k < a.M_; ++k) {
        c.A_[i][j] =
            (int)((1LL * c.A_[i][j] + 1LL * a.A_[i][k] * b.A_[k][j]) % MOD);
      }
    }
  }
  return c;
}
Matrix pow(const Matrix &a, int x) {
  assert(a.N_ == a.M_);
  Matrix res(a.N_, a.N_);
  for (int i = 0; i < a.N_; ++i) {
    res.A_[i][i] = 1;
  }
  Matrix q = a;
  while (x > 0) {
    if (x & 1) {
      res = res * q;
    }
    q = q * q;
    x >>= 1;
  }
  return res;
}
int N, b, k, x, A[MAX];
static void solve(int test) {
  scanf("%d %d %d %d", &N, &b, &k, &x);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  Matrix w(x, x), e(x, x);
  for (int i = 0; i < x; ++i) {
    w.A_[i][(i * 10) % x] = 1;
  }
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < N; ++j) {
      e.A_[i][(i + A[j]) % x]++;
    }
  }
  auto m = pow(w * e, b);
  printf("%d", m.A_[0][k]);
}
int main() {
  ios_base::sync_with_stdio(0);
  solve(0);
  return 0;
}
