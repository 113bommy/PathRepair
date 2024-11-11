#include <bits/stdc++.h>
using namespace std;
int euler[500000], arr[500000], pos[200100], n, x, y, z, idx = 0, xy, xz, yz;
pair<int, int> tree[1500000];
vector<int> graph[200100];
void build(int node, int a, int b) {
  if (a > b) return;
  if (a == b) {
    tree[node] = make_pair(a, arr[a]);
    return;
  }
  build(node * 2 + 1, a, (a + b) / 2);
  build(node * 2 + 2, (a + b) / 2 + 1, b);
  tree[node] = tree[node * 2 + 1].second < tree[node * 2 + 2].second
                   ? tree[node * 2 + 1]
                   : tree[node * 2 + 2];
}
pair<int, int> range(int node, int a, int b, int i, int j) {
  if (b < i || a > j || a > b) return make_pair(-1, 999999);
  if (a >= i && b <= j) return tree[node];
  pair<int, int> q1 = range(node * 2 + 1, a, (a + b) / 2, i, j);
  pair<int, int> q2 = range(node * 2 + 2, (a + b) / 2 + 1, b, i, j);
  return q1.second < q2.second ? q1 : q2;
}
void dfs(int u, int p, int lvl) {
  if (pos[u] == -1) pos[u] = idx;
  arr[idx] = lvl;
  euler[idx++] = u;
  for (int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v != p) dfs(v, u, lvl + 1);
  }
  arr[idx] = lvl - 1;
  euler[idx++] = p;
}
int lca(int u, int v) {
  return euler[range(0, 0, 2 * n - 2, min(pos[u], pos[v]), max(pos[u], pos[v]))
                   .first];
}
int dist(int u, int v) {
  return arr[pos[u]] + arr[pos[v]] - 2 * arr[pos[lca(u, v)]];
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x;
    x--;
    graph[x].push_back(i);
  }
  memset(pos, -1, sizeof(pos));
  dfs(0, -1, 0);
  build(0, 0, 2 * n - 2);
  x = y = 0;
  for (int i = 1; i < n; i++) {
    xy = dist(x, y);
    xz = dist(x, i);
    yz = dist(y, i);
    if (xz > xy && xz >= yz)
      y = i;
    else if (yz >= xz && yz > xy)
      x = i;
    cout << max(xy, max(xz, yz)) << " ";
  }
  return 0;
}
