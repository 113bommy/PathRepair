#include <bits/stdc++.h>
using namespace std;
long long ans, n, k, l, p;
struct matrix {
  long long a[2][2];
  matrix() {}
  matrix(long long x, long long y, long long z, long long t) {
    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = t;
  }
} I(1, 0, 0, 1), P(0, 1, 1, 1);
matrix operator*(matrix a, matrix b) {
  matrix c(0, 0, 0, 0);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % p) % p;
  return c;
}
matrix pow(matrix a, long long b) {
  matrix ans = I;
  while (b) {
    if (b & 1) ans = ans * a;
    b >>= 1;
    a = a * a;
  }
  return ans;
}
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
int main() {
  cin >> n >> k >> l >> p;
  if (l != 64 && k >= (unsigned long long)(1ULL << l)) {
    cout << 0;
    return 0;
  }
  matrix w = pow(P, n);
  long long fib = (w.a[1][0] + w.a[1][1]) % p, ans = 1,
            ww = (ksm(2, n) - fib + p) % p;
  for (int i = 0; i < l; ++i) {
    if ((k & (1LL << i)) == 0)
      ans = ans * fib % p;
    else
      ans = ans * ww % p;
  }
  cout << ans % p;
  return 0;
}
