#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int M = 1e9 + 7;
vector<pair<int, int> > edges;
int preparent[505][N], sufparent[505][N];
int sz[505], parent[505];
int roots(int v, int idx) {
  if (sufparent[v][idx] == v) return v;
  return sufparent[v][idx] = roots(sufparent[v][idx], idx);
}
int rootp(int v, int idx) {
  if (preparent[v][idx] == v) return v;
  return preparent[v][idx] = rootp(preparent[v][idx], idx);
}
void joinp(int x, int y, int idx) {
  if (sz[x] > sz[y])
    preparent[y][idx] = x, sz[x] += sz[y];
  else
    preparent[x][idx] = y, sz[y] += sz[x];
  return;
}
void joins(int x, int y, int idx) {
  if (sz[x] > sz[y])
    sufparent[y][idx] = x, sz[x] += sz[y];
  else
    sufparent[x][idx] = y, sz[y] += sz[x];
  return;
}
int root(int v) {
  if (parent[v] == v) return v;
  return parent[v] = root(parent[v]);
}
void join(int x, int y) {
  if (sz[x] > sz[y])
    parent[y] = x, sz[x] += sz[y];
  else
    parent[x] = y, sz[y] += sz[x];
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    edges.push_back(make_pair(x, y));
  }
  for (int i = 1; i <= n; i++) preparent[i][0] = i, sz[i] = 1;
  for (int i = 1; i <= m; i++) {
    int u = edges[i - 1].first;
    int v = edges[i - 1].second;
    for (int j = 1; j <= n; j++) preparent[j][i] = preparent[j][i - 1];
    int ur = rootp(u, i);
    int vr = rootp(v, i);
    if (ur != vr) {
      joinp(ur, vr, i);
    }
  }
  for (int i = 1; i <= n; i++) sufparent[i][m + 1] = i, sz[i] = 1;
  for (int i = m; i >= 1; i--) {
    int u = edges[i - 1].first;
    int v = edges[i - 1].second;
    for (int j = 1; j <= n; j++) sufparent[j][i] = sufparent[j][i + 1];
    int ur = roots(u, i);
    int vr = roots(v, i);
    if (ur != vr) {
      joins(ur, vr, i);
    }
  }
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int l, r;
    cin >> l >> r;
    l -= 1;
    r += 1;
    bool check[505] = {0};
    int ans = 0;
    for (int j = 1; j <= n; j++) parent[j] = preparent[j][l], sz[i] = 1;
    for (int j = 1; j <= n; j++) {
      int u = preparent[j][l];
      int v = sufparent[j][r];
      int ur = root(u);
      int vr = root(v);
      if (ur != vr) join(ur, vr);
    }
    for (int i = 1; i <= n; i++) check[root(i)] = 1;
    for (int i = 1; i <= n; i++)
      if (check[i]) ans += 1;
    cout << ans << "\n";
  }
  return 0;
}
