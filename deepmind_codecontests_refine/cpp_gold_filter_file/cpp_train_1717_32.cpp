#include <bits/stdc++.h>
using namespace std;
long long MOD;
struct Matrix {
  int n, m;
  long long a[10][10];
  void clear(int x = 0, int y = 0) {
    n = x;
    m = y;
    memset(a, 0, sizeof(a));
  }
  Matrix operator*(const Matrix &b) const {
    Matrix tmp;
    tmp.clear(n, b.m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < b.m; ++j)
        for (int k = 0; k < m; ++k) {
          tmp.a[i][j] = (tmp.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        }
    return tmp;
  }
  void show() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << a[i][j] << " ";
      cout << endl;
    }
  }
};
Matrix quickPow(Matrix mat, unsigned long long n) {
  Matrix res;
  res.clear(2, 2);
  res.a[0][0] = 1;
  res.a[0][1] = 0;
  res.a[1][0] = 0;
  res.a[1][1] = 1;
  while (n) {
    if (n & 1) res = res * mat;
    mat = mat * mat;
    n = n >> 1;
  }
  return res;
}
unsigned long long _pow(unsigned long long n) {
  if (n == 0) return 1;
  unsigned long long sum = 1;
  sum = _pow(n / 2);
  sum = sum * sum % MOD;
  if (n & 1) sum = sum * 2 % MOD;
  return sum;
}
int main() {
  unsigned long long n, k, l, m;
  cin >> n >> k >> l >> MOD;
  if (l < 64 && (1ULL << l) <= k) {
    printf("0\n");
    return 0;
  }
  Matrix fib, _begin;
  _begin.clear(2, 1);
  fib.clear(2, 2);
  _begin.a[0][0] = 3, _begin.a[1][0] = 2;
  fib.a[0][0] = fib.a[0][1] = fib.a[1][0] = 1;
  fib = quickPow(fib, n - 2) * _begin;
  unsigned long long no = fib.a[0][0];
  unsigned long long yes = (MOD + _pow(n) - no) % MOD;
  unsigned long long sum = 1;
  for (int i = 0; i < l; i++) {
    if (k & (1ULL << i))
      sum = sum * yes % MOD;
    else
      sum = sum * no % MOD;
  }
  cout << sum % MOD << endl;
  return 0;
}
