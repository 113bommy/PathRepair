#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, m;
unordered_set<int> g[MAXN];
int color[MAXN];
int low[MAXN];
int depth[MAXN];
stack<pair<int, int> > edge_stack;
vector<pair<int, int> > edges_to_remove;
int COMP_ID;
int comp_before[MAXN];
int comp_after[MAXN];
void remove_comp(int u, int v, bool odd) {
  pair<int, int> uv(u, v);
  while (true) {
    pair<int, int> top = edge_stack.top();
    edge_stack.pop();
    if (odd) edges_to_remove.push_back(top);
    if (top == uv) break;
  }
}
bool dfs_before(int u, int p, int d) {
  comp_before[u] = COMP_ID;
  depth[u] = d;
  color[u] = d % 2;
  low[u] = d - 1;
  bool u_odd = false;
  for (int v : g[u]) {
    if (v == p) continue;
    if (depth[v] == -1) {
      edge_stack.emplace(u, v);
      bool v_odd = dfs_before(v, u, d + 1);
      if (p == -1) {
        assert(low[v] >= d);
      }
      if (low[v] >= d) {
        remove_comp(u, v, v_odd);
      } else {
        u_odd = u_odd or v_odd;
        low[u] = min(low[u], low[v]);
      }
    } else if (depth[v] < d) {
      assert(d - depth[v] >= 2);
      edge_stack.emplace(u, v);
      low[u] = min(low[u], depth[v]);
      if (color[u] == color[v]) {
        u_odd = true;
      }
    } else {
    }
  }
  return u_odd;
}
void dfs_after(int u, int p) {
  comp_after[u] = COMP_ID;
  for (int v : g[u]) {
    if (v == p or comp_after[v] != -1) continue;
    dfs_after(v, u);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].insert(b);
    g[b].insert(a);
  }
  memset(depth, -1, sizeof(depth[0]) * n);
  COMP_ID = 0;
  for (int u = 0; u <= n - 1; ++u) {
    if (depth[u] == -1) {
      dfs_before(u, -1, 0);
      COMP_ID++;
    }
  }
  for (auto& e : edges_to_remove) {
    g[e.first].erase(e.second);
    g[e.second].erase(e.first);
  }
  memset(comp_after, -1, sizeof(comp_after[0]) * n);
  COMP_ID = 0;
  for (int u = 0; u <= n - 1; ++u) {
    if (comp_after[u] == -1) {
      dfs_after(u, -1);
      COMP_ID++;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
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
