#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> gr[200005];
bool flag[200005], vis[200005], block[200005];
int dist[200005], par[200005];
void dfs(int now, int d, int p) {
  if (vis[now]) return;
  vis[now] = true;
  dist[now] = d, par[now] = p;
  for (auto a : gr[now]) dfs(a, d + 1, now);
}
int ans = 0;
bool go(int now, int p) {
  bool ff = false;
  for (auto to : gr[now]) {
    if (to == p || block[to]) continue;
    bool tt = go(to, now);
    if (tt) {
      ff = tt;
      ans += 2;
    }
  }
  ff |= flag[now];
  return ff;
}
int main() {
  int i, j, k, u, v;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 1; i < n; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  k = 0;
  for (i = 1; i <= m; i++) {
    scanf("%d", &j);
    flag[j] = true;
    k = max(k, j);
  }
  dfs(k, 0, -1);
  int mx = -1, node = -1;
  for (i = 1; i <= n; i++) {
    if (flag[i] && dist[i] > mx) {
      mx = dist[i];
      node = i;
    }
  }
  memset(vis, false, sizeof(vis));
  dfs(node, 0, -1);
  mx = -1;
  int node2 = -1;
  for (i = 1; i <= n; i++) {
    if (flag[i] && dist[i] > mx) {
      mx = dist[i];
      node2 = i;
    }
  }
  printf("%d\n", min(node, node2));
  memset(vis, false, sizeof(vis));
  for (i = node2;; i = par[i]) {
    ans++;
    block[i] = true;
    if (i == node) break;
  }
  ans--;
  for (i = 1; i <= n; i++) {
    if (block[i]) go(i, -1);
  }
  cout << ans << endl;
}
