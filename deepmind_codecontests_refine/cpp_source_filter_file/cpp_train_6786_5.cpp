#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using std::max;
using std::min;
using std::pair;
using std::string;
using std::vector;
using ll = long long;
const ll INF = 1e18;
vector<pair<ll, ll>> tr;
vector<ll> buf;
void push(ll v) {
  if (buf[v] == 0) return;
  buf[v * 2 + 1] += buf[v];
  buf[v * 2 + 2] += buf[v];
  tr[v * 2 + 1].first += buf[v];
  tr[v * 2 + 2].first += buf[v];
  buf[v] = 0;
}
void add(ll v, ll vl, ll vr, ll l, ll r, ll x) {
  if (vr <= l || r <= vl) return;
  if (l <= vl && vr <= r) {
    tr[v].first += x;
    buf[v] += x;
    return;
  }
  ll m = (vl + vr) / 2;
  push(v);
  add(v * 2 + 1, vl, m, l, r, x);
  add(v * 2 + 2, m, vr, l, r, x);
  tr[v] = std::max(tr[v * 2 + 1], tr[v * 2 + 2]);
}
pair<ll, ll> get(ll v, ll vl, ll vr, ll l, ll r) {
  if (vr <= l || r <= vl) return {-INF, -INF};
  if (l <= vl && vr <= r) return tr[v];
  push(v);
  ll m = (vl + vr) / 2;
  return std::max(get(v * 2 + 1, vl, m, l, r), get(v * 2 + 2, m, vr, l, r));
}
void build(ll v, ll vl, ll vr) {
  tr[v].second = vl;
  if (vr - vl == 1) return;
  ll m = (vl + vr) / 2;
  build(v * 2 + 1, vl, m);
  build(v * 2 + 2, m, vr);
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << std::fixed << std::setprecision(0);
  ll n;
  cin >> n;
  vector<pair<pair<ll, ll>, ll>> segs(n);
  vector<ll> i2p;
  for (auto &seg : segs) {
    cin >> seg.first.first >> seg.first.second >> seg.second;
    if (seg.first.first > seg.first.second)
      std::swap(seg.first.first, seg.first.second);
    i2p.push_back(seg.first.first);
    i2p.push_back(seg.first.second);
  }
  std::sort(i2p.begin(), i2p.end());
  i2p.resize(std::unique(i2p.begin(), i2p.end()) - i2p.begin());
  ll m = i2p.size();
  std::map<ll, ll> p2i;
  for (ll i = 0; i < m; ++i) p2i[i2p[i]] = i;
  std::sort(segs.begin(), segs.end());
  tr.resize(4 * m);
  buf.resize(4 * m);
  build(0, 0, m);
  for (ll i = 0; i < m; ++i) add(0, 0, m, i, i + 1, -i2p[i]);
  pair<ll, pair<ll, ll>> ans = {-INF, {0, 0}};
  for (ll i = n - 1; i >= 0; --i) {
    auto seg = segs[i];
    ll l, r, c;
    std::tie(l, r) = seg.first;
    c = seg.second;
    l = p2i[l];
    r = p2i[r];
    add(0, 0, m, r, m, c);
    std::tie(c, r) = get(0, 0, m, l, m);
    if (i != 0 && segs[i - 1].first.first == l) continue;
    ans = max(ans, std::make_pair(c + i2p[l], std::make_pair(l, r)));
  }
  if (ans.first < 0) {
    cout << 0 << '\n' << 2e9 << ' ' << 2e9 << ' ' << 2e9 << ' ' << 2e9;
    return 0;
  }
  cout << ans.first << '\n'
       << i2p[ans.second.first] << ' ' << i2p[ans.second.first] << ' '
       << i2p[ans.second.second] << ' ' << i2p[ans.second.second];
  return 0;
}
