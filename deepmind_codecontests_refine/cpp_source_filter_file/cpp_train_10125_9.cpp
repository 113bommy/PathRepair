#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-all-loops")
#pragma GCC target("sse4.2")
using namespace std;
ifstream in;
ofstream out;
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
long long n;
vector<long long> v;
bool viv = false;
struct Tree {
  int s = 1;
  int n = 0;
  long long my_null = -inf;
  vector<pair<long long, long long> > t;
  vector<pair<long long, long long> > seg;
  inline long long res(long long v1, long long v2) { return max(v1, v2); }
  void cnt_seg() {
    seg.resize(2 * s);
    seg[1] = {0, s};
    for (int i = 1; i < s; i++) {
      int tm = seg[i].first + seg[i].second >> 1;
      seg[2 * i] = {seg[i].first, tm};
      seg[2 * i + 1] = {tm, seg[i].second};
    }
  }
  void build(long long sz) {
    n = sz;
    while (s < n) s <<= 1;
    t.resize(2 * s, {my_null, 0});
    cnt_seg();
  }
  void build(vector<long long> v) {
    n = v.size();
    while (s < n) s <<= 1;
    t.resize(2 * s, {my_null, 0});
    for (int i = 0; i < n; i++) t[s + i] = {v[i], 0};
    for (int i = s - 1; i > 0; i--) upd(i);
    cnt_seg();
  }
  inline void adder(int v, long long val) {
    t[v].first += val;
    t[v].second += val;
  }
  void upd(int v) {
    if (v >= s) return;
    t[v].first = res(t[2 * v].first, t[2 * v + 1].first);
  }
  void push(int v) {
    if (v >= s) return;
    long long psh = t[v].second;
    if (psh == 0) return;
    t[v].second = 0;
    adder(2 * v, psh);
    adder(2 * v + 1, psh);
  }
  long long val(int l, int r, int v, int tl, int tr) {
    if (r <= tl || tr <= l) return my_null;
    push(v);
    if (l <= tl && tr <= r) return t[v].first;
    int tm = tl + tr >> 1;
    long long v1 = val(l, r, 2 * v, tl, tm);
    long long v2 = val(l, r, 2 * v + 1, tm, tr);
    upd(v);
    return res(v1, v2);
  }
  long long val(int l, int r) { return val(l, r + 1, 1, 0, s); }
  long long val(int pl) { return val(pl, pl + 1, 1, 0, s); }
  void add(int l, int r, int v, int tl, int tr, long long val) {
    if (r <= tl || tr <= l) return;
    push(v);
    if (l <= tl && tr <= r) return void(adder(v, val));
    int tm = tl + tr >> 1;
    add(l, r, 2 * v, tl, tm, val);
    add(l, r, 2 * v + 1, tm, tr, val);
    upd(v);
  }
  void add(int v, long long val) {
    v += s;
    t[v].first += val;
    v >>= 1;
    while (v) upd(v), v >>= 1;
  }
  void add(int l, int r, long long t) { add(l, r + 1, 1, 0, s, t); }
  void show() {
    for (long long i = 1; i < 2 * s; i++) {
      cout << '\t' << '{' << t[i].first << ' ' << t[i].second << "} ";
      if ((i & (i + 1)) == 0) cout << endl;
    }
  }
};
Tree t;
void solve() {
  long long k, q;
  cin >> n >> k >> q;
  k--;
  v.resize(500 * kk);
  for (int i = 0; i < v.size(); i++) v[i] = i;
  t.build(v);
  set<pair<long long, long long> > now;
  multiset<long long> s;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    pair<long long, long long> p = {x, y};
    y += abs(x - k);
    if (now.count(p))
      s.erase(s.find(-y)), now.erase(p), t.add(y, -1);
    else
      s.insert(-y), now.insert(p), t.add(y, 1);
    if (s.size() == 0) {
      cout << 0 << '\n';
    } else {
      long long mx = -(*s.begin());
      long long ans = t.val(0, mx);
      ans -= n;
      ans = max(ans, 0ll);
      cout << ans << '\n';
    }
  }
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
