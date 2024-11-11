#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, logn = 19, mod = 998244353;
int a[N], up[N][logn], d[N];
vector<int> adj[N];
void dfs1(int v, int p = -1) {
  for (int u : adj[v]) {
    if (u != p) {
      up[u][0] = v;
      for (int i = (1); ((1) > 0 ? i < (logn - 1) : i > (logn - 1)); i += (1))
        up[u][i] = up[up[u][i - 1]][i - 1];
      d[u] = d[v] + 1;
      dfs1(u, v);
    }
  }
}
int lca(int v, int u) {
  if (d[v] < d[u]) swap(u, v);
  for (int i = (logn - 1); ((-1) > 0 ? i < (-1) : i > (-1)); i += (-1)) {
    if (d[up[v][i]] >= d[u]) v = up[v][i];
  }
  if (v == u) return v;
  for (int i = (logn - 1); ((-1) > 0 ? i < (-1) : i > (-1)); i += (-1)) {
    if (up[v][i] != up[u][i]) {
      v = up[v][i], u = up[u][i];
    }
  }
  return up[v][0];
}
int l[N], dp[N][2];
int dfs2(int v, int p = -1) {
  vector<pair<int, int> > cur;
  for (int u : adj[v]) {
    if (u != p) {
      int c = dfs2(u, v);
      if (c != 0) cur.emplace_back(c, u);
    }
  }
  set<int> tmp;
  for (int i = (0); ((1) > 0 ? i < ((int)cur.size()) : i > ((int)cur.size()));
       i += (1)) {
    if (cur[i].first > 0) tmp.insert(cur[i].first);
  }
  vector<int> vals(tmp.begin(), tmp.end());
  if ((int)vals.size() > 1) {
    cout << 0 << '\n';
    exit(0);
  }
  if (a[v] != 0 && !vals.empty() && vals[0] != a[v]) {
    cout << 0 << '\n';
    exit(0);
  }
  if (a[v] == 0 && cur.empty()) return 0;
  if (a[v] == 0 && vals.empty()) {
    vector<int> pr(1, 1), su(1, 1);
    for (int i = (0); ((1) > 0 ? i < ((int)cur.size()) : i > ((int)cur.size()));
         i += (1)) {
      int t = (long long)((dp[cur[i].second][0] + dp[cur[i].second][1]) % mod) *
              pr.back() % mod;
      pr.push_back(t);
    }
    for (int i = ((int)cur.size() - 1); ((-1) > 0 ? i < (-1) : i > (-1));
         i += (-1)) {
      int t = (long long)((dp[cur[i].second][0] + dp[cur[i].second][1]) % mod) *
              su.back() % mod;
      su.push_back(t);
    }
    reverse(su.begin(), su.end());
    dp[v][1] = 0;
    for (int i = (0); ((1) > 0 ? i < ((int)cur.size()) : i > ((int)cur.size()));
         i += (1)) {
      int t = (long long)((long long)pr[i] * su[i + 1] % mod) *
              dp[cur[i].second][1] % mod;
      dp[v][1] = (dp[v][1] + t) % mod;
    }
    dp[v][0] = (dp[v][0] + pr[(int)cur.size()]) % mod;
    return -1;
  }
  dp[v][1] = 1;
  for (auto p : cur) {
    if (p.first == -1) {
      dp[v][1] = (long long)dp[v][1] *
                 ((dp[p.second][0] + dp[p.second][1]) % mod) % mod;
    } else {
      dp[v][1] = (long long)dp[v][1] * dp[p.second][1] % mod;
    }
  }
  if (a[v] == 0) return vals[0];
  return (l[a[v]] == v ? -1 : a[v]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = (0); ((1) > 0 ? i < (n) : i > (n)); i += (1)) cin >> a[i];
  for (int i = (0); ((1) > 0 ? i < (n - 1) : i > (n - 1)); i += (1)) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(0);
  memset(l, -1, sizeof(l));
  for (int i = (0); ((1) > 0 ? i < (n) : i > (n)); i += (1)) {
    if (a[i] != 0) {
      l[a[i]] = (l[a[i]] == -1 ? i : lca(l[a[i]], i));
    }
  }
  for (int i = (1); ((1) > 0 ? i < (k + 1) : i > (k + 1)); i += (1)) {
    if (a[l[i]] != 0 && a[l[i]] != i) {
      cout << 0 << '\n';
      exit(0);
    }
    a[l[i]] = i;
  }
  dfs2(0);
  cout << dp[0][1] << '\n';
}
