#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int BUF = 85;
class Matrix {
 public:
  int sz, mat[BUF][BUF];
  Matrix() {}
  Matrix(int _sz, int _mat[BUF][BUF]) {
    sz = _sz;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) mat[i][j] = _mat[i][j];
  }
  Matrix operator*(const Matrix &opp) {
    int t[BUF][BUF] = {};
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j)
        for (int k = 0; k < sz; ++k)
          t[i][j] = (t[i][j] + 1LL * mat[i][k] * opp.mat[k][j]) % MOD;
    return Matrix(sz, t);
  }
};
int nCk[BUF][BUF];
long long N;
int K;
void makeTable() {
  memset(nCk, 0, sizeof(nCk));
  nCk[0][0] = 1;
  for (int n = 1; n < BUF; ++n)
    for (int k = 0; k <= n; ++k)
      nCk[n][k] = (nCk[n - 1][k] + (k == 0 ? 0 : nCk[n - 1][k - 1])) % MOD;
}
void read() { cin >> N >> K; }
int mul(int a, int b) { return 1LL * a * b % MOD; }
int mypow(int p, long long n) {
  if (n == 0) return 1;
  int t = mypow(p, n / 2);
  return n & 1 ? mul(mul(t, t), p) : mul(t, t);
}
Matrix matPow(const Matrix &p, long long n) {
  if (n == 0) {
    static int t[BUF][BUF];
    memset(t, 0, sizeof(t));
    for (int i = 0; i < K * 2 + 3; ++i) t[i][i] = 1;
    return Matrix(K * 2 + 3, t);
  }
  Matrix t = matPow(p, n / 2);
  return n & 1 ? t * t * p : t * t;
}
void work() {
  int mat[BUF][BUF] = {};
  for (int k = 0; k <= K; ++k) {
    for (int j = 0; j <= k; ++j) {
      mat[k][k - j] = mul(nCk[k][j], mypow(1, j));
      mat[k][K + 1 + k - j] = mul(nCk[k][j], mypow(2, j));
    }
    mat[K + 1 + k][k] = 1;
  }
  mat[K * 2 + 2][K] = mat[K * 2 + 2][K * 2 + 2] = 1;
  Matrix ret = matPow(Matrix(K * 2 + 3, mat), N - 1);
  int ans = 0;
  for (int i = 0; i <= K; ++i) {
    ans = (ans + 1LL * ret.mat[K * 2 + 2][i] * 2 * mypow(2, i)) % MOD;
    ans = (ans + 1LL * ret.mat[K * 2 + 2][K + 1 + i] * 1 * mypow(1, i)) % MOD;
  }
  cout << ans + 1 << endl;
}
int main() {
  makeTable();
  read();
  work();
  return 0;
}
