#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
int m1[N], m2[N], siz[N], par[N], dia[N], join[N];
vector<vector<int>> edg(N);
map<pair<int, int>, long double> dp;
int dfs(int i, int parent) {
  par[i] = parent;
  siz[parent]++;
  int ta;
  for (auto& x : edg[i]) {
    if (par[x]) continue;
    ta = dfs(x, parent);
    if (ta > m1[i])
      m2[i] = m1[i], m1[i] = ta;
    else
      m2[i] = max(m2[i], ta);
  }
  return m1[i] + 1;
}
void dfs2(int i, int parent, int dis) {
  int ta = max({dis, m1[i], m2[i]});
  join[i] = ta;
  dia[par[i]] = max(dia[par[i]], m1[i] + m2[i]);
  for (auto& x : edg[i]) {
    if (x == parent) continue;
    int tb = dis + 1;
    if (m1[x] == m1[i] - 1)
      dfs2(x, i, max(tb, m2[i] + 1));
    else
      dfs2(x, i, max(tb, m1[i] + 1));
  }
}
void solve() {
  int n, m, q, ta, tb;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> ta >> tb;
    edg[ta].push_back(tb);
    edg[tb].push_back(ta);
  }
  for (int i = 1; i <= n; i++) {
    if (par[i]) continue;
    dfs(i, i);
    dfs2(i, -1, 0);
  }
  map<int, vector<long long>> joins, joins_pref;
  for (int i = 1; i <= n; i++) {
    joins[par[i]].push_back(join[i]);
  }
  for (auto& x : joins) {
    sort(x.second.begin(), x.second.end());
    long long ctr = 0;
    for (auto& y : x.second) {
      ctr += y;
      joins_pref[x.first].push_back(ctr);
    }
  }
  while (q--) {
    cin >> ta >> tb;
    ta = par[ta], tb = par[tb];
    if (ta == tb) {
      cout << "-1\n";
      continue;
    }
    if (ta > tb) swap(ta, tb);
    if (dp.count(make_pair(ta, tb))) {
      cout << fixed << setprecision(10) << dp[make_pair(ta, tb)] << "\n";
      continue;
    }
    if (siz[ta] > siz[tb]) swap(ta, tb);
    vector<long long>& x = joins[ta];
    vector<long long>& y = joins[tb];
    int max_dia = max(dia[ta], dia[tb]);
    long double ans = 0;
    for (auto& it : x) {
      int i = upper_bound(y.begin(), y.end(), max_dia - it - 1) - y.begin() - 1;
      ans += joins_pref[tb][joins_pref[tb].size() - 1];
      ans -= (i >= 0) ? joins_pref[tb][i] : 0;
      ans += 1L * (it + 1) * (joins_pref[tb].size() - i - 1);
      ans += 1L * (i + 1) * max_dia;
    }
    ans = ans / (1.0L * x.size() * y.size());
    cout << fixed << setprecision(10) << ans << "\n";
    if (ta > tb) swap(ta, tb);
    dp[make_pair(ta, tb)] = ans;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
