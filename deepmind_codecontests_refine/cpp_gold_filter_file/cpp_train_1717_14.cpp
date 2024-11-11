#include <bits/stdc++.h>
using namespace std;
long long MOD;
struct mat {
  long long ma[2][2];
  mat() { ma[0][0] = ma[0][1] = ma[1][0] = ma[1][1] = 0; }
};
mat MatMul(mat m1, mat m2) {
  mat res;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        res.ma[i][k] = (res.ma[i][k] + m1.ma[i][j] * m2.ma[j][k]) % MOD;
  return res;
}
mat MatExp(mat base, long long exp) {
  if (exp == 1) return base;
  mat x = MatExp(base, exp >> 1);
  mat res = MatMul(x, x);
  if (exp & 1) res = MatMul(res, base);
  return res;
}
long long fibonacci(long long n) {
  mat x;
  x.ma[0][0] = x.ma[0][1] = x.ma[1][0] = 1LL;
  mat res = MatExp(x, n);
  return res.ma[0][0];
}
long long power(long long base, long long exp) {
  if (exp == 0) return 1LL;
  long long x = power(base, exp >> 1L);
  x = (x * x) % MOD;
  if (exp & 1) x = (x * base) % MOD;
  return x;
}
int main() {
  std::ios::sync_with_stdio(false);
  long long n, k, l, m;
  cin >> n >> k >> l >> m;
  MOD = m;
  if (m == 1 || (l < 63 && (1LL << l) <= k)) {
    cout << 0 << endl;
    return 0;
  }
  if (l == 0) {
    if (k == 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  long long pow = power(2, n);
  long long fib = fibonacci(n + 1);
  long long res = 1LL;
  for (int i = 0; i < l; ++i) {
    if ((k >> i) & 1)
      res = (res * (pow - fib)) % m;
    else
      res = (res * fib) % m;
  }
  if (res < 0) res += m;
  cout << res << endl;
  return 0;
}
