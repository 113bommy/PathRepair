#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
struct mat {
  long long a, b, c, d;
};
mat operator*(const mat &x, const mat &y) {
  mat z;
  z.a = ((x.a * y.a % mod) + (x.b * y.c % mod)) % mod;
  z.b = ((x.a * y.b % mod) + (x.b * y.d % mod)) % mod;
  z.c = ((x.c * y.a % mod) + (x.d * y.c % mod)) % mod;
  z.d = ((x.d * y.d % mod) + (x.c * y.b % mod)) % mod;
  return z;
}
mat power(mat x, long long n) {
  mat y = x;
  --n;
  while (n > 0) {
    if (n & 1) {
      y = y * x;
    }
    n >>= 1;
    x = x * x;
  }
  return y;
}
int main(void) {
  mat m = (mat){mod - 1, 1, 0, 2};
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    long long n;
    scanf("%I64d", &n);
    m = power(m, n);
  }
  long long a = (m.a + m.b) % mod, b = m.d;
  a = a * ((mod + 1) / 2) % mod;
  b = b * ((mod + 1) / 2) % mod;
  printf("%I64d/%I64d\n", a, b);
  return 0;
}
