#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, cnt;
int pm[10003], f[10003], g[10003];
long long a[10003], b[10003], c[10003], d[10003];
void ex_gcd(long long, long long, long long &, long long &);
int quick_pow(int, int);
bool merge();
void fac(int, long long *);
void prime(int);
long long gcd(long long, long long);
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", f + i, g + i);
    prime(f[i]);
    prime(g[i]);
  }
  sort(pm + 1, pm + 1 + cnt);
  cnt = unique(pm + 1, pm + 1 + cnt) - pm - 1;
  fac(f[1], a);
  fac(g[1], b);
  for (int i = 2; i <= n; ++i) {
    fac(f[i], c);
    fac(g[i], d);
    if (!merge()) return puts("-1"), 0;
  }
  int ans = 1;
  for (int i = 1; i <= cnt; ++i)
    ans = 1ll * ans * quick_pow(pm[i], a[i] % (mod - 1)) % mod;
  cout << ans << endl;
  return 0;
}
void prime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) {
      pm[++cnt] = i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) pm[++cnt] = x;
  return;
}
void fac(int x, long long *p) {
  for (int i = 1; i <= cnt; ++i) {
    p[i] = 0;
    while (x % pm[i] == 0) ++p[i], x /= pm[i];
  }
  return;
}
int quick_pow(int x, int y) {
  int sum = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) sum = 1ll * sum * x % mod;
  return sum;
}
void ex_gcd(long long x, long long y, long long &a, long long &b) {
  if (!y) return a = 1, b = 0, void();
  ex_gcd(y, x % y, a, b);
  a -= x / y * b;
  swap(a, b);
  return;
}
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
bool merge() {
  long long cb = 0, cd = 0;
  for (int i = 1; i <= cnt; ++i) cb += b[i], cd += d[i];
  if (!cb && !cd) {
    for (int i = 1; i <= cnt; ++i)
      if (a[i] != c[i]) return false;
    return true;
  }
  if (!cb || !cd) {
    if (!cb) swap(a, c), swap(b, d), swap(cb, cd);
    long long k = 0;
    for (int i = 1; i <= cnt; ++i)
      if (b[i]) {
        if (c[i] < a[i] || (c[i] - a[i]) % b[i]) return false;
        k = (c[i] - a[i]) / b[i];
        break;
      } else if (a[i] != c[i])
        return false;
    for (int i = 1; i <= cnt; ++i) {
      if (a[i] + k * b[i] != c[i]) return false;
      a[i] += k * b[i];
      b[i] = 0;
    }
    return true;
  }
  int p1 = 0, p2 = 0;
  for (int i = 1; i <= cnt; ++i)
    if (b[i] * cd != d[i] * cb) {
      p1 = i;
      break;
    }
  if (p1) {
    for (int i = 1; i <= cnt; ++i)
      if (b[i] * d[p1] != d[i] * b[p1]) {
        p2 = i;
        break;
      }
    long long x1 =
        c[p1] * d[p2] - c[p2] * d[p1] - a[p1] * d[p2] + a[p2] * d[p1];
    long long x2 =
        a[p1] * b[p2] - a[p2] * b[p1] - c[p1] * b[p2] + c[p2] * b[p1];
    long long y1 = b[p1] * d[p2] - b[p2] * d[p1];
    long long y2 = d[p1] * b[p2] - d[p2] * b[p1];
    if (x1 * y1 < 0 || x2 * y2 < 0 || abs(x1) % abs(y1) || abs(x2) % abs(y2))
      return false;
    x1 /= y1;
    x2 /= y2;
    for (int i = 1; i <= cnt; ++i) {
      if (a[i] + b[i] * x1 != c[i] + d[i] * x2) return false;
      a[i] += b[i] * x1;
      b[i] = 0;
    }
    return true;
  }
  long long kb, kd, k;
  for (int i = 1; i <= cnt; ++i)
    if (b[i]) {
      long long g = gcd(b[i], d[i]);
      kb = b[i] / g;
      kd = d[i] / g;
      break;
    }
  for (int i = 1; i <= cnt; ++i)
    if (b[i]) {
      if ((a[i] - c[i]) % (b[i] / kb) == 0) {
        k = (a[i] - c[i]) / (b[i] / kb);
        break;
      } else
        return false;
    }
  for (int i = 1; i <= cnt; ++i)
    if (c[i] + (b[i] / kb) * k != a[i]) return false;
  if (k < 0) swap(a, c), swap(b, d), swap(kb, kd), k = -k;
  long long x, y;
  ex_gcd(kb, kd, x, y);
  x = (-k * x % kd + kd) % kd;
  for (int i = 1; i <= cnt; ++i) a[i] += b[i] * x, b[i] *= kd;
  return true;
}
