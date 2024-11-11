#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1001002003004005006ll;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename Monoid>
struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;
  int sz;
  vector<Monoid> seg;
  const F f;
  const Monoid gen;
  SegmentTree(int n, const F f, const Monoid &gen) : f(f), gen(gen) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, gen);
  }
  void set(int k, const Monoid &x) { seg[k + sz] = x; }
  void build() {
    for (int k = sz - 1; k > 0; k--) seg[k] = f(seg[2 * k], seg[2 * k + 1]);
  }
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) seg[k] = f(seg[2 * k], seg[2 * k + 1]);
  }
  Monoid query(int a, int b) {
    Monoid L = gen, R = gen;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
  Monoid operator[](const int &k) const { return seg[k + sz]; }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  set<ll> ins;
  for (int i = 0; i < (n); i++) {
    cin >> v[i].second >> v[i].first;
    ins.insert(v[i].first);
  }
  sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first != b.first)
      return a.first > b.first;
    else
      return a.second < b.second;
  });
  int m = (int)ins.size();
  map<ll, int> id;
  int tp = 0;
  for (auto &x : ins) id[x] = tp++;
  auto segfunc = [](pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
      a.second += b.second;
      a.second %= 1000000007;
      return a;
    } else {
      return (a < b ? a : b);
    }
  };
  SegmentTree<pair<ll, ll>> seg(m, segfunc, make_pair(LINF, 0));
  seg.build();
  for (int i = 0; i < (n); i++) {
    auto ite = ins.lower_bound(v[i].second);
    int idx = id[v[i].first];
    if (ite == ins.end()) {
      ll cost = v[i].first;
      auto p = seg[idx];
      if (p.first > cost)
        seg.update(idx, make_pair(cost, 1));
      else if (p.first == cost)
        seg.update(idx, make_pair(p.first, p.second + 1));
    } else {
      auto minip = seg.query(id[*ite], m);
      auto p = seg[idx];
      if (p.first > minip.first - (v[i].second - v[i].first)) {
        seg.update(idx, make_pair(minip.first - (v[i].second - v[i].first),
                                  minip.second));
      } else if (p.first == minip.first - (v[i].second - v[i].first)) {
        seg.update(idx,
                   make_pair(p.first, (minip.second + p.second) % 1000000007));
      }
    }
  }
  cout << seg.query(0, m).second % 1000000007 << endl;
  return 0;
}
