#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
vector<pair<int, int>> adj[N], _adj[N];
long long sz[N];
int val[N];
int tt[N];
void dfs(int u, int p) {
  tt[u] = 1;
  for (auto it : adj[u]) {
    if (it.first == p) continue;
    _adj[u].push_back(it);
    val[it.first] = it.second;
    dfs(it.first, u);
    tt[u] += tt[it.first];
    sz[u] += sz[it.first] + it.second;
  }
}
long long tot, cnt;
int vis = 0, n;
void DFS(int u, int p) {
  for (auto it : _adj[u]) {
    cnt += it.second;
    tot += cnt;
    vis++;
    DFS(it.first, u);
    if (vis != n - 1) cnt += it.second;
  }
}
bool cmp(pair<int, int> u, pair<int, int> v) {
  return sz[u.first] * tt[v.first] < sz[v.first] * tt[u.first];
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) sz[i] += val[i];
  for (int i = 0; i < N; i++) sort(_adj[i].begin(), _adj[i].end(), cmp);
  DFS(1, 0);
  cout << setprecision(10) << 1.0 * tot / (n - 1) << endl;
  return 0;
}
