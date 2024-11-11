#include <bits/stdc++.h>
using namespace std;
struct edge_type {
  int u, v, w, index;
};
int n, m, u, v, w, root[100001], child[100001], newV[2 * 100001], nnew,
    low[100001], num[100001], cnt, ans[100001];
vector<edge_type> edge[1000001];
vector<pair<int, int> > adj[100001];
bool visited[100001];
edge_type make_edge(int u, int v, int w, int index) {
  edge_type re;
  re.u = u;
  re.v = v;
  re.w = w;
  re.index = index;
  return re;
}
int get_root(int x) {
  if (root[x] == x) return x;
  root[x] = get_root(root[x]);
  return root[x];
}
void join(int x, int y) { root[get_root(x)] = get_root(y); }
void tarjan(int u, int pre) {
  low[u] = 2000000000;
  num[u] = ++cnt;
  int v, index;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    v = adj[u][i].second;
    index = adj[u][i].first;
    if (!visited[index]) {
      visited[index] = true;
      if (num[v] != 0) {
        low[u] = min(low[u], num[v]);
      } else {
        tarjan(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] >= num[v]) ans[index] = 1;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    edge[w].push_back(make_edge(u, v, w, i));
  }
  for (int i = 1; i <= n; i++) {
    root[i] = i;
    child[i] = 1;
  }
  cnt = 0;
  for (w = 1; w < 1000001; w++) {
    if (edge[w].size() == 0) continue;
    nnew = 0;
    for (unsigned int i = 0; i < edge[w].size(); i++) {
      u = get_root(edge[w][i].u);
      v = get_root(edge[w][i].v);
      if (u == v) continue;
      newV[nnew++] = u;
      newV[nnew++] = v;
      ans[edge[w][i].index] = 2;
      adj[u].push_back(make_pair(edge[w][i].index, v));
      adj[v].push_back(make_pair(edge[w][i].index, u));
      num[u] = num[v] = 0;
    }
    for (int i = 0; i < nnew; i++) {
      if (num[newV[i]] == 0) {
        tarjan(newV[i], 0);
      }
    }
    for (int i = 0; i < nnew; i++) adj[newV[i]].clear();
    for (unsigned int i = 0; i < edge[w].size(); i++) {
      u = get_root(edge[w][i].u);
      v = get_root(edge[w][i].v);
      if (u != v) join(u, v);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (ans[i] == 0)
      printf("none\n");
    else if (ans[i] == 1)
      printf("any\n");
    else
      printf("at least one\n");
  }
  return 0;
}
