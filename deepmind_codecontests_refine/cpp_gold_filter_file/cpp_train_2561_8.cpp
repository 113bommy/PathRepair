#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxh = 20;
int p[maxn];
int deep[maxn];
int anc[maxn][maxh];
int rt;
struct Edge {
  int from;
  int to;
  Edge(int f, int t) : from(f), to(t) {}
};
vector<int> G[maxn];
vector<Edge> edges;
void dfs(int root, int from) {
  if (root == rt) {
    deep[root] = 1;
    for (int i = 0; i < maxh; i++) anc[root][i] = root;
  } else {
    for (int i = 1; i < maxh; i++) {
      int y = anc[root][i - 1];
      anc[root][i] = anc[y][i - 1];
    }
  }
  for (int i = 0; i < G[root].size(); i++) {
    Edge e = edges[G[root][i]];
    if (e.to == from) continue;
    deep[e.to] = deep[root] + 1;
    anc[e.to][0] = root;
    dfs(e.to, root);
  }
}
void swim(int &x, int H) {
  for (int i = 0; H > 0; i++) {
    if (H & 1) x = anc[x][i];
    H /= 2;
  }
}
int lca(int x, int y) {
  int i;
  if (deep[x] > deep[y]) swap(x, y);
  swim(y, deep[y] - deep[x]);
  if (x == y) return x;
  for (;;) {
    for (i = 0; anc[x][i] != anc[y][i]; i++)
      ;
    if (i == 0) {
      return anc[x][0];
    }
    x = anc[x][i - 1];
    y = anc[y][i - 1];
  }
  return -1;
}
int dist(int st, int ed) {
  int ret = deep[st] + deep[ed] - deep[lca(st, ed)] * 2;
  return ret;
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    edges.push_back(Edge(i, p[i]));
    G[i].push_back(edges.size() - 1);
    edges.push_back(Edge(p[i], i));
    G[p[i]].push_back(edges.size() - 1);
  }
  rt = 1;
  dfs(1, -1);
  for (int iq = 0; iq < q; iq++) {
    int a, b, c;
    cin >> a >> b >> c;
    int x = dist(a, b);
    int y = dist(a, c);
    int z = dist(b, c);
    int ans = 0;
    ans = max(ans, (x + y - z) / 2);
    ans = max(ans, (x + z - y) / 2);
    ans = max(ans, (y + z - x) / 2);
    cout << ans + 1 << endl;
  }
  return 0;
}
