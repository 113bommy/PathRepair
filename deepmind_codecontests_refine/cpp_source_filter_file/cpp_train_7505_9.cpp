#include <bits/stdc++.h>
using namespace std;
int n, q, k, x, y, ed[200005], st[200005], lca[200005][25], dep[200005], cnt,
    flag;
vector<int> g[200005];
map<pair<int, int>, int> vis;
struct node {
  int sum, add;
} tree[800005];
void dfs(int now, int pre) {
  st[now] = ++cnt;
  dep[now] = dep[pre] + 1;
  lca[now][0] = pre;
  for (auto v : g[now])
    if (v != pre) dfs(v, now);
  ed[now] = cnt;
}
void push_up(int pos, int l, int r) {
  if (tree[pos].add)
    tree[pos].sum = r - l + 1;
  else if (l == r)
    tree[pos].sum = 0;
  else
    tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
}
void UPD(int pos, int l, int r, int ql, int qr) {
  if (l > r) return;
  if (ql <= l && r <= qr) {
    tree[pos].add += flag;
    push_up(pos, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) UPD(pos << 1, l, mid, ql, qr);
  if (mid < qr) UPD(pos << 1 | 1, mid + 1, r, ql, qr);
  push_up(pos, l, r);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++)
    cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
  dfs(1, 0);
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= n; j++) lca[j][i] = lca[lca[j][i - 1]][i - 1];
  while (q--) {
    cin >> x >> y;
    if (vis.count({x, y}) || vis.count({y, x})) {
      if (vis[{x, y}])
        flag = -1;
      else
        flag = 1;
      vis[{x, y}] = vis[{y, x}] = (vis[{x, y}] == 1) ? -1 : 1;
    } else
      vis[{x, y}] = vis[{y, x}] = 1, flag = 1;
    if (st[x] > st[y]) swap(x, y);
    if (ed[x] >= ed[y]) {
      int tp = y;
      for (int j = 20; j >= 0; j--)
        if (dep[x] < dep[lca[tp][j]]) tp = lca[tp][j];
      UPD(1, 1, n, st[tp], st[y] - 1);
      UPD(1, 1, n, ed[y] + 1, ed[tp]);
    } else {
      UPD(1, 1, n, 1, st[x] - 1);
      UPD(1, 1, n, ed[x] + 1, st[y] - 1);
      UPD(1, 1, n, ed[y] + 1, n);
    }
    cout << n - tree[1].sum << '\n';
  }
  return 0;
}
