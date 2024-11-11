#include <bits/stdc++.h>
using namespace std;
int n, m, qq;
vector<int> g[100005], tr[100005];
int mark[100005], dpt[100005];
map<pair<int, int>, bool> conn;
int timer, tin[100005], tout[100005], up[100005][21], l = 20;
void dfs(int st, int pr, int cd = 0) {
  tin[st] = ++timer;
  dpt[st] = cd;
  up[st][0] = pr;
  for (int i = 1; i <= l; ++i) up[st][i] = up[up[st][i - 1]][i - 1];
  for (int v : tr[st]) {
    if (v == pr) continue;
    dfs(v, st, cd + 1);
  }
  tout[st] = ++timer;
}
bool upper(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
pair<int, int> lca2(int a, int b) {
  int ax = a;
  for (int i = l; i >= 0; --i)
    if (!upper(up[ax][i], b)) ax = up[ax][i];
  int bx = b;
  for (int i = l; i >= 0; --i)
    if (!upper(up[bx][i], a)) bx = up[bx][i];
  return make_pair(ax, bx);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> qq;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    conn[make_pair(u, v)] = 1;
    conn[make_pair(v, u)] = 1;
  }
  queue<int> q;
  q.push(1);
  mark[1] = 1;
  while (!q.empty()) {
    int st = q.front();
    q.pop();
    for (int v : g[st])
      if (!mark[v]) {
        mark[v] = 1;
        tr[st].push_back(v);
        tr[v].push_back(st);
        q.push(v);
      }
  }
  dfs(1, 1);
  while (qq--) {
    int a, b;
    cin >> a >> b;
    if (upper(b, a)) swap(a, b);
    if (upper(a, b)) {
      cout << dpt[b] - dpt[a] << '\n';
    } else {
      pair<int, int> tem = lca2(a, b);
      int lc = up[tem.first][0];
      int dis = dpt[a] + dpt[b] - 2 * dpt[lc];
      if (conn.find(tem) != conn.end()) dis--;
      cout << dis << '\n';
    }
  }
}
