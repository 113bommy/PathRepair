#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
static inline int ctz(unsigned x) { return __builtin_ctz(x); }
static inline int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
static inline int clz(unsigned x) { return __builtin_clz(x); }
static inline int clzll(unsigned long long x) { return __builtin_clzll(x); }
static inline int popcnt(unsigned x) { return __builtin_popcount(x); }
static inline int popcntll(unsigned long long x) {
  return __builtin_popcountll(x);
}
static inline int bsr(unsigned x) { return 31 ^ clz(x); }
static inline int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
int main() {
  canhazfast();
  static long long a[200016];
  int n, b = 0;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] >= k) return cout << "0", 0;
  }
  while (!a[b]) ++b;
  if (n - b == 2) return cout << (k - a[b + 1] - 1) / a[b] + 1, 0;
  if (n - b == 3) {
    long long x = a[b], y = a[b + 1], z = a[b + 2];
    assert(x);
    long long lo = 1, hi = sqrt(2 * k / x);
    while (lo < hi) {
      long long m = (lo + hi) / 2;
      long long f = m * (m + 1) / 2 * x + m * y + z;
      if (f >= k)
        hi = m;
      else
        lo = m + 1;
    }
    return cout << lo, 0;
  }
  for (int i = 1; i <= 2000000; ++i) {
    for (int j = b + 1; j < n; ++j) {
      a[j] += a[j - 1];
      if (a[j] >= k) return cout << i, 0;
    }
  }
  cout << "wat?";
  return 0;
}
