#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
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
const int mod = 1000000007;
const int maxn = 3000100;
const int inf = 0x3f3f3f3f;
long long fac[maxn + 5], ifac[maxn + 5], inv[maxn + 5];
long long ans[maxn + 5];
void solve() {
  inv[1] = fac[0] = ifac[0] = 1;
  for (auto i = 2; i <= maxn; i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  for (auto i = 1; i <= maxn; i++) fac[i] = fac[i - 1] * i % mod;
  for (auto i = 1; i <= maxn; i++) ifac[i] = ifac[i - 1] * inv[i] % mod;
  auto binom = [](int n, int m) {
    if (m < 0 || n < m) return 0ll;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
  };
  int n, q;
  scanf("%d%d", &n, &q);
  for (auto i = 1; i <= n; i++) ans[1] = (ans[1] + binom(i * 3, 1)) % mod;
  for (auto i = 1; i <= n; i++) ans[2] = (ans[2] + binom(i * 3, 2)) % mod;
  for (auto i = 3; i <= n * 3; i++)
    ans[i] = (binom(n * 3 + 3, i + 1) - binom(3, i + 1) - ans[i - 2] -
              ans[i - 1] * 3 + 5ll * mod) %
             mod * inv[3] % mod;
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", ans[x]);
  }
}
int main() {
  int tt = 1;
  while (tt--) solve();
  return 0;
}
