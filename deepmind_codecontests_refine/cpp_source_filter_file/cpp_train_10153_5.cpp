#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
long long arr[100009], path[100009], ans, dp[100009];
vector<int> adj[100009];
long long cep[100009], sag[100009];
pair<long long, long long> pre[100009], suf[100009];
void cmp(pair<long long, long long>& x, int y) {
  if (x.first < y) {
    x.second = x.first;
    x.first = y;
  } else if (x.second < y)
    x.second = y;
}
void dfs(int nd, int pr) {
  pair<long long, long long> mx = make_pair(0, 0);
  pair<long long, long long> res = make_pair(0, 0);
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr) continue;
    dfs(to, nd);
    umax(dp[nd], dp[to]);
    umax(path[nd], path[to]);
    cmp(mx, path[to]);
    cmp(res, dp[to]);
  }
  umax(ans, res.first + res.second);
  umax(dp[nd], arr[nd] + mx.first + mx.second);
  path[nd] += arr[nd];
}
void dfs1(int nd, int pr, long long DP, long long PATH) {
  long long now = 0;
  pair<long long, long long> won = make_pair(0, 0);
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr) continue;
    cep[to] = now;
    pre[to] = won;
    umax(now, dp[to]);
    cmp(won, path[to]);
  }
  now = 0;
  won = make_pair(0, 0);
  for (int i = int(adj[nd].size()) - 1; i >= 0; i--) {
    int to = adj[nd][i];
    if (to == pr) continue;
    sag[to] = now;
    suf[to] = won;
    umax(now, dp[to]);
    cmp(won, path[to]);
  }
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr) continue;
    pair<long long, pair<long long, long long> > new_DP;
    new_DP = make_pair(max(DP, max(cep[to], sag[to])), make_pair(0, 0));
    cmp(new_DP.second, PATH);
    cmp(new_DP.second, pre[to].first);
    cmp(new_DP.second, pre[to].second);
    cmp(new_DP.second, suf[to].first);
    cmp(new_DP.second, suf[to].second);
    cmp(new_DP.second, suf[to].second);
    umax(new_DP.first, new_DP.second.first + new_DP.second.second + arr[nd]);
    umax(ans, dp[to] + new_DP.first);
    dfs1(to, nd, new_DP.first, new_DP.second.first + arr[nd]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", arr + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  umax(ans, dp[1]);
  dfs1(1, -1, 0, 0);
  printf("%lld\n", ans);
  return 0;
}
