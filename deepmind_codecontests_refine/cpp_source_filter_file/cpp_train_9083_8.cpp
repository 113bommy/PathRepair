#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using ll = long long;
struct sgt {
  vector<int> t;
  int sz = 1;
  sgt(int n) {
    while (sz < n) sz *= 2;
    t.resize(2 * sz);
  }
  void add(int i, int x) {
    i += sz;
    t[i] = x;
    for (i /= 2; i > 0; i /= 2) t[i] = max(t[i * 2], t[i * 2 + 1]);
  }
  int rmq(int l, int r) {
    if (l > r) return 0;
    int i = l + sz, j = r + sz;
    int m = 0;
    while (i <= j) {
      if (i % 2) m = max(m, t[i++]);
      if (!(j % 2)) m = max(m, t[j--]);
      i /= 2;
      j /= 2;
    }
    return m;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<pi> v(n);
  for (auto &x : v) cin >> x.first >> x.second;
  sort(v.begin(), v.end(), [](pi a, pi b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
  });
  vi dp(n), in(n);
  sgt for_dp(2e5 + 10), for_in(2e5 + 10);
  dp[0] = 1;
  in[0] = 0;
  for_dp.add(v[0].second, 1);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    dp[i] = for_dp.rmq(0, v[i].first - 1);
    int k = 0;
    vector<int> ind;
    for (int j = 0; j < n; ++j) {
      if (!(v[j].first >= v[i].first && v[j].second <= v[i].second) || i == j)
        continue;
      ind.push_back(j);
      int p = in[j] + for_in.rmq(0, v[j].first - 1);
      k = max(k, p);
      for_in.add(v[j].second, max(p, for_in.t[v[j].second + for_in.sz]));
    }
    for (auto q : ind) for_in.add(v[q].second, 0);
    in[i] = k + 1;
    if (k) dp[i] += in[i];
    ans = max(ans, dp[i]);
    for_dp.add(v[i].second, max(dp[i], for_dp.t[v[i].second + for_dp.sz]));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
