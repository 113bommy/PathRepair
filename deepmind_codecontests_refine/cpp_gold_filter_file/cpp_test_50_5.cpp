#include <bits/stdc++.h>
using namespace std;
long long IOS = []() {
  ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
template <class T>
void _W(const T &x) {
  cout << x;
}
template <class T>
void _W(T &x) {
  cout << x;
}
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++)) cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  cout << ", ";
  W(tail...);
}
using pii = pair<long long, long long>;
const long long N = 2e6 + 10, mod = 998244353;
inline long long quick(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long n, tp;
long long a[N], f[N], mi[N], sf[N], pre[N];
void solve() {
  scanf("%d", &n);
  for (long long i = 1; i <= n; i++) scanf("%d", &a[i]);
  tp = 1;
  f[0] = 1;
  sf[tp] = 1;
  mi[tp] = a[1];
  pre[tp] = a[1];
  for (long long i = 1; i <= n; i++) {
    long long A = a[i + 1], sn = 0;
    f[i] = -pre[tp];
    while (tp && A <= mi[tp]) sn = (sn + sf[tp]) % mod, tp--;
    mi[++tp] = A;
    sf[tp] = (sn + f[i]) % mod;
    pre[tp] = (pre[tp - 1] + 1ll * A * sf[tp]) % mod;
  }
  long long ans = ((n & 1 ? -f[n] : f[n]) + mod) % mod;
  printf("%d\n", ans);
}
signed main() {
  long long tt = 1;
  while (tt--) {
    solve();
  }
}
