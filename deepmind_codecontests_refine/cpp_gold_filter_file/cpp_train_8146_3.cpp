#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4,avx,avx2,fma")
using namespace std;
const string nl = "\n";
using ll = int64_t;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using str = string;
using vpii = vector<pii>;
using vpll = vector<pll>;
template <class T>
inline bool ckmin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool ckmax(T& a, T b) {
  return b > a ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
str to_string(char c) { return str(1, c); }
str to_string(bool b) { return b ? "true" : "false"; }
str to_string(const char* second) { return (str)second; }
str to_string(str second) { return second; }
template <class A>
str to_string(complex<A> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
str to_string(vector<bool> v) {
  str res = "{";
  for (int i = 0; i < (int)v.size(); i++) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
str to_string(bitset<SZ> b) {
  str res = "";
  for (int i = 0; i < b.size(); i++) res += char('0' + b[i]);
  return res;
}
template <class A, class B>
str to_string(pair<A, B> p);
template <class T>
str to_string(T v) {
  bool fst = 1;
  str res = "{";
  for (const auto& x : v) {
    if (!fst) res += ", ";
    fst = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
str to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
typedef long long node;
struct segtree {
  int size;
  vector<node> vals;
  node ne = 0;
  node comb(node a, node b) { return a + b; }
  void init(int n) {
    size = 1;
    while (size < n) {
      size *= 2;
    }
    vals.assign(2 * size, ne);
  }
  void build(vector<node>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < a.size()) {
        vals[x] = a[lx];
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    vals[x] = comb(vals[2 * x + 1], vals[2 * x + 2]);
  }
  void build(vector<node>& a) { build(a, 0, 0, size); }
  void update(int i, node v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      vals[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m)
      update(i, v, 2 * x + 1, lx, m);
    else
      update(i, v, 2 * x + 2, m, rx);
    vals[x] = comb(vals[2 * x + 1], vals[2 * x + 2]);
  }
  void update(int i, node v) { update(i, v, 0, 0, size); }
  node query(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return ne;
    if (lx >= l && rx <= r) {
      return vals[x];
    }
    int m = (lx + rx) / 2;
    node s1 = query(l, r, 2 * x + 1, lx, m);
    node s2 = query(l, r, 2 * x + 2, m, rx);
    return comb(s1, s2);
  }
  node query(int l, int r) { return query(l, r, 0, 0, size); }
} st;
bool cmp(array<int, 3> a, array<int, 3> b) {
  if (a[0] == b[0]) {
    return a[2] < b[2];
  }
  return a[0] > b[0];
}
const int mxN = 1e5 + 10;
int n, m;
ll ans = 1;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  st.init((int)1e6 + 5);
  vector<array<int, 3>> pq;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int y, lx, rx;
    cin >> y >> lx >> rx;
    pq.push_back({lx, y, -69});
    pq.push_back({rx, y, 4200000});
    if (lx == 0 && rx == (int)1e6) ans++;
  }
  for (int i = 0; i < m; i++) {
    int x, ly, ry;
    cin >> x >> ly >> ry;
    if (ly == 0 && ry == (int)1e6) {
      ans++;
    }
    pq.push_back({x, ly, ry});
  }
  0;
  sort(pq.begin(), pq.end(), [](array<int, 3> a, array<int, 3> b) {
    if (a[0] == b[0]) return a[2] < b[2];
    return a[0] < b[0];
  });
  reverse(pq.begin(), pq.end());
  while (!pq.empty()) {
    array<int, 3> x = pq.back();
    pq.pop_back();
    if (x[2] == -69) {
      st.update(x[1], 1);
    } else if (x[2] == 4200000) {
      st.update(x[1], 0);
    } else {
      ans += st.query(x[1], x[2] + 1);
    }
    0;
  }
  cout << ans << nl;
}
