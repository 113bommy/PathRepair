#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(unsigned long long &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.F);
  putchar(' ');
  _W(x.S);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int MOD = 998244353, mod = 1e9 + 9;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int MAXN = 2e6 + 10, MAXM = 4e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int inv2 = 5e8 + 4;
const int Lim = 1 << 20;
long long f[MAXN], g[MAXN], n, a[MAXN], m;
void solve() {
  R(n);
  for (int i = 1; i <= n; i++) R(a[i]), m += a[i];
  long long invm = powmod(m, MOD - 2), invn1 = powmod(n - 1, MOD - 2);
  for (int i = 0; i < m; i++) {
    long long k1 = powmod(m - i, MOD - 2) * m % MOD * (n - 1) % MOD;
    long long k2 = i * invm % MOD;
    g[i] = (k2 * (i > 0 ? g[i - 1] : 0) + 1) % MOD * k1 % MOD;
  }
  for (int i = m; i >= 0; i--) f[i] = (f[i + 1] + g[i]) % MOD;
  long long ans = 0;
  for (int i = 1; i <= n; i++) (ans += f[a[i]]) %= MOD;
  ans = (ans + MOD - f[0] * (n - 1)) % MOD;
  W(ans * powmod(n, MOD - 2) % MOD);
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
