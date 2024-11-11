#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 10;
const int mod = 1000000007;
const int phi = 1000000006;
long long n, f1, f2, f3, c;
struct Matix {
  long long m[10][10];
};
Matix muti(Matix a, Matix b, int n) {
  Matix c;
  memset(c.m, 0, sizeof(c.m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        c.m[i][j] = (c.m[i][j] + (a.m[i][k] * b.m[k][j]) % phi) % phi;
  return c;
}
Matix ksm(Matix a, long long b, long long n) {
  Matix res;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < n; ++j) res.m[i][j] = (i == j) ? 1 : 0;
  while (b) {
    if (b & 1) res = muti(res, a, n);
    a = muti(a, a, n);
    b >>= 1;
  }
  return res;
}
long long ksm_num(long long a, long long b, long long mod) {
  a %= mod;
  long long res = 1 % mod;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%lld %lld %lld %lld %lld", &n, &f1, &f2, &f3, &c);
  Matix f, fa, k, ka;
  long long F1, F2, F3, F4;
  f.m[0][0] = 1, f.m[0][1] = 2, f.m[0][2] = 4, f.m[1][0] = 1, f.m[1][1] = 2,
  f.m[1][2] = 3, f.m[2][0] = 1, f.m[2][1] = 1, f.m[2][2] = 2;
  fa.m[0][0] = 1, fa.m[0][1] = 1, fa.m[0][2] = 1, fa.m[1][0] = 1,
  fa.m[1][1] = 0, fa.m[1][2] = 0, fa.m[2][0] = 0, fa.m[2][1] = 1,
  fa.m[2][2] = 0;
  k.m[0][0] = 14, k.m[0][1] = 6, k.m[0][2] = 2, k.m[0][3] = 4, k.m[0][4] = 5,
  k.m[0][5] = -1;
  ka.m[0][0] = 1, ka.m[0][1] = 1, ka.m[0][2] = 0, ka.m[0][3] = 0,
  ka.m[0][4] = 0, ka.m[0][5] = 0, ka.m[1][0] = 1, ka.m[1][1] = 0,
  ka.m[1][2] = 1, ka.m[1][3] = 0, ka.m[1][4] = 0, ka.m[1][5] = 0,
  ka.m[2][0] = 1, ka.m[2][1] = 0, ka.m[2][2] = 0, ka.m[2][3] = 0,
  ka.m[2][4] = 0, ka.m[2][5] = 0, ka.m[3][0] = 1, ka.m[3][1] = 0,
  ka.m[3][2] = 0, ka.m[3][3] = 1, ka.m[3][4] = 0, ka.m[3][5] = 0,
  ka.m[4][0] = 1, ka.m[4][1] = 0, ka.m[4][2] = 0, ka.m[4][3] = 0,
  ka.m[4][4] = 1, ka.m[4][5] = 0, ka.m[5][0] = 1, ka.m[5][1] = 0,
  ka.m[5][2] = 0, ka.m[5][3] = -1, ka.m[5][4] = -1, ka.m[5][5] = 1;
  if (n >= 7) {
    n -= 6;
    f = muti(f, ksm(fa, n, 3), 3);
    k = muti(k, ksm(ka, n, 6), 6);
    F1 = ksm_num(f1, f.m[2][2], mod), F2 = ksm_num(f2, f.m[1][2], mod),
    F3 = ksm_num(f3, f.m[0][2], mod), F4 = ksm_num(c, k.m[0][0], mod);
  } else {
    n -= 4;
    F1 = ksm_num(f1, f.m[0][n], mod), F2 = ksm_num(f2, f.m[0][n], mod),
    F3 = ksm_num(f3, f.m[0][n], mod), F4 = ksm_num(c, k.m[0][2 - n], mod);
  }
  long long ans = (F1 % mod * F2 % mod * F3 % mod * F4 % mod) % mod;
  printf("%lld", ans);
  return 0;
}
