#include <bits/stdc++.h>
using namespace std;
int P;
struct Matrix {
  int a[4];
  Matrix() {
    a[0] = a[1] = a[2] = 1;
    a[3] = 0;
  }
  Matrix operator*(const Matrix &t) const {
    Matrix res;
    res.a[0] = (1LL * a[0] * t.a[0] + 1LL * a[1] * t.a[2]) % P;
    res.a[1] = (1LL * a[0] * t.a[1] + 1LL * a[1] * t.a[3]) % P;
    res.a[2] = (1LL * a[2] * t.a[0] + 1LL * a[3] * t.a[2]) % P;
    res.a[3] = (1LL * a[2] * t.a[1] + 1LL * a[3] * t.a[3]) % P;
    return res;
  }
  Matrix operator^(long long x) const {
    Matrix res, a;
    x--;
    while (x) {
      if (x & 1) res = res * a;
      a = a * a;
      x >>= 1;
    }
    return res;
  }
};
int POW(int x, long long k) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1LL * res * x % P;
    x = 1LL * x * x % P;
    k >>= 1;
  }
  return res;
}
int main() {
  long long n, k;
  int l, m;
  cin >> n >> k >> l >> m;
  if (l != 64 && k >= (unsigned long long)(1ULL << l)) {
    printf("0\n");
    return 0;
  }
  P = m;
  Matrix fib;
  fib = fib ^ (n + 1);
  int x = fib.a[0];
  int y = ((POW(2, n) - x) % P + P) % P;
  int sum = 1;
  for (int i = 0; i < l; ++i) {
    if (k & (1LL << i))
      sum = 1LL * sum * y % P;
    else
      sum = 1LL * sum * x % P;
  }
  cout << sum << endl;
  return 0;
}
