#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, mod = 1e9 + 7;
const long long inf = 1e18 + 10;
long long intersection(pair<long long, long long> p1,
                       pair<long long, long long> p2) {
  long long need = (p2.second - p1.second);
  long long get = (p2.first - p1.first);
  long long ret = need / get;
  if (ret * get < need) {
    ret++;
  }
  return ret;
}
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<pair<long long, pair<long long, long long> > > e;
  vector<pair<long long, long long> > g[n];
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    e.push_back({w, {u, v}});
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  sort(e.begin(), e.end());
  vector<pair<long long, long long> > vec;
  long long dis[n];
  for (auto x : e) {
    for (long long i = 0; i < n; i++) {
      dis[i] = inf;
    }
    dis[0] = 0;
    long long u = x.second.first, v = x.second.second, w = x.first;
    set<pair<long long, long long> > st;
    st.insert({0, 0});
    while (st.size()) {
      auto x = *st.begin();
      st.erase(st.begin());
      long long v = x.second;
      for (auto xx : g[v]) {
        if (xx.second < w && dis[xx.first] > dis[v] + w - xx.second) {
          st.erase({dis[xx.first], xx.first});
          dis[xx.first] = dis[v] + w - xx.second;
          st.insert({dis[xx.first], xx.first});
        }
      }
    }
    long long val = min(dis[u], dis[v]);
    if (val < inf) {
      if (vec.size() > 0 && vec.back().first == w && vec.back().second <= val) {
        continue;
      }
      while (vec.size() > 0 && vec.back().second >= val) {
        vec.pop_back();
      }
      while (vec.size() > 1 &&
             intersection(vec[vec.size() - 1], {w, val}) <=
                 intersection(vec[vec.size() - 2], vec[vec.size() - 1])) {
        vec.pop_back();
      }
      vec.push_back({w, val});
    }
  }
  long long cur = 1;
  long long ans = 0;
  for (long long i = 1; i < vec.size() && cur <= q; i++) {
    long long pt = intersection(vec[i - 1], vec[i]);
    if (pt <= cur) {
      continue;
    }
    pt = min(pt, 1ll * q + 1);
    ans +=
        1ll * (cur + pt - 1) * (pt - cur) / 2 % mod * vec[i - 1].first % mod -
        1ll * vec[i - 1].second * (pt - cur) % mod;
    ans %= mod;
    if (ans < 0) {
      ans += mod;
    }
    cur = pt;
  }
  long long sz = vec.size();
  if (cur <= q) {
    ans += 1ll * (cur + q) * (q - cur + 1) / 2 % mod * vec[sz - 1].first % mod -
           1ll * vec[sz - 1].second * (q - cur + 1) % mod;
    ans %= mod;
    if (ans < 0) {
      ans += mod;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  long long cur = 1;
  while (t--) {
    solve();
  }
  return 0;
}
