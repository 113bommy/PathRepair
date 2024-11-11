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
using pi = pair<int, int>;
using vi = vc<int>;
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
template <int i, class T>
void print_tuple(ostream&, const T&) {}
template <int i, class T, class H, class... Args>
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
void print(t x, int suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(int n, int off = 0) {
  vi v(n);
  for (int i = int(0); i < int(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i], i == int(v.size()) - 1 ? suc : 2);
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
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const int inf = INT_MAX / 2 - 100;
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
int botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
bool inc(int first, int second, int c) {
  return first <= second && second <= c;
}
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
  for (int i = int(0); i < int(int(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
int lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
struct unionfind {
  vi p, s;
  int c;
  unionfind(int n) : p(n, -1), s(n, 1), c(n) {}
  int find(int first) {
    return p[first] == -1 ? first : (p[first] = find(p[first]));
  }
  bool unite(int first, int second) {
    first = find(first);
    second = find(second);
    if (first == second) return false;
    if (s[first] < s[second]) swap(first, second);
    p[second] = first;
    s[first] += s[second];
    c--;
    return true;
  }
  bool same(int first, int second) { return find(first) == find(second); }
  int sz(int first) { return s[find(first)]; }
};
const int S = 20;
int deg[1 << S];
vc<pi> g[1 << S];
bool used[1 << S];
int head[1 << S];
vi res;
void dfs(int v) {
  while (head[v] < int(g[v].size())) {
    int to, idx;
    tie(to, idx) = g[v][head[v]++];
    if (used[idx / 2]) continue;
    used[idx / 2] = 1;
    dfs(to);
    res.push_back(idx);
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vc<pi> es(n);
  for (int i = int(0); i < int(n); i++) {
    int first, second;
    cin >> first >> second;
    es[i] = pi(first, second);
  }
  for (int ans = int(21) - 1; ans >= int(0); ans--) {
    const int m = mask(ans);
    memset(deg, 0, sizeof(deg));
    for (auto e : es) {
      deg[e.first & m]++;
      deg[e.second & m]++;
    }
    bool ok = true;
    for (int i = int(0); i < int(1 << S); i++)
      if (deg[i] % 2) ok = false;
    if (ok) {
      vi vs;
      for (auto e : es) {
        vs.push_back(e.first & m);
        vs.push_back(e.second & m);
      }
      mkuni(vs);
      int s = int(vs.size());
      unionfind uf(s);
      for (auto e : es) {
        int first = lwb(vs, e.first & m);
        int second = lwb(vs, e.second & m);
        uf.unite(first, second);
      }
      if (uf.c == 1) {
        for (int i = int(0); i < int(n); i++) {
          int first = lwb(vs, es[i].first & m);
          int second = lwb(vs, es[i].second & m);
          g[first].emplace_back(second, i * 2);
          g[second].emplace_back(first, i * 2 + 1);
        }
        dfs(0);
        reverse(res.begin(), res.end());
        assert(int(res.size()) == n);
        print(ans);
        for (int i = int(0); i < int(n); i++) {
          int x = res[i];
          print(x / 2 + x % 2 + 1, 2);
          print(x / 2 + (1 - x % 2) + 1, i == n - 1 ? 1 : 2);
        }
        return 0;
      }
    }
  }
  assert(0);
}
