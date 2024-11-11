#include <bits/stdc++.h>
using namespace std;
long long const M = 2e5 + 10, M2 = 1e7 + 10, mod = 1e9 + 7, inf = 1e18 + 10;
long long d[M], d2[M], n, m, k, s1, s2, f, a[M], b[M], x[M], y[M], l[M], r[M],
    c[M];
bool vis[M], mark[M];
vector<long long> adj[M], edg[M];
void relax() {
  for (long long i = 1; i <= n; i++) edg[i].clear();
  for (long long i = 1; i <= m; i++) {
    edg[a[i]].push_back(c[i]);
  }
  for (long long i = 1; i <= k; i++) {
    if (mark[i])
      edg[x[i]].push_back(r[i]);
    else
      edg[x[i]].push_back(l[i]);
  }
}
void dij(long long s, long long dp[]) {
  for (long long i = 1; i <= n; i++) dp[i] = inf;
  dp[s] = 0;
  set<pair<long long, long long> > st;
  st.insert(make_pair(0, s));
  while (st.size()) {
    pair<long long, long long> now = *st.begin();
    st.erase(now);
    long long v = now.second;
    for (long long i = 0; i < adj[v].size(); i++) {
      long long u = adj[v][i];
      if (dp[u] <= dp[v] + edg[v][i]) continue;
      st.erase(make_pair(dp[u], u));
      dp[u] = dp[v] + edg[v][i];
      st.insert(make_pair(dp[u], u));
    }
  }
}
int32_t main() {
  cin >> n >> m >> k;
  cin >> s1 >> s2 >> f;
  for (long long i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    adj[a[i]].push_back(b[i]);
  }
  for (long long i = 1; i <= k; i++) {
    mark[i] = 0;
    cin >> x[i] >> y[i] >> l[i] >> r[i];
    adj[x[i]].push_back(y[i]);
  }
  relax();
  for (long long i = 1; i <= k + 1; i++) {
    dij(s1, d);
    dij(s2, d2);
    if (i == k + 1) break;
    long long mn = inf * 3, ind = -1;
    for (long long j = 1; j <= k; j++) {
      if (vis[j]) continue;
      long long tmp = d2[x[j]];
      if (d[x[j]] >= d2[x[j]] && tmp < mn) mn = tmp, ind = j;
    }
    if (ind == -1) break;
    vis[ind] = 1;
    long long u = x[ind];
    if (d[u] >= d2[u]) mark[ind] = 1;
    relax();
  }
  bool flag = 0;
  if (d[f] > d2[f]) flag = 1;
  if (!flag) {
    if (d[f] == d2[f])
      cout << "DRAW\n";
    else
      cout << "WIN\n";
    for (long long i = 1; i <= k; i++) {
      if (mark[i])
        cout << r[i] << " ";
      else
        cout << l[i] << " ";
    }
    return 0;
  }
  for (long long i = 1; i <= k; i++) mark[i] = 0, vis[i] = 0;
  relax();
  for (long long i = 1; i <= k + 1; i++) {
    dij(s1, d);
    dij(s2, d2);
    if (i == k + 1) break;
    long long mn = inf * 3, ind;
    for (long long j = 1; j <= k; j++) {
      if (vis[j]) continue;
      long long tmp = d[x[j]] + l[j];
      if (tmp < mn) mn = tmp, ind = j;
    }
    vis[ind] = 1;
    long long u = x[ind];
    if (d[u] > d2[u]) mark[ind] = 1;
    relax();
  }
  if (d[f] > d2[f]) return cout << "LOSE\n", 0;
  cout << "DRAW\n";
  for (long long i = 1; i <= k; i++) {
    if (mark[i])
      cout << r[i] << " ";
    else
      cout << l[i] << " ";
  }
}
