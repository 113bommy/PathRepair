#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[100005];
pair<pair<int, int>, pair<int, int> > edges[100005];
int A[100005], disc[100005], low[100005], t;
bool must[100005], never[100005], vis[100005];
int Find(int x) {
  int root = x, tmp;
  while (A[root] >= 0) root = A[root];
  while (x != root) {
    tmp = x;
    x = A[x];
    A[tmp] = root;
  }
  return root;
}
void Union(int a, int b) {
  int x = Find(a), y = Find(b);
  if (x != y) {
    if (A[x] > A[y]) swap(x, y);
    A[x] += A[y];
    A[y] = x;
  }
}
void dfs(int v, int p, int e) {
  vis[v] = 1;
  disc[v] = ++t;
  low[v] = disc[v];
  for (auto i : adj[v]) {
    if (!vis[i.first]) dfs(i.first, v, i.second);
    if (i.second != e) low[v] = min(low[v], low[i.first]);
  }
  if (e and low[v] > low[p]) must[e] = 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, a, b, i, j, k;
  vector<int> v;
  cin >> n >> m;
  for (i = 1; i <= n; i++) A[i] = -1;
  for (i = 0; i < m; i++) {
    cin >> edges[i].second.first >> edges[i].second.second >>
        edges[i].first.first;
    edges[i].first.second = i + 1;
  }
  sort(edges, edges + m);
  i = 0;
  while (i < m) {
    for (j = i; j < m; j++)
      if (edges[j].first.first != edges[i].first.first) break;
    v.clear();
    for (k = i; k < j; k++) {
      a = Find(edges[k].second.first), b = Find(edges[k].second.second);
      if (a == b) {
        never[edges[k].first.second] = 1;
        continue;
      }
      adj[a].push_back({b, edges[k].first.second});
      adj[b].push_back({a, edges[k].first.second});
      v.push_back(a);
      v.push_back(b);
      vis[a] = vis[b] = 0;
    }
    t = 0;
    for (auto x : v)
      if (!vis[x]) dfs(x, 0, 0);
    for (auto x : v) adj[x].clear();
    for (k = i; k < j; k++)
      Union(edges[k].second.first, edges[k].second.second);
    i = j;
  }
  for (i = 1; i <= m; i++)
    if (must[i])
      cout << "any" << '\n';
    else if (never[i])
      cout << "none" << '\n';
    else
      cout << "at least one" << '\n';
  return 0;
}
