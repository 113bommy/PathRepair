#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 1e9 + 6;
struct Matrix {
  long long a[2][2];
} s;
Matrix Mul(Matrix a, Matrix b) {
  Matrix c;
  memset(c.a, 0, sizeof(c.a));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
      }
    }
  }
  return c;
}
Matrix Quick(Matrix a, long long b) {
  Matrix c;
  c.a[0][0] = c.a[1][1] = 1;
  c.a[0][1] = c.a[1][0] = 0;
  while (b) {
    if (b & 1) c = Mul(c, a);
    b >>= 1, a = Mul(a, a);
  }
  return c;
}
int k;
long long t;
long long quick(long long a, long long b) {
  long long ans = 1ll;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1, a = a * a % mod;
  }
  return ans;
}
int main() {
  scanf("%d", &k);
  s.a[0][0] = 1, s.a[1][0] = 1, s.a[0][1] = 2, s.a[1][1] = 0;
  t = 2ll;
  long long ans = 1ll;
  for (int i = 1; i <= k; i++) {
    long long x;
    scanf("%lld", &x);
    ans = ans * x % mod2;
    t = quick(t, x);
  }
  s = Quick(s, ans);
  printf("%lld/%lld\n", s.a[1][1] * quick(2ll, mod - 2) % mod,
         t * quick(2ll, mod - 2) % mod);
  return 0;
}
