#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
inline bool chmax(T &a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T, class U>
inline bool chmin(T &a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
constexpr int INF = 1000000000;
constexpr ll llINF = 3000000000000000000;
constexpr int mod = 1000000007;
constexpr double eps = 1e-8;
const double pi = acos(-1);
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int Random(int mi, int ma) {
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<int> engine(mi, ma);
  return engine(mt);
}
ll gcd(ll a, ll b) {
  while (a % b) {
    a %= b;
    swap(a, b);
  }
  return b;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool isprime(int a) {
  if (a == 1) return false;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
set<int> primes;
void init_prime(int n) {
  primes.insert(2);
  for (int i = 3; i <= n; i += 2) {
    bool f = true;
    for (int j : primes) {
      if (j * j > i) break;
      if (i % j == 0) {
        f = false;
        break;
      }
    }
    if (f) primes.insert(i);
  }
}
ll modpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
vector<ll> inv, fact, factinv;
void init_fact(int n) {
  inv.resize(n + 1);
  fact.resize(n + 1);
  factinv.resize(n + 1);
  inv[0] = 0;
  inv[1] = 1;
  fact[0] = 1;
  factinv[0] = 1;
  for (ll i = 1; i <= n; i++) {
    if (i >= 2) inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
    fact[i] = (fact[i - 1] * i) % mod;
    factinv[i] = factinv[i - 1] * inv[i] % mod;
  }
}
ll _inv(ll a, ll m = mod) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
ll comb(int a, int b) {
  if (a < b) return 0;
  if (a < 0) return 0;
  return fact[a] * factinv[a - b] % mod * factinv[b] % mod;
}
ll multicomb(int a, int b) { return comb(a + b - 1, b); }
int n, p[200010], a[200010];
ll siz[200010], c[200010];
vector<int> g[200010];
void dfs(int x) {
  siz[x] = a[x];
  for (int i : g[x]) {
    dfs(i);
    c[x] += c[i];
    siz[x] += siz[i];
  }
  if (g[x].empty()) c[x]++;
}
void solve() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    g[p[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(0);
  ll ans = 0;
  for (int i = 0; i < n; i++) chmax(ans, (siz[i] + c[i] - 1) / c[i]);
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
