#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxN = 100005;
vector<pair<int, int> > ed[maxN];
int Find(int x, vector<int> &parent, vector<int> &height) {
  if (x != parent[x]) parent[x] = Find(parent[x], parent, height);
  return parent[x];
}
bool Union(int x, int y, vector<int> &parent, vector<int> &height) {
  if ((x = Find(x, parent, height)) == (y = Find(y, parent, height)))
    return false;
  if (height[x] > height[y]) {
    parent[y] = x;
  } else {
    parent[x] = y;
    if (height[x] == height[y]) height[y]++;
  }
  return true;
}
void dfs(int n, vector<vector<int> > &adj, vector<int> &comp, int cc) {
  comp[n] = cc;
  for (const auto &to : adj[n]) {
    if (comp[to] < 0) dfs(to, adj, comp, cc);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = (0); i < (m); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ed[c].emplace_back(a, b);
  }
  int r = sqrt(m);
  vector<vector<int> > heavy;
  map<int, int> hi;
  int hc = 0;
  map<pair<int, int>, int> light;
  for (int c = (1); c < (m + 1); c++) {
    if (int((ed[c]).size()) > r) {
      vector<int> parent(n + 1), height(n + 1, 0);
      for (int i = (1); i < (n + 1); i++) parent[i] = i;
      for (const auto &e : ed[c]) {
        Union(e.first, e.second, parent, height);
      }
      hi[c] = hc++;
      heavy.push_back(parent);
    } else {
      map<int, int> ni;
      int nc = 0;
      vector<int> in;
      vector<vector<int> > adj(2 * int((ed[c]).size()), vector<int>());
      for (const auto &e : ed[c]) {
        if (!(ni.find(e.first) != end(ni)))
          ni[e.first] = nc++, in.push_back(e.first);
        if (!(ni.find(e.second) != end(ni)))
          ni[e.second] = nc++, in.push_back(e.second);
        adj[ni[e.first]].push_back(ni[e.second]);
        adj[ni[e.second]].push_back(ni[e.first]);
      }
      vector<int> comp(nc, -1);
      int cc = 0;
      for (int i = (0); i < (nc); i++) {
        if (comp[i] < 0) dfs(i, adj, comp, cc), cc++;
      }
      for (int i = (0); i < (nc); i++)
        for (int j = (0); j < (nc); j++) {
          if (comp[i] == comp[j]) {
            light[make_pair(in[i], in[j])]++;
          }
        }
    }
  }
  int q;
  cin >> q;
  for (int i = (0); i < (q); i++) {
    int u, v;
    cin >> u >> v;
    int res = light[make_pair(u, v)];
    vector<int> foo;
    for (auto &parent : heavy) {
      res += (Find(u, parent, parent) == Find(v, parent, parent));
    }
    cout << res << endl;
  }
}
