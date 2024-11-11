#include <bits/stdc++.h>
using namespace std;
int parent[500009];
int sz[500009];
void initialize() {
  for (int i = 1; i <= 500009; ++i) {
    parent[i] = i;
    sz[i] = 1;
  }
}
int find_parent(int n) {
  if (n == parent[n])
    return n;
  else
    return parent[n] = find_parent(parent[n]);
}
void Union(int u, int v) {
  u = find_parent(u);
  v = find_parent(v);
  if (u == v) return;
  if (sz[u] > sz[v]) swap(u, v);
  parent[u] = v;
  sz[v] += sz[u];
}
int main() {
  initialize();
  int n, m;
  cin >> n >> m;
  int x, y, y1;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    if (x == 0) continue;
    cin >> y;
    for (int j = 1; j < x; ++j) {
      cin >> y1;
      Union(y, y1);
    }
  }
  for (int i = 1; i <= n; ++i) cout << sz[parent[i]] << " ";
  cout << endl;
  return 0;
}
