#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int MOD = p - 1;
const int M = 105;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, m, k, t, x, y;
struct Matrix {
  long long n, m, a[M][M];
  Matrix() {
    n = m = 0;
    memset(a, 0, sizeof a);
  }
  void clear() { memset(a, 0, sizeof a); }
  Matrix operator*(const Matrix &b) const {
    Matrix r;
    r.n = n;
    r.m = b.m;
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++)
        for (long long k = 1; k <= b.m; k++)
          r.a[i][k] = (r.a[i][k] + a[i][j] * b.a[j][k]) % MOD;
    return r;
  }
  void print() {
    for (long long i = 1; i <= n; i++, puts(""))
      for (long long j = 1; j <= m; j++) printf("%lld ", a[i][j]);
  }
} A;
Matrix qkpow(Matrix a, long long b) {
  Matrix r;
  r.n = r.m = k;
  for (long long i = 1; i <= k; i++) r.a[i][i] = 1;
  while (b > 0) {
    if (b & 1) r = r * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}
long long bsgs(long long a, long long b) {
  long long m = sqrt(p) + 1, t = 1, tt = 1;
  map<long long, long long> mp;
  for (long long i = 0; i < m; i++) {
    mp[b * t % p] = i;
    t = t * a % p;
  }
  for (long long i = 1; i <= m; i++) {
    tt = tt * t % p;
    if (mp[tt]) return i * m - mp[tt];
  }
  return 0;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, y, x);
  y -= (a / b);
  return d;
}
long long fast(long long a, long long b) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return r;
}
signed main() {
  k = read();
  A.n = A.m = k;
  for (long long i = 1; i <= k; i++) A.a[1][i] = read();
  for (long long i = 1; i <= k; i++) A.a[i + 1][i] = 1;
  n = read();
  m = read();
  A = qkpow(A, n - k);
  n = A.a[1][1];
  t = bsgs(3, m);
  long long d = exgcd(n, MOD, x, y);
  x = (x % MOD + MOD) % MOD;
  if (t % d)
    puts("-1");
  else {
    t /= d;
    printf("%lld\n", fast(3, t * x % MOD));
  }
}
