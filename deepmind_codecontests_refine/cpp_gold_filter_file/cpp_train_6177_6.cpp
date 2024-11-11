#include <bits/stdc++.h>
using namespace std;
struct edge {
  int s, p, w, ind;
};
bool cmp(edge a, edge b) {
  if (a.w < b.w) return true;
  return false;
}
const int max_N = 100000 + 20;
const int INF = 1000000001;
bool mark[max_N], pass[max_N];
int n, m, par[max_N], size[max_N], h[max_N], min_d[max_N], ans[max_N];
string a[max_N];
vector<pair<int, int> > adj[max_N];
set<int> node;
edge e[max_N];
int findpar(int v) {
  if (par[par[v]] != par[v]) par[v] = findpar(par[v]);
  return par[v];
}
void dsu(int a, int b) {
  a = findpar(a), b = findpar(b);
  if (a == b) return;
  if (size[a] < size[b]) swap(a, b);
  par[b] = a, size[a] += size[b];
}
void dfs(int v) {
  mark[v] = true;
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int u = adj[v][i].first, r = adj[v][i].second;
    if (!mark[u]) {
      pass[r] = true;
      h[u] = h[v] + 1;
      dfs(u);
      min_d[v] = min(min_d[v], min_d[u]);
    } else if (!pass[r]) {
      min_d[v] = min(min_d[v], h[u]);
      pass[r] = true;
    }
  }
}
void dfs_all() {
  for (set<int>::iterator it = node.begin(); it != node.end(); it++) {
    int i = *it;
    if (!mark[i]) {
      h[i] = 0;
      dfs(i);
    }
    mark[i] = false;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d %d", &a, &b, &e[i].w);
    e[i].ind = i, e[i].s = a - 1, e[i].p = b - 1;
  }
  sort(e, e + m, cmp);
  for (int i = 0; i < n; i++) par[i] = i, size[i] = 1, min_d[i] = INF;
  int pt1 = 0, pt2 = 0;
  while (pt1 < m) {
    while (e[pt1].w == e[pt2].w) {
      int u = findpar(e[pt2].s), v = findpar(e[pt2].p);
      if (u != v) {
        ans[pt2] = 1;
        node.insert(u), node.insert(v);
        adj[u].push_back(make_pair(v, pt2));
        adj[v].push_back(make_pair(u, pt2));
      }
      pt2++;
    }
    dfs_all();
    for (set<int>::iterator it = node.begin(); it != node.end(); it++) {
      int u = *it;
      for (int j = 0; j < (int)adj[u].size(); j++) {
        int ee = adj[u][j].second;
        if (h[u] > h[adj[u][j].first] && min_d[u] < h[u]) ans[ee] = 2;
        pass[ee] = false;
      }
      min_d[u] = INF, adj[u].clear();
    }
    node.clear();
    while (pt1 < pt2) {
      if (ans[pt1] > 0) dsu(e[pt1].s, e[pt1].p);
      pt1++;
    }
  }
  for (int i = 0; i < m; i++) {
    int pt = e[i].ind;
    if (ans[i] == 0)
      a[pt] = "none";
    else if (ans[i] == 1)
      a[pt] = "any";
    else
      a[pt] = "at least one";
  }
  for (int i = 0; i < m; i++) cout << a[i] << endl;
  return 0;
}
