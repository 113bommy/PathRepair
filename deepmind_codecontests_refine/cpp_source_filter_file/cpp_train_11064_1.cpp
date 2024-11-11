#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U first) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U first) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    first(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <class T, class U>
void erase(T& t, const U& u) {
  auto it = t.find(u);
  assert(it != end(t));
  t.erase(u);
}
template <class T>
void re(complex<T>& c);
template <class T, class U>
void re(pair<T, U>& p);
template <class T>
void re(vector<T>& v);
template <class T, size_t SZ>
void re(AR<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(db& d) {
  str t;
  re(t);
  d = stod(t);
}
void re(ld& d) {
  str t;
  re(t);
  d = stold(t);
}
template <class T, class... U>
void re(T& t, U&... u) {
  re(t);
  re(u...);
}
template <class T>
void re(complex<T>& c) {
  T a, b;
  re(a, b);
  c = {a, b};
}
template <class T, class U>
void re(pair<T, U>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& x) {
  for (auto& a : x) re(a);
}
template <class T, size_t SZ>
void re(AR<T, SZ>& x) {
  for (auto& a : x) re(a);
}
str to_string(char c) { return str(1, c); }
str to_string(const char* second) { return (str)second; }
str to_string(str second) { return second; }
str to_string(bool b) { return to_string((int)b); }
template <class T>
str to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
str to_string(vector<bool> v) {
  str res = "{";
  for (int i = (0); i < ((int)(v).size()); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
str to_string(bitset<SZ> b) {
  str res = "";
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p);
template <class T>
str to_string(T v) {
  bool fst = 1;
  str res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p) {
  return to_string(p.first) + " " + to_string(p.second);
}
template <class T>
void pr(T x) {
  cout << to_string(x);
}
template <class T, class... U>
void pr(const T& t, const U&... u) {
  pr(t);
  pr(u...);
}
void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T& t, const U&... u) {
  pr(t);
  if (sizeof...(u)) pr(" ");
  ps(u...);
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
void setIn(str second) { freopen(second.c_str(), "r", stdin); }
void setOut(str second) { freopen(second.c_str(), "w", stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str second = "") {
  unsyncIO();
  if ((int)(second).size()) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
int totFlow;
struct Dinic {
  using F = int;
  struct Edge {
    int to, rev;
    F flo, cap;
  };
  int N;
  V<V<Edge>> adj;
  void init(int _N) {
    N = _N;
    adj.resize(N);
  }
  void ae(int a, int b, F cap, F rcap = 0) {
    assert(min(cap, rcap) >= 0);
    adj[a].push_back({b, (int)(adj[b]).size(), 0, cap});
    adj[b].push_back({a, (int)(adj[a]).size() - 1, 0, rcap});
  }
  vi lev, ptr;
  bool bfs(int second, int t) {
    lev = ptr = vi(N);
    lev[second] = 1;
    queue<int> q({second});
    while ((int)(q).size()) {
      int u = q.front();
      q.pop();
      for (auto& e : adj[u])
        if (e.flo < e.cap && !lev[e.to]) q.push(e.to), lev[e.to] = lev[u] + 1;
    }
    return lev[t];
  }
  F dfs(int v, int t, F flo) {
    if (v == t) return flo;
    for (int& i = ptr[v]; i < (int)(adj[v]).size(); i++) {
      Edge& e = adj[v][i];
      F dif = e.cap - e.flo;
      if (lev[e.to] != lev[v] + 1 || !dif) continue;
      if (F df = dfs(e.to, t, min(flo, dif))) {
        e.flo += df;
        adj[e.to][e.rev].flo -= df;
        return df;
      }
    }
    return 0;
  }
  vb vis;
  F DFS(int x, int v, int t) {
    if (v == t) return 1;
    0;
    if (vis[v]) return 0;
    vis[v] = 1;
    for (auto& e : adj[v])
      if (e.flo > 0) {
        if (e.to == t && v != x) continue;
        if (F df = DFS(x, e.to, t)) {
          e.flo--;
          adj[e.to][e.rev].flo++;
          return 1;
        }
      }
    return 0;
  }
  void maxFlow(int second, int t) {
    while (bfs(second, t))
      while (F df = dfs(second, t, numeric_limits<F>::max())) totFlow += df;
  }
};
int n, a[200][200];
bool ok(int x) { return 1 <= x && x <= 1e9; }
int hsh(int a, int b) { return n * a + b + 2; }
int hsh(pi p) { return hsh(p.first, p.second); }
bool valid(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }
Dinic D;
void delCap(int x) {
  int cnt = 0;
  for (auto& t : D.adj[x])
    if (t.to == 1) {
      if (t.flo == 1) {
        0;
        D.vis = vb(D.N);
        assert(D.DFS(x, 0, 1));
        totFlow--;
      }
      t.cap--;
      cnt++;
    }
  assert(cnt == 1);
}
void addCap(int x) {
  int cnt = 0;
  for (auto& t : D.adj[0])
    if (t.to == x) {
      t.cap++;
      cnt++;
    }
  assert(cnt == 1);
  return;
}
int main() {
  setIO();
  re(n);
  V<pair<int, pi>> todo;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) {
      re(a[i][j]);
      if (ok(a[i][j])) todo.push_back({a[i][j], {i, j}});
    }
  sort(begin(todo), end(todo));
  ll ans = 0;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n - 1); ++j)
      if (ok(a[i][j]) && ok(a[i][j + 1])) ans += abs(a[i][j] - a[i][j + 1]);
  for (int i = (0); i < (n - 1); ++i)
    for (int j = (0); j < (n); ++j)
      if (ok(a[i][j]) && ok(a[i + 1][j])) ans += abs(a[i][j] - a[i + 1][j]);
  D.init(n * n + 2);
  for (int x = (0); x < (n); ++x)
    for (int y = (0); y < (n); ++y)
      if (a[x][y] == 0) {
        for (int z = (0); z < (4); ++z) {
          int X = x + xd[z], Y = y + yd[z];
          if (valid(X, Y) && a[X][Y] != -1) {
            if (make_pair(X, Y) < make_pair(x, y) && a[X][Y] == 0) continue;
            D.ae(hsh(X, Y), hsh(x, y), 1, 1);
          }
        }
      }
  for (int x = (0); x < (n); ++x)
    for (int y = (0); y < (n); ++y)
      if (ok(a[x][y])) {
        D.ae(0, hsh(x, y), 0);
        D.ae(hsh(x, y), 1, 1);
      }
  for (int i = (0); i < ((int)(todo).size() - 1); ++i) {
    delCap(hsh(todo[i].second));
    addCap(hsh(todo[i].second));
    D.maxFlow(0, 1);
    ans += totFlow * (todo[i + 1].first - todo[i].first);
  }
  ps(ans);
}
