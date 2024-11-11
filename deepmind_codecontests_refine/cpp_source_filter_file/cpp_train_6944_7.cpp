#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000009LL;
long long large = 2000000000000000000LL;
vector<vector<pair<int, int> > > adj;
vector<int> cost;
class UnionFind {
 private:
  vector<int> p;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      p[y] = x;
    }
  }
};
vector<bool> vis;
vector<int> cc;
vector<int> l, r;
void dfs(int u, int parent) {
  vis[u] = true;
  cc.push_back(u);
  for (int j = 0; j < (int)adj[u].size(); j++) {
    int v = adj[u][j].first;
    if (!vis[v]) dfs(v, u);
  }
}
vector<int> s;
void dfs0(int u, int parent, int e) {
  int sum = 0;
  for (int j = 0; j < (int)adj[u].size(); j++) {
    int v = adj[u][j].first;
    if (v == parent) continue;
    dfs0(v, u, adj[u][j].second);
    if (u == l[adj[u][j].second]) {
      sum += cost[adj[u][j].second];
    } else {
      sum -= cost[adj[u][j].second];
    }
  }
  if (e != -1) {
    if (u == l[e])
      cost[e] = s[u] - sum;
    else
      cost[e] = s[u] + sum;
  }
}
int main() {
  int n;
  cin >> n;
  s.assign(n, 0);
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);
  int m;
  cin >> m;
  cost.assign(m, 0);
  l.assign(m, -1);
  r = l;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    l[i] = x;
    r[i] = y;
  }
  UnionFind uf(n);
  adj.assign(n, vector<pair<int, int> >());
  for (int i = 0; i < m; i++) {
    if (!uf.isSameSet(l[i], r[i])) {
      uf.unionSet(l[i], r[i]);
      adj[l[i]].push_back(pair<int, int>(r[i], i));
      adj[r[i]].push_back(pair<int, int>(l[i], i));
    }
  }
  vis.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cc.clear();
      dfs(i, -1);
      int sum = 0;
      for (int j = 0; j < (int)cc.size(); j++) {
        int u = cc[j];
        sum += s[u];
      }
      if (sum != 0) {
        cout << "Impossible" << endl;
        return 0;
      }
      dfs0(i, -1, -1);
    }
  }
  cout << "Possible" << endl;
  for (int i = 0; i < m; i++) {
    cout << cost[i] << endl;
  }
  return 0;
}
