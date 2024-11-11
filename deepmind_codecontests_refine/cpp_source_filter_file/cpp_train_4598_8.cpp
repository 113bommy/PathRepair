#include <bits/stdc++.h>
int N = 1e6, SZ = 320, INF = 1 << 29;
long long LINF = (1LL << 60), mod = 1e9 + 7;
const long double eps = 1e-9, PI = acos(-1.0);
using namespace std;
char READ_DATA;
int SIGNAL_INPUT;
template <typename Type>
inline Type ru(Type &v) {
  SIGNAL_INPUT = 1;
  while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
    if (READ_DATA == '-')
      SIGNAL_INPUT = -1;
    else if (READ_DATA == EOF)
      return EOF;
  v = READ_DATA - '0';
  while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9')
    v = v * 10 + READ_DATA - '0';
  v *= SIGNAL_INPUT;
  return v;
}
inline long long modru(long long &v) {
  long long p = 0;
  SIGNAL_INPUT = 1;
  while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
    if (READ_DATA == '-')
      SIGNAL_INPUT = -1;
    else if (READ_DATA == EOF)
      return EOF;
  p = v = READ_DATA - '0';
  while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9') {
    v = (v * 10 + READ_DATA - '0') % mod;
    p = (p * 10 + READ_DATA - '0') % (mod - 1);
  }
  v *= SIGNAL_INPUT;
  return p;
}
template <typename A, typename B>
inline int ru(A &x, B &y) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  return 2;
}
template <typename A, typename B, typename C>
inline int ru(A &x, B &y, C &z) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  ru(z);
  return 3;
}
template <typename A, typename B, typename C, typename D>
inline int ru(A &x, B &y, C &z, D &w) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  ru(z);
  ru(w);
  return 4;
}
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline long long ss(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return ans;
}
template <typename Type>
void brc(Type *a, int n) {
  int k;
  for (int i = 1, j = n / 2; i < n - 1; i++) {
    if (i < j) swap(a[i], a[j]);
    k = n >> 1;
    while (j >= k) {
      j ^= k;
      k >>= 1;
    }
    if (j < k) j ^= k;
  }
}
void fft(complex<double> *a, int n, int inv = 1) {
  complex<double> u, t;
  brc(a, n);
  for (int h = 2; h <= n; h <<= 1) {
    complex<double> wn(cos(inv * 2.0 * PI / h), sin(inv * 2.0 * PI / h));
    for (int j = 0; j < n; j += h) {
      complex<double> w(1, 0);
      for (int k = j; k < j + (h >> 1); k++) {
        u = a[k];
        t = w * a[k + (h >> 1)];
        a[k] = u + t;
        a[k + (h >> 1)] = u - t;
        w *= wn;
      }
    }
  }
  if (inv == -1)
    for (int i = 0; i < n; i++) {
      a[i] /= n;
    }
}
void ntt(long long *a, int n, int inv = 1) {
  long long u, t;
  brc(a, n);
  for (int h = 2; h <= n; h <<= 1) {
    long long wn = ss(3, (mod - 1) / h);
    if (inv == -1) wn = ss(wn, mod - 2);
    for (int j = 0; j < n; j += h) {
      long long w = 1;
      for (int k = j; k < j + (h >> 1); k++) {
        u = a[k];
        t = w * a[k + (h >> 1)] % mod;
        a[k] = (u + t) % mod;
        a[k + (h >> 1)] = (u - t + mod) % mod;
        (w *= wn) %= mod;
      }
    }
  }
  if (inv == -1) {
    long long tmp = ss(n, mod - 2);
    for (int i = 0; i < n; i++) (a[i] *= tmp) %= mod;
  }
}
struct Edge {
  int u, v, nxt;
  long long w;
  Edge(int _u = 0, int _v = 0, long long _w = 0, int _nxt = -1) {
    u = _u;
    v = _v;
    w = _w;
    nxt = _nxt;
  }
  int operator<(const Edge &b) const { return u < b.u; }
};
const int maxn = 1e6 + 5;
int n, x, a[maxn];
int pre[maxn], suf[maxn];
int main() {
  ru(n, x);
  for (int i = 1; i < n + 1; i++) {
    ru(a[i]);
  }
  for (int i = 0; i <= x + 1; i++) {
    pre[i] = 1;
    suf[i] = x;
  }
  int maxv = 1, minv = x, up = x, down = 1;
  for (int i = 1; i < n + 1; i++) {
    pre[a[i]] = max(pre[a[i]], maxv);
    if (pre[a[i]] > a[i]) {
      down = max(down, a[i]);
    }
    maxv = max(maxv, a[i]);
  }
  for (int i = n; i >= 1; i--) {
    suf[a[i]] = min(suf[a[i]], minv);
    if (suf[a[i]] < a[i]) {
      up = min(up, a[i]);
    }
    minv = min(minv, a[i]);
  }
  for (int i = 1; i < x + 1; i++) {
    pre[i] = max(pre[i], pre[i - 1]);
  }
  for (int i = x; i >= 1; i--) {
    suf[i] = min(suf[i + 1], suf[i]);
  }
  long long ans = 0;
  int j = down;
  for (int i = 1; i <= up; i++) {
    while (j <= x && (j < pre[i - 1])) j++;
    ans += x - j + 1;
  }
  cout << ans;
}
