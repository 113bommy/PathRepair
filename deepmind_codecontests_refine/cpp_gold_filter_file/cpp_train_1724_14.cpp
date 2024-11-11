#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const long long mo = (long long)1e9 + 7;
const long long M = 210;
long long S[M][M], C[M][M];
inline long long add(long long p, long long q) {
  return (p += q) >= mo ? p - mo : p;
}
inline long long sub(long long p, long long q) {
  return (p -= q) < 0 ? p + mo : p;
}
inline long long ksm(long long p, long long q, long long mo) {
  long long res = 1;
  for (; q; q >>= 1, p = 1ll * p * p % mo)
    if (q & 1) res = 1ll * res * p % mo;
  return res;
}
inline void init_Stirling() {
  S[0][0] = 1;
  for (long long i = (1); i <= (M - 5); ++i) S[i][0] = 0;
  for (long long i = (1); i <= (M - 5); ++i)
    for (long long j = (1); j <= (i); ++j)
      S[i][j] = sub(S[i - 1][j - 1], 1ll * (i - 1) * S[i - 1][j] % mo);
}
inline void init_C() {
  for (long long i = (0); i <= (M - 5); ++i) C[i][0] = 1;
  for (long long i = (1); i <= (M - 5); ++i)
    for (long long j = (1); j <= (i); ++j)
      C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  cerr << C[7][3] << endl;
}
struct sqt5 {
  long long a, b;
  sqt5() {}
  sqt5(long long _a, long long _b) { a = _a, b = _b; }
  sqt5 operator+(const sqt5 &p) const { return sqt5(add(a, p.a), add(b, p.b)); }
  sqt5 operator-(const sqt5 &p) const { return sqt5(sub(a, p.a), sub(b, p.b)); }
  sqt5 operator*(const sqt5 &p) const {
    return sqt5(add(1ll * a * p.a % mo, 1ll * b * p.b % mo * 5ll % mo),
                add(1ll * b * p.a % mo, 1ll * a * p.b % mo));
  }
  sqt5 operator*(const long long &p) const {
    return sqt5(1ll * a * p % mo, 1ll * b * p % mo);
  }
  sqt5 operator/(const sqt5 &p) const {
    long long iv = ksm(
        sub(1ll * p.a * p.a % mo, 1ll * p.b * p.b % mo * 5ll % mo), mo - 2, mo);
    sqt5 inp = sqt5(1ll * p.a * iv % mo, 1ll * (mo - p.b) * iv % mo);
    return (*this) * inp;
  }
} A, B, invsq5;
inline sqt5 ksm_sqt5(sqt5 p, long long q, long long mo) {
  sqt5 res = sqt5(1, 0);
  for (; q; q >>= 1, p = p * p)
    if (q & 1) res = res * p;
  return res;
}
long long k, l, r, fack;
long long sum(long long n) {
  sqt5 res = sqt5(0, 0);
  for (long long j = (0); j <= (k); ++j) {
    long long eff = S[k][j];
    sqt5 dq = sqt5(0, 0);
    sqt5 ef = ksm_sqt5(invsq5, j, mo);
    for (long long p = (0); p <= (j); ++p) {
      sqt5 q = ksm_sqt5(A, p, mo) * ksm_sqt5(B, j - p, mo);
      sqt5 ret =
          (ksm_sqt5(q, 3, mo) - ksm_sqt5(q, n + 3, mo)) / (sqt5(1, 0) - q);
      if (q.a == 1 && q.b == 0) ret = sqt5(n % mo, 0);
      dq = dq + ret * (1ll * C[j][p] * ((j - p) & 1 ? mo - 1 : 1) % mo);
    }
    res = res + dq * eff * ef;
  }
  return 1ll * res.a * ksm(fack, mo - 2, mo) % mo;
}
int main() {
  init_Stirling();
  init_C();
  A = sqt5((mo + 1) / 2, (mo + 1) / 2),
  B = sqt5((mo + 1) / 2, mo - (mo + 1) / 2);
  invsq5 = sqt5(0, ksm(5, mo - 2, mo));
  k = read();
  l = read(), r = read();
  fack = 1;
  for (long long i = (1); i <= (k); ++i) fack = 1ll * fack * i % mo;
  printf("%lld\n", sub(sum(r), sum(l - 1)));
}
