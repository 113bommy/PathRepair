#include <bits/stdc++.h>
using namespace std;
vector<int> comp_before;
vector<int> comp_after;
vector<int> low;
vector<int> depth;
vector<int> color;
vector<set<int>> g;
stack<pair<int, int>> s;
vector<pair<int, int>> banned;
int curr_comp;
int n, m;
void removeComp(bool odd, pair<int, int> e) {
  while (true) {
    if (odd) banned.push_back(s.top());
    if (s.top() == e) {
      s.pop();
      break;
    } else
      s.pop();
  }
}
bool dfs(int u, int p, int d) {
  comp_before[u] = curr_comp;
  depth[u] = d;
  low[u] = d;
  bool odd = false;
  for (int v : g[u]) {
    if (v == p) continue;
    if (depth[v] == -1) {
      pair<int, int> uv(u, v);
      s.push(uv);
      bool v_odd = dfs(v, u, d + 1);
      if ((p == -1) || (low[v] >= depth[u]))
        removeComp(v_odd, uv);
      else {
        odd = odd or v_odd;
        low[u] = min(low[u], low[v]);
      }
    } else if (depth[v] < depth[u]) {
      if ((depth[u] - depth[v]) % 2 == 0) odd = true;
      s.push({u, v});
      low[u] = min(low[u], depth[v]);
    }
  }
  return odd;
}
void bfs(int s) {
  queue<int> q;
  q.push(s);
  color[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    comp_after[u] = curr_comp;
    for (int v : g[u]) {
      if (color[v] == -1) {
        color[v] = 1 - color[u];
        q.push(v);
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  g.assign(n, set<int>());
  comp_before.resize(n);
  comp_after.assign(n, -1);
  low.resize(n);
  depth.assign(n, -1);
  color.assign(n, -1);
  banned.clear();
  while (!s.empty()) s.pop();
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b), --a, --b;
    g[a].insert(b);
    g[b].insert(a);
  }
  curr_comp = 0;
  for (int i = 0; i <= n - 1; ++i)
    if (depth[i] == -1) dfs(i, -1, 0), curr_comp++;
  for (auto e : banned) {
    g[e.first].erase(e.second);
    g[e.second].erase(e.first);
  }
  curr_comp = 0;
  for (int i = 0; i <= n - 1; ++i)
    if (color[i] == -1) bfs(i), curr_comp++;
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b), --a, --b;
    if (comp_before[a] != comp_before[b])
      puts("NO");
    else if (comp_after[a] != comp_after[b])
      puts("YES");
    else if (color[a] != color[b])
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
