#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
template <class T>
void mini(T &l, T r) {
  l = min(l, r);
}
template <class T>
void maxi(T &l, T r) {
  l = max(l, r);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const long long N = 5E3 + 10, MOD = 1E9 + 7;
int n, K;
int a[N];
long long f[N];
long long modExp(long long e, long long n, long long m = MOD) {
  long long ret = 1;
  for (; n; n >>= 1, e = e * e % m)
    if (n & 1) ret = ret * e % m;
  return ret;
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) f[j] = (f[j] + f[j - 1]) % MOD;
    long long t = f[n];
    for (int j = n; j >= i; --j) f[j] = f[j - 1] * a[j] % MOD;
    f[i - 1] = t;
  }
  long long t = 1, inv = modExp(n, MOD - 2);
  long long ans = 1;
  for (int i = 1; i <= n; ++i) ans = ans * a[i] % MOD;
  for (int i = n; i >= 0; --i) {
    ans -= f[i] * t % MOD;
    t = t * inv % MOD * (K - n + i) % MOD * -1;
  }
  printf("%lld\n", (ans % MOD + MOD) % MOD);
  return 0;
}
