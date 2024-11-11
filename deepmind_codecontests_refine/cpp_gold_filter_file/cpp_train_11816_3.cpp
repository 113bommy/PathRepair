#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 1;
  char k = getchar();
  x = 0;
  for (; k > '9' || k < '0'; k = getchar())
    if (k == '-') f = -1;
  for (; k >= '0' && k <= '9'; k = getchar()) x = x * 10 + k - '0';
  x *= f;
}
template <class T>
inline void _print(T x) {
  if (x >= 10) _print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  _print(x);
}
long long mul(long long a, long long b, long long mod) {
  long double c = 1.;
  return (a * b - (long long)(c * a * b / mod) * mod) % mod;
}
inline int qpow(int x, int k, int mod) {
  int res = 1, bas = x;
  while (k) {
    if (k & 1) res = 1ll * res * bas % mod;
    bas = 1ll * bas * bas % mod, k >>= 1;
  }
  return res;
}
const int N = 2e5 + 5, mod = 1e9 + 7;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void inc(int &x, int y) { x = add(x, y); }
int n, m, k, x, y, f[N], fac[N], ifac[N];
pair<int, int> node[N];
inline int C(int n, int m) { return mul(fac[n], mul(ifac[m], ifac[n - m])); }
int main() {
  read(n), read(m), read(k);
  for (register int i = 1; i <= k; ++i)
    read(x), read(y), node[i] = make_pair(x, y);
  node[k + 1] = make_pair(n, m);
  sort(node + 1, node + 1 + k), fac[0] = 1;
  for (register int i = 1; i <= n + m; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n + m] = qpow(fac[n + m], mod - 2, mod);
  for (register int i = n + m - 1; i >= 0; --i)
    ifac[i] = mul(ifac[i + 1], i + 1);
  for (register int i = 1; i <= k + 1; ++i) {
    x = node[i].first, y = node[i].second;
    f[i] = C(x + y - 2, x - 1);
    for (register int j = 1; j < i; ++j) {
      int tx = node[j].first, ty = node[j].second;
      if (ty > y) continue;
      inc(f[i], mod - mul(f[j], C(x - tx + y - ty, x - tx)));
    }
  }
  print(f[k + 1]);
  return 0;
}
