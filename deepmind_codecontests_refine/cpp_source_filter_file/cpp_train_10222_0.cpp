#include <bits/stdc++.h>
using namespace std;
const long long N = 2e4 + 10;
const long long mod = 998244353;
const long long G = 3;
inline long long read() {
  long long p = 0;
  long long f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    p = p * 10 + ch - '0';
    ch = getchar();
  }
  return p * f;
}
long long rt, tot, lc[N << 2], rc[N << 2];
long long R[N << 2];
long long qpow(long long x, long long k, long long mo) {
  long long s = 1;
  while (k) {
    if (k & 1) s = (s * x) % mo;
    x = (x * x) % mo;
    k >>= 1;
  }
  return s;
}
void DFT(long long *a, long long n, long long fh) {
  for (long long i = 0; i < n; i++)
    if (R[i] > i) swap(a[R[i]], a[i]);
  for (long long i = 1; i < n; i <<= 1) {
    long long gn = qpow(G, (mod - 1) / (i << 1), mod);
    for (long long j = 0; j < n; j += (i << 1)) {
      long long g = 1;
      for (long long k = 0; k < i; k++, g = g * gn % mod) {
        long long x = a[j + k];
        long long y = a[j + k + i] * g % mod;
        a[j + k] = x + y;
        a[j + k + i] = (x - y + mod) % mod;
      }
    }
  }
  if (fh == -1) reverse(a + 1, a + n);
}
long long K;
long long a[N << 2], b[N << 2], c[N << 2];
vector<long long> FFT(vector<long long> na, vector<long long> nb) {
  long long m = na.size() - 1 + nb.size() - 1;
  long long l = 0, n;
  for (n = 1; n <= m; n <<= 1) l++;
  for (long long i = 0; i < n; i++) a[i] = b[i] = 0;
  for (long long i = 0; i < na.size(); i++) a[i] = na[i];
  for (long long i = 0; i < nb.size(); i++) b[i] = nb[i];
  for (long long i = 0; i < n; i++)
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << (l - 1));
  DFT(a, n, 1);
  DFT(b, n, 1);
  for (long long i = 0; i < n; i++) c[i] = a[i] * b[i] % mod;
  DFT(c, n, -1);
  for (long long i = 0; i < n; i++)
    c[i] = (long long)(c[i] * qpow(n, mod - 2, mod) % mod);
  m = min(m, K);
  vector<long long> nc;
  for (long long i = 0; i <= m; i++) nc.push_back(c[i]);
  return nc;
}
long long Q, ya[N], yb[N];
vector<long long> build(long long &u, long long L, long long R) {
  if (!u) u = ++tot;
  if (L == R) {
    vector<long long> v;
    v.push_back(1);
    v.push_back(yb[L]);
    return v;
  }
  long long mid = (L + R) >> 1;
  vector<long long> na = build(lc[u], L, mid);
  vector<long long> nb = build(rc[u], mid + 1, R);
  return FFT(na, nb);
}
long long n;
int main() {
  n = read();
  K = read();
  for (long long i = 1; i <= n; i++) {
    ya[i] = read();
  }
  Q = read();
  rt = tot = 0;
  while (Q--) {
    long long op = read();
    if (op == 1) {
      long long q = read();
      long long k = read();
      long long d = read();
      for (long long i = 1; i <= n; i++) yb[i] = ya[i];
      yb[k] = d;
      for (long long i = 1; i <= n; i++) {
        yb[i] = q - yb[i];
        if (yb[i] < 0) yb[i] += mod;
      }
    } else {
      long long q = read();
      long long l = read();
      long long r = read();
      long long d = read();
      for (long long i = 1; i <= n; i++) yb[i] = ya[i];
      for (long long i = l; i <= r; i++) yb[i] += d;
      for (long long i = 1; i <= n; i++) {
        yb[i] = q - yb[i];
        if (yb[i] < 0) yb[i] += mod;
      }
    }
    vector<long long> ans = build(rt, 1, n);
    printf("%lld\n", (ans[K] + mod) % mod);
  }
  return 0;
}
