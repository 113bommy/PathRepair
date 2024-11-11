#include <bits/stdc++.h>
using namespace std;
const int mxn = 101000;
vector<vector<int> > g, t;
int inTree[mxn];
int d[mxn];
int n, q;
void dfs(int u, int dd, int num, int p) {
  inTree[u] = num;
  d[u] = dd;
  t[num].push_back(0);
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, dd + 1, num, u);
  }
}
void add(int p, int v, int num) {
  for (int i = p; i < t[num].size(); i += (i & (-i))) {
    t[num][i] += v;
  }
}
int query(int p, int num) {
  int res = 0;
  for (int i = p; i > 0; i -= (i & (-i))) {
    res += t[num][i];
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  g.resize(n + 1);
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  t.resize(g[1].size() + 1);
  int inRoot = 0;
  for (int i = 0; i < g[1].size(); i++) {
    t[i].push_back(0);
    dfs(g[1][i], 1, i, 1);
  }
  t[t.size() - 1].resize(n + 10);
  for (int i = 0, v, val, dist, tp; i < q; i++) {
    cin >> tp;
    if (tp) {
      cin >> v;
      if (v == 1)
        cout << inRoot << "\n";
      else {
        int res = query(d[v], inTree[v]) + query(d[v], t.size() - 1);
        cout << res << "\n";
      }
    } else {
      cin >> v >> val >> dist;
      if (v == 1) {
        inRoot += val;
        add(1, val, t.size() - 1);
        add(dist + 1, val, t.size() - 1);
      } else {
        if (dist >= d[v]) {
          int left = dist - d[v];
          inRoot += val;
          add(1, val, t.size() - 1);
          add(left + 1, -val, t.size() - 1);
          add(left + 1, val, inTree[v]);
          add(d[v] + dist + 1, -val, inTree[v]);
        } else {
          add(d[v] - dist, val, inTree[v]);
          add(d[v] + dist + 1, -val, inTree[v]);
        }
      }
    }
  }
  return 0;
}
