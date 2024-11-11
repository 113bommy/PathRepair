#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2, typename T3>
struct triplet {
  T1 first;
  T2 second;
  T3 third;
  triplet() {
    first = T1();
    second = T2();
    third = T3();
  }
  triplet(T1 a, T2 b, T3 c) { first = a, second = b, third = c; }
};
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = triplet<int, int, int>;
using pl = pair<ll, ll>;
using tl = triplet<ll, ll, ll>;
const int INF = ~(1 << 31);
const int MININF = (1 << 31);
const ll LNF = ~(1LL << 63);
const ll MINLNF = (1LL << 63);
const ll MOD1 = 1e9 + 7;
const ll MOD9 = 998244353;
class Combinatorics {
 public:
  ll n, Mod;
  vector<ll> fact, rfact, powers2;
  Combinatorics(ll _n, ll mod) {
    n = _n;
    Mod = mod;
    fact.resize(n + 1);
    rfact.resize(n + 1);
    powers2.resize(n + 1);
  }
  ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
      if (y & 1) res = res * x % Mod;
      x = x * x % Mod, y >>= 1;
    }
    return res;
  }
  ll inv(ll x) { return quick_pow(x, Mod - 2); }
  ll moddiv(ll a, ll b) { return 1LL * a * inv(b) % Mod; }
  void precalc() {
    powers2[0] = fact[0] = 1;
    for (int i = 1; i <= n; i++)
      fact[i] = fact[i - 1] * i % Mod, powers2[i] = powers2[i - 1] * 2LL % Mod;
    rfact[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--) rfact[i] = rfact[i + 1] * (i + 1) % Mod;
  }
  ll pow2(ll n) { return powers2[n]; }
  ll nchoosek(ll a, ll b) {
    return 1LL * fact[a] * rfact[b] % Mod * rfact[a - b] % Mod;
  }
  ll catalan(ll a) {
    return 1LL * fact[2 * a] * rfact[a] % Mod * rfact[a + 1] % Mod;
  }
};
void ans1(bool x) {
  if (x)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
void ans2(bool x) {
  if (x)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
const int NMAX = 2e5;
ll n, m, x, y;
void Input() { cin >> n >> m; }
void Solve() {
  if (n == 2)
    cout << m;
  else {
    Combinatorics C(NMAX, MOD9);
    C.precalc();
    cout << (1LL * C.nchoosek(m, n - 1) * (n - 2) % MOD9 * C.pow2(n - 3) %
             MOD9);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    Input();
    Solve();
  }
  return 0;
}
