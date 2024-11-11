#include <bits/stdc++.h>
using namespace std;
const int mxn = 3e5 + 5;
const long long mod = 998244353;
long long dis[mxn];
bool vis[mxn];
struct data {
  int u;
  long long w;
  int idx;
};
vector<data> adj[mxn];
data par[mxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    scanf("%d%d%lld", &u, &v, &w);
    adj[u].push_back({v, w, i});
    adj[v].push_back({u, w, i});
  }
  int src;
  scanf("%d", &src);
  memset(dis, 63, sizeof dis);
  priority_queue<pair<long long, long long> > pq;
  pq.push({0, src});
  dis[src] = 0;
  while (!pq.empty()) {
    pair<long long, long long> top = pq.top();
    pq.pop();
    int u = top.second;
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto it : adj[u]) {
      int v = it.u;
      long long w = it.w;
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        par[v] = {u, w, it.idx};
        pq.push({-dis[v], v});
      } else if (dis[u] + w == dis[v] && w < par[v].w) {
        par[v] = {v, w, it.idx};
      }
    }
  }
  vector<int> ans;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i == src) continue;
    ans.push_back(par[i].idx);
    sum += par[i].w;
  }
  sort(ans.begin(), ans.end());
  cout << sum << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  return 0;
}
