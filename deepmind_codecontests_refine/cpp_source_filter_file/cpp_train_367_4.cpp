#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  char c = getchar();
  long long tot = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    tot = -1;
    c = getchar();
  }
  long long sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * tot;
}
inline void wr(long long x) {
  if (x < 0) {
    putchar('-');
    wr(-x);
    return;
  }
  if (x >= 10) wr(x / 10);
  putchar(x % 10 + '0');
}
inline void wrn(long long x) {
  wr(x);
  putchar('\n');
}
inline void wri(long long x) {
  wr(x);
  putchar(' ');
}
inline void wrn(long long x, long long y) {
  wri(x);
  wrn(y);
}
inline void wrn(long long a, long long b, long long c) {
  wri(a);
  wrn(b, c);
}
long long n, m, d, inv[500055], mod, ans;
long long f[1005][11][505];
inline void add(long long &x, long long k) {
  x += k;
  x -= (x >= mod) ? mod : 0;
  x += (x < 0) ? mod : 0;
}
void init(long long x) {
  inv[0] = inv[1] = 1;
  for (long long i = (2); i <= (n); i++)
    inv[i] = mod - 1LL * (mod / i) * inv[mod % i] % mod;
}
inline long long dp(long long n, long long d, long long k) {
  k = min(k, n - 1);
  if (f[n][d][k] != -1) return f[n][d][k];
  if ((n == 1 && d == m - 1) || (n == 1 && !d)) return f[n][d][k] = 1;
  if (n == 1 || !k) return f[n][d][k] = 0;
  long long t = dp(k, m - 1, k);
  f[n][d][k] = dp(n, d, k - 1);
  long long num = 1;
  for (long long i = (1); i <= (min((n - 1) / k, d)); i++) {
    num = 1LL * num * (t + i - 1) % mod * inv[i] % mod;
    add(f[n][d][k], dp(n - k * i, d - i, k - 1) * num % mod);
  }
  return f[n][d][k];
}
signed main() {
  n = read();
  m = read();
  mod = read();
  init(n);
  if (n == 1 || n == 2) {
    return puts("1"), 0;
  }
  if ((n - 2) % (m - 1) != 0) return puts("0"), 0;
  ;
  memset(f, -1, sizeof(f));
  ans = dp(n, m, (n - 1) / 2);
  if (n % 2 == 0) {
    long long t = dp(n / 2, m - 1, n / 2 - 1);
    add(ans, 1LL * t * (t + 1) % mod);
  }
  wrn(ans);
  return 0;
}
