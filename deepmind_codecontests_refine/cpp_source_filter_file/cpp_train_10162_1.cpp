#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};
long double eps = (long double)1 / 1e6;
const long double pi = 3.14159265359;
long long inf = 1e18, mod1 = 1e9 + 7;
long long sqr(long long a) { return a * a; }
long long qb(long long a) { return a * a * a; }
void umin(int &a, int b) { a = min(a, b); }
void umax(int &a, int b) { a = max(a, b); }
bool is_prime(long long val) {
  for (long long i = 2; i <= sqrt(val); i++)
    if (val % i == 0) return 0;
  return 1;
}
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long binpow(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod
                    : sqr(binpow(a, b / 2, mod)) % mod)
           : 1;
}
long long binmult(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod
                    : (2 * binmult(a, b / 2, mod)) % mod)
           : 0;
}
const long long tx[4] = {0, 1, -1, 1};
const long long ty[4] = {-1, 0, 1, 1};
const char rev_to[4] = {'E', 'W', 'N', 'S'};
const int M = 1e9;
const int N = 2e5 + 2;
const int ppp = 73;
const int lg = 19;
const int OPEN = 1;
const int CLOSE = 0;
auto rnd = bind(uniform_int_distribution<long long>(1, N), mt19937(time(0)));
void bad() {
  cout << "NE";
  exit(0);
}
vector<pair<int, int>> g[N];
int n, m;
vector<pair<int, pair<int, int>>> edges;
int v, u, x;
int p[N], second[N];
void init() {
  iota(p, p + N, 0);
  fill(second, second + N, 1);
}
int dad(int v) {
  if (v == p[v]) return v;
  return p[v] = dad(p[v]);
}
bool mg(int a, int b) {
  int ra = dad(a), rb = dad(b);
  if (ra == rb) return 0;
  if (second[ra] < second[rb]) swap(ra, rb);
  p[rb] = ra;
  second[ra] += second[rb];
  return 1;
}
const int K = 32;
int basis[K];
vector<int> lol[N];
int wh[N], inv[N];
int sz;
void add(int msk, int nmb) {
  for (int i = 0; i < K; i++) {
    if (!((1ll << i) & msk)) continue;
    if (!basis[i]) {
      basis[i] = msk;
      wh[sz] = i;
      inv[i] = sz;
      sz++;
      return;
    }
    msk ^= basis[i];
  }
}
void to_conclude(int &val, int nmb) {
  for (int i = K - 1; ~i; i--) {
    val = min(val, val ^ basis[i]);
  }
}
int xr[N];
int V[N], U[N], X[N];
void dfs(int v, int xx, int p) {
  xr[v] = xx;
  for (auto &z : g[v]) {
    if (z.first == p) continue;
    dfs(z.first, z.second ^ xx, v);
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n >> m;
  init();
  vector<int> nd;
  for (int i = 0; i < m; i++) {
    cin >> V[i] >> U[i] >> X[i];
    V[i]--;
    U[i]--;
    int x1 = dad(V[i]), x2 = dad(U[i]);
    if (x1 == x2) {
      nd.push_back(i);
    } else {
      mg(x1, x2);
      g[V[i]].push_back({U[i], X[i]});
      g[U[i]].push_back({V[i], X[i]});
    }
  }
  dfs(0, 0, 0);
  int cnt = 0;
  for (auto &z : nd) {
    int lulw = xr[V[z]] ^ xr[U[z]] ^ X[z];
    if (!lulw) continue;
    add(lulw, z);
    cnt++;
  }
  to_conclude(xr[n - 1], 1);
  cout << xr[n - 1];
  return 0;
}
