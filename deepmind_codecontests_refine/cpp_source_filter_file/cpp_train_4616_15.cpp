#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
long long n, ans, x[20], y[20], a, b, c, aa, bb, cc, maxx, maxy, v;
inline long long mi(long long a, long long b) {
  long long x = 1, y = a;
  while (b) {
    if (b & 1) x *= y;
    y *= y;
    b >>= 1;
  }
  return x;
}
inline void dfss(long long p, long long k) {
  if (k > maxy) return;
  if (p > n) {
    if (k < aa) return;
    bb = k;
    cc = v / aa / bb;
    if (aa * bb + aa * cc + bb * cc < ans)
      ans = aa * bb + aa * cc + bb * cc, a = aa, b = bb, c = cc;
    return;
  }
  if (y[p]) y[p]--, dfss(p, k * x[p]), y[p]++;
  dfss(p + 1, k);
}
inline void dfs(long long p, long long k) {
  if (k > maxx) return;
  if (p > n) {
    aa = k;
    if (v / aa + aa * 2 * sqrt(v / aa) < ans) {
      maxy = sqrt(v / aa) + 1e-8;
      dfss(1, 1);
    }
    return;
  }
  if (y[p]) y[p]--, dfs(p, k * x[p]), y[p]++;
  dfs(p + 1, k);
}
signed main() {
  long long T = read();
  while (T--) {
    n = read();
    v = 1;
    for (long long i = 1; i <= n; i++) {
      x[i] = read();
      y[i] = read();
      v *= mi(x[i], y[i]);
    }
    ans = 1e18;
    a = b = c = 0;
    maxx = pow(v, 1.0 / 3.0) + 1e-8;
    dfs(1, 1);
    printf("%lld %lld %lld %lld\n", 2 * ans, a, b, c);
  }
  return 0;
}
