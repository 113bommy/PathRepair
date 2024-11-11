#include <bits/stdc++.h>
template <class T>
inline void chkmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class T>
inline void chkmin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void read(T &x) {
  char c;
  int f = 1;
  x = 0;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    f = -1;
  else
    x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
const int MOD = 1e9 + 7, HALF = (MOD + 1) >> 1;
const int K = 200;
int fac[K + 9], inv[K + 9];
int C[K + 9][K + 9];
int fpm(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = (long long)ret * a % MOD;
    a = (long long)a * a % MOD, b >>= 1;
  }
  return ret;
}
void prepare(int k) {
  for (int i = 0; i <= k; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = (long long)fac[i - 1] * i % MOD;
  inv[k] = fpm(fac[k], MOD - 2);
  for (int i = k - 1; i >= 0; --i)
    inv[i] = (long long)inv[i + 1] * (i + 1) % MOD;
}
void mult(int *c, int p) {
  static int r[K + 9];
  int x[2] = {(MOD - p) % MOD, 1};
  memset(r, 0, sizeof r);
  for (int i = 0; i <= p; ++i)
    for (int j = 0; j < 2; ++j)
      (r[i + j] += (long long)c[i] * x[j] % MOD) %= MOD;
  memcpy(c, r, sizeof r);
}
struct num {
  int a, b;
  num() { a = b = 0; }
  num(int _a, int _b) : a(_a), b(_b) {}
  friend num operator+(const num &p, const num &q) {
    return num((p.a + q.a) % MOD, (p.b + q.b) % MOD);
  }
  friend num operator-(const num &p, const num &q) {
    return num((p.a - q.a + MOD) % MOD, (p.b - q.b + MOD) % MOD);
  }
  friend num operator*(const num &p, const num &q) {
    return num(((long long)p.a * q.a + 5ll * p.b * q.b) % MOD,
               ((long long)p.a * q.b + (long long)q.a * p.b) % MOD);
  }
  friend num operator/(const num &p, const num &q) {
    int val =
        fpm(((long long)q.a * q.a % MOD - 5ll * q.b * q.b % MOD + MOD) % MOD,
            MOD - 2);
    return num(
        ((long long)p.a * q.a % MOD - 5ll * p.b * q.b % MOD + MOD) * val % MOD,
        ((long long)p.b * q.a % MOD - (long long)q.b * p.a % MOD + MOD) * val %
            MOD);
  }
};
num fpm(num a, long long b) {
  num ret = num(1, 0);
  while (b) {
    if (b & 1) ret = ret * a;
    a = a * a, b >>= 1;
  }
  return ret;
}
num pow(int t, int p, long long n) {
  num x;
  if (p < 0)
    x = fpm(num((long long)(MOD - 1) * HALF % MOD, HALF), -p);
  else
    x = fpm(num(HALF, HALF), p);
  if (t & 1) x = x * num(MOD - 1, 0);
  num ret;
  if (x.a == 1 && x.b == 0)
    ret.a = n;
  else
    ret = (fpm(x, n + 1) - x) / (x - num(1, 0));
  if (t & 1) ret = ret * num(MOD - 1, 0);
  return ret;
}
int calc(long long n, int k) {
  num ret;
  for (int i = 0; i <= k; ++i)
    ret = ret + pow(k - i, 2 * i - k, n) * num(C[k][i], 0);
  if (k & 1)
    return (long long)ret.b * fpm(fpm(5, k >> 1), MOD - 2) % MOD;
  else
    return (long long)ret.a * fpm(fpm(5, k >> 1), MOD - 2) % MOD;
}
int solve(long long n, int k) {
  n += 2;
  static int coe[K + 9];
  coe[0] = 1;
  for (int i = 0; i < k; ++i) mult(coe, i);
  int ans = 0;
  for (int i = 0; i <= k; ++i)
    (ans += (long long)coe[i] * calc(n, i) % MOD) %= MOD;
  ans = (long long)ans * inv[k] % MOD;
  return ans;
}
int main() {
  int k;
  long long l, r;
  read(k), read(l), read(r), prepare(k);
  std::cout << (solve(r, k) - solve(l - 1, k) + MOD) % MOD << std::endl;
  return 0;
}
