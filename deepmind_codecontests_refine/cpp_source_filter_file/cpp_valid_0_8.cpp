#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ '0');
    s = getchar();
  }
  x *= f;
}
template <typename T>
void write(T x, char s = '\n') {
  if (!x) {
    putchar('0');
    putchar(s);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  T t = 0, tmp[25] = {};
  while (x) tmp[t++] = x % 10, x /= 10;
  while (t-- > 0) putchar(tmp[t] + '0');
  putchar(s);
}
const int MAXN = 3e6 + 5;
const int mod = 1e9 + 7;
long long f[MAXN][3], fac[MAXN * 3], finv[MAXN * 3], inv[MAXN * 3];
int n, Q;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
void pre() {
  int N = 3e6;
  fac[0] = finv[0] = 1;
  inv[1] = 1;
  for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i % mod;
  finv[N] = qpow(fac[N], mod - 2);
  for (int i = N - 1; i >= 1; --i) finv[i] = finv[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= N; ++i) inv[i] = finv[i] * fac[i - 1] % mod;
}
long long C(long long n, long long m) {
  return fac[n] * finv[n - m] % mod * finv[m] % mod;
}
int main() {
  read(n), read(Q);
  pre();
  f[0][0] = f[0][1] = f[0][2] = n + 1;
  for (int i = 1; i <= 3 * n; ++i) {
    f[i][0] = C(3 * n + 3, i + 1) - 2 * f[i - 1][0] % mod - f[i - 1][1];
    f[i][0] = (f[i][0] % mod + mod) % mod;
    f[i][0] = f[i][0] * inv[3] % mod;
    f[i][1] = (f[i][0] + f[i - 1][0]) % mod;
    f[i][2] = (f[i][1] + f[i - 1][1]) % mod;
  }
  while (Q-- > 0) {
    int x;
    read(x);
    write(f[x][0]);
  }
  return 0;
}
