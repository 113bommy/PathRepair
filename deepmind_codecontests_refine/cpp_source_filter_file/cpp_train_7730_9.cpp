#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
const long long N = (long long)3e5 + 7;
long long n, m, k, verts[N], c[N], w[N], combo[N], sol[N], con[N];
vector<pair<long long, long long>> g[N], g2[N];
map<pair<long long, long long>, long long> tx;
long long dep[N];
long long mndep[N];
set<pair<long long, long long>> bri;
set<pair<long long, long long>> be;
set<pair<long long, long long>> good;
void dfs_first(long long a, long long par) {
  mndep[a] = dep[a];
  for (auto &it : g[a]) {
    long long b = it.first;
    if (dep[b] == -1) {
      good.insert({a, b});
      dep[b] = 1 + dep[a];
      dfs_first(b, a);
      mndep[a] = min(mndep[a], mndep[b]);
      continue;
    }
    if (dep[b] < dep[a] - 1) {
      be.insert({b, a});
      be.insert({a, b});
      mndep[a] = min(mndep[a], dep[b]);
    }
  }
}
long long ct[N], cnt;
void build(long long a) {
  ct[a] = n;
  for (auto &it : g[a]) {
    long long b = it.first;
    if (bri.count({a, b})) return;
    if (ct[b] == 0) build(b);
  }
}
long long dp[N], u[N];
long long cntt = 0;
bool p2(long long x) {
  long long y = log2(x);
  return ((1 << y) == x);
}
bool vivi[N];
void dfs(long long a) {
  vivi[a] = 1;
  cntt++;
  u[a] = con[a];
  dp[a] = combo[a];
  for (auto &it : g[a]) {
    long long b = it.first;
    if (vivi[b] == 0) {
      dfs(b);
      long long tax = it.second;
      u[a] += u[b];
      if (u[b] == 0 || u[b] == k)
        dp[a] += dp[b];
      else
        dp[a] += max(0LL, dp[b] - tax);
    }
  }
}
void swp(long long a, long long b) {
  u[a] -= u[b];
  long long tax = tx[{a, b}];
  if (u[b] == 0 || u[b] == k)
    dp[a] -= dp[b];
  else
    dp[a] -= max(0LL, dp[b] - tax);
  u[b] += u[a];
  if (u[a] == 0 || u[a] == k)
    dp[b] += dp[a];
  else
    dp[b] += max(0LL, dp[a] - tax);
}
bool got[N];
void reb(long long a) {
  for (auto &it : g[a]) {
    long long b = it.first;
    if (got[b]) continue;
    long long u_a = u[a], u_b = u[b], dp_a = dp[a], dp_b = dp[b];
    swp(a, b);
    got[b] = 1;
    sol[b] = dp[b];
    reb(b);
    u[a] = u_a;
    u[b] = u_b;
    dp[a] = dp_a;
    dp[b] = dp_b;
  }
}
void get(long long a) {
  dfs(a);
  sol[a] = dp[a];
  got[a] = 1;
  reb(a);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (long long i = 1; i <= k; i++) cin >> verts[i];
  for (long long i = 1; i <= n; i++) cin >> c[i];
  for (long long i = 1; i <= m; i++) cin >> w[i];
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    g[x].push_back({y, w[i]});
    g[y].push_back({x, w[i]});
  }
  for (long long i = 1; i <= n; i++) {
    dep[i] = -1;
  }
  dep[1] = 1;
  dfs_first(1, -1);
  for (long long i = 1; i <= n; i++) {
    if (dep[i] == -1) {
      cout << "e dep\n";
      exit(0);
    }
  }
  long long cerpinsky = 0;
  for (long long i = 1; i <= n; i++) {
    for (auto &it : g[i]) {
      long long j = it.first;
      if (be.count({i, j})) continue;
      if (!good.count({i, j})) continue;
      if (dep[i] < mndep[j]) {
        bri.insert({i, j});
        bri.insert({j, i});
        cerpinsky++;
      }
    }
  }
  cnt = n;
  n = 0;
  for (long long i = 1; i <= cnt; i++) {
    if (ct[i] == 0) {
      n++;
      build(i);
    }
  }
  set<pair<long long, long long>> tet;
  long long edges = 0;
  for (long long i = 1; i <= cnt; i++) {
    combo[ct[i]] += c[i];
    for (auto &it : g[i]) {
      long long j = it.first;
      if (i > j) continue;
      if (!bri.count({i, j})) {
        continue;
      }
      edges++;
      g2[ct[i]].push_back({ct[j], it.second});
      g2[ct[j]].push_back({ct[i], it.second});
    }
  }
  if ((long long)bri.size() % 2 || (long long)bri.size() / 2 != n - 1 ||
      edges != n - 1) {
    cout << n << "\n";
    cout << edges << "\n";
    cout << (long long)bri.size() << " " << (long long)bri.size() / 2 << "\n";
    cout << cerpinsky << "\n";
    return 0;
  }
  for (long long i = 1; i <= k; i++) con[ct[verts[i]]]++;
  for (long long i = 1; i <= n; i++) g[i] = g2[i];
  for (long long i = 1; i <= n; i++) {
    for (auto &it : g[i]) {
      long long j = it.first, tax = it.second;
      tx[{i, j}] = tx[{j, i}] = tax;
    }
  }
  get(1);
  for (long long i = 1; i <= cnt; i++) {
    cout << sol[ct[i]] << " ";
  }
  cout << "\n";
  return 0;
}
