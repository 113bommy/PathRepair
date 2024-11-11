#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1 << 20;
const ll inf = 1ll << 40;
ll n, m, p;
ll ca[maxn], cb[maxn];
void init() {
  fill(ca, ca + maxn, inf);
  fill(cb, cb + maxn, inf);
}
vector<pair<ll, ll>> mon[maxn];
struct sgt {
  ll v[maxn << 1], tag[maxn << 1];
  void init() {
    for (ll i = 0; i < maxn; ++i) v[i + maxn] = -cb[i];
    for (ll i = maxn - 1; i > 0; --i) update(i);
  }
  void add_node(ll i, ll val) { v[i] += val, tag[i] += val; }
  void update(ll i) {
    if (i < maxn) {
      push(i);
      v[i] = max(v[i << 1], v[i << 1 | 1]);
    }
  }
  void push(ll i) {
    if (i < maxn && tag[i]) {
      add_node(i << 1, tag[i]);
      add_node(i << 1 | 1, tag[i]);
      tag[i] = 0;
    }
  }
  void add(ll l, ll r, ll val) {
    l += maxn, r += maxn;
    ll sl = l, sr = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) add_node(l++, val);
      if (r & 1) add_node(--r, val);
    }
    while (sl) {
      update(sl);
      update(sr);
      sl >>= 1, sr >>= 1;
    }
  }
  ll query() { return v[1]; }
} tree;
ll get_ans() {
  tree.init();
  ll res = -(ca[1] + cb[1]);
  for (ll i = 1; i + 1 < maxn; ++i) {
    for (auto [xb, coin] : mon[i]) tree.add(xb, maxn, coin);
    res = max(res, -ca[i + 1] + tree.query());
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  init();
  cin >> n >> m >> p;
  for (ll i = 1, a, c; i <= n; ++i) {
    cin >> a >> c;
    ca[a] = min(ca[a], c);
  }
  for (ll i = 1, b, c; i <= m; ++i) {
    cin >> b >> c;
    cb[b] = min(cb[b], c);
  }
  for (ll i = maxn - 2; i >= 0; --i) {
    ca[i] = min(ca[i + 1], ca[i]);
    cb[i] = min(cb[i + 1], cb[i]);
  }
  for (ll i = 0, a, b, c; i < p; ++i) {
    cin >> a >> b >> c;
    mon[a].emplace_back(b, c);
  }
  cout << get_ans() << '\n';
}
