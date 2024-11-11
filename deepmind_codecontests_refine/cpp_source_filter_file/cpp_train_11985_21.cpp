#include <bits/stdc++.h>
using namespace std;
long long Tree[1000005];
vector<int> g[300005];
vector<pair<int, int> > q[300005];
long long ans[300005];
bool vis[300005];
void Update(int node, int l, int r, int i, int j, int x) {
  if (l >= i && r <= j) {
    Tree[node] += x;
    return;
  }
  int mid = (l + r) >> 1;
  int lc = node << 1, rc = lc | 1;
  if (i <= mid && j >= l) Update(lc, l, mid, i, j, x);
  if (i <= r && j > mid) Update(rc, mid + 1, r, i, j, x);
}
long long query(int node, int l, int r, int idx, long long x) {
  if (l == r) return x + Tree[node];
  int mid = (l + r) >> 1;
  int lc = node << 1, rc = lc | 1;
  if (idx <= mid)
    return query(lc, l, mid, idx, x + Tree[node]);
  else
    return query(rc, mid + 1, r, idx, x + Tree[node]);
}
void dfs(int u, int h) {
  vis[u] = 1;
  for (auto p : q[u]) {
    int dis = min(h + p.second, 300001);
    Update(1, 1, 300002, h, dis, p.first);
  }
  ans[u] = query(1, 1, 300002, h, 0);
  for (int v : g[u]) {
    if (vis[v]) continue;
    dfs(v, h + 1);
  }
  for (auto p : q[u]) {
    int dis = (h + p.second, 300001);
    Update(1, 1, 300002, h, dis, -p.first);
  }
}
int main(void) {
  int node;
  scanf("%d", &node);
  for (int i = 1; i < node; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int qry;
  scanf("%d", &qry);
  for (int i = 1; i <= qry; i++) {
    int v, d, x;
    scanf("%d%d%d", &v, &d, &x);
    q[v].push_back({x, d});
  }
  dfs(1, 1);
  for (int i = 1; i <= node; i++) printf("%lld ", ans[i]);
  return 0;
}
