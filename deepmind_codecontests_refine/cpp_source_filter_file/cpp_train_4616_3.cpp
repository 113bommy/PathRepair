#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    sum = (sum << 1) + (sum << 3) + (c ^ 48);
    c = getchar();
  }
  return sum;
}
long long const maxn = 1e6 + 5;
double const eps = 1e-6;
long long n, v, ans, ansa, ansb, ansc, p[maxn], c[maxn];
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    b >>= 1;
    a = a * a;
  }
  return res;
}
long long calc(long long a) { return 2 * sqrt(v) * sqrt(a) + v / a; }
void dfsb(long long x, long long a, long long b) {
  if ((long double)a * b * b - eps > v) return;
  if (x > n) {
    if ((long double)a * b + v / a + v / b < ans) {
      ans = a * b + v / a + v / b;
      ansa = a, ansb = b, ansc = v / a / b;
    }
    return;
  }
  long long t = 1;
  for (long long i = 1; i <= c[x]; i++) t *= p[x];
  for (long long i = c[x]; i >= 0; i--) {
    c[x] -= i;
    dfsb(x + 1, a, b * t);
    c[x] += i, t /= p[x];
  }
}
void dfsa(long long x, long long a) {
  if ((long double)a * a * a - eps > v) return;
  if (x > n) {
    if (calc(a) <= ans) dfsb(1, a, 1);
    return;
  }
  long long t = 1;
  for (long long i = 1; i <= c[x]; i++) t *= p[x];
  for (long long i = c[x]; i >= 0; i--) {
    c[x] -= i;
    dfsa(x + 1, a * t);
    t /= p[x], c[x] += i;
  }
}
signed main() {
  long long T = read();
  while (T--) {
    n = read();
    ans = ansa = ansb = ansc = 1e17, v = 1;
    for (long long i = 1; i <= n; i++) p[i] = read(), c[i] = read();
    for (long long i = 1; i <= n; i++) v *= ksm(p[i], c[i]);
    dfsa(1, 1);
    printf("%lld %lld %lld %lld\n", ans * 2, ansa, ansb, ansc);
  }
  return 0;
}
