#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<ll, ll>;
using vi = vc<ll>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
template <class t>
void print(t x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
pi readpi(ll off = 0) {
  ll first, second;
  cin >> first >> second;
  return pi(first + off, second + off);
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
ll botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
ll mask(ll i) { return (ll(1) << i) - 1; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
void myshuffle(vc<t>& first) {
  for (ll i = ll(0); i < ll(ll(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
ll lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
vvc<ll> readGraph(ll n, ll m) {
  vvc<ll> g(n);
  for (ll i = ll(0); i < ll(m); i++) {
    ll first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  return g;
}
vvc<ll> readTree(ll n) { return readGraph(n, n - 1); }
const ll vmax = 510;
ll cnt[vmax][vmax];
bool vis[vmax][vmax];
bool rw[vmax][vmax];
void paint(ll x, ll y) {
  if (vis[x][y]) return;
  vis[x][y] = true;
  pi ls[3]{pi(x + 1, y), pi(x - 1, y),
           x % 2 == 0 ? pi(x + 1, y - 1) : pi(x - 1, y + 1)};
  for (auto z : ls) {
    ll i, j;
    tie(i, j) = z;
    if (inc(0, i, vmax - 1) && inc(0, j, vmax - 1)) {
      if (++cnt[i][j] == 2) paint(i, j);
    }
  }
}
bool waf[vmax][vmax];
ll deg[vmax][vmax];
vc<pi> tr[vmax][vmax];
void dfs(ll x, ll y, ll px, ll py) {
  if (waf[x][y]) {
    cout << "SICK" << endl;
    exit(0);
  }
  waf[x][y] = true;
  pi ls[3]{pi(x + 1, y), pi(x - 1, y),
           x % 2 == 0 ? pi(x + 1, y - 1) : pi(x - 1, y + 1)};
  for (auto z : ls) {
    ll i, j;
    tie(i, j) = z;
    if (inc(0, i, vmax - 1) && inc(0, j, vmax - 1) && vis[i][j]) {
      deg[x][y]++;
      tr[x][y].emplace_back(i, j);
      if (pi(px, py) != pi(i, j)) {
        dfs(i, j, x, y);
      }
    }
  }
}
void slv() {
  ll n;
  cin >> n;
  for (ll i = ll(0); i < ll(n); i++) {
    ll x, y;
    cin >> x >> y;
    paint(x, y);
    rw[x][y] = true;
  }
  ll ans = -n;
  for (ll i = ll(0); i < ll(vmax); i++)
    for (ll j = ll(0); j < ll(vmax); j++)
      if (vis[i][j] && !waf[i][j]) {
        dfs(i, j, -1, -1);
      }
  for (ll x = ll(0); x < ll(vmax); x++)
    for (ll y = ll(0); y < ll(vmax); y++)
      if (vis[x][y]) ans += 2;
  void(0);
  for (ll x = ll(0); x < ll(vmax); x++)
    for (ll y = ll(0); y < ll(vmax); y++)
      if (deg[x][y] == 3 && !rw[x][y]) {
        {
          bool ok = true, has2 = false;
          for (auto [i, j] : tr[x][y]) {
            ok &= rw[i][j];
            if (deg[i][j] >= 2) has2 = true;
          }
          if (ok && has2) {
            ans += 2;
          }
        }
        {
          bool ok = true, has3 = false;
          for (auto [i, j] : tr[x][y]) {
            if (deg[i][j] <= 2) {
              ok &= rw[i][j];
            } else {
              has3 = true;
              if (!rw[i][j] && pi(x, y) < pi(i, j)) {
                for (auto [k, l] : tr[i][j]) {
                  if (pi(k, l) != pi(x, y)) {
                    ok &= rw[k][l];
                  }
                }
              } else {
                ok = false;
              }
            }
          }
          if (ok && has3) {
            void(0);
            ans += 2;
          }
        }
      }
  cout << "RECOVERED" << endl;
  print(ans);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  slv();
}
