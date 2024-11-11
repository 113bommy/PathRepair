#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
const long long INF = 8e18;
const long long MOD = 1e9 + 7;
int n, m, c, C[MAXN];
vector<pair<int, int>> adj[MAXN], adj_r[MAXN];
vector<pair<pair<int, int>, int>> edges;
vector<int> T[MAXN];
stack<int> st;
bool vis[MAXN];
long long dp[MAXN], val[MAXN];
void dfs(int v) {
  if (vis[v]) return;
  vis[v] = true;
  for (pair<int, int> e : adj[v]) dfs(e.first);
  st.push(v);
}
void sfd(int v) {
  C[v] = c;
  T[c].push_back(v);
  for (pair<int, int> e : adj_r[v])
    if (C[e.first] == 0) sfd(e.first);
}
long long Cost(long long e) {
  long long L = 0, R = 1e5;
  while (L < R) {
    long long mid = (L + R + 1) >> 1;
    if (mid * (mid + 1) / 2 > e)
      R = mid - 1;
    else
      L = mid;
  }
  if (L == 0) return 0;
  return (L + 1) * e - L * (L + 1) * (L - 1) / 6;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj_r[v].push_back({u, w});
    edges.push_back({{u, v}, w});
  }
  for (int i = 1; i <= n; i++) dfs(i);
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    if (C[v] == 0) c++, sfd(v);
  }
  for (auto e : edges)
    if (C[e.first.first] == C[e.first.second])
      val[C[e.first.first]] += Cost(e.second);
  for (int i = c; i > 0; i--) {
    for (int v : T[i]) {
      for (pair<int, int> e : adj[v]) {
        int u = e.first, w = e.second;
        if (C[u] == i) continue;
        dp[i] = max(dp[i], dp[C[u]] + w);
      }
    }
    dp[i] += val[i];
  }
  int s;
  cin >> s;
  cout << dp[C[s]] << '\n';
  return 0;
}
