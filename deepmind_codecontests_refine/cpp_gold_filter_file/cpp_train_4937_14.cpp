#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const long long Linfi = (long long)9e18;
const int c1 = 11;
const int c2 = 37;
int n = 4;
int parent[1000005], depth[1000005];
int f[1000005][25];
void Init() {
  parent[1] = -1;
  parent[2] = parent[3] = parent[4] = 1;
  depth[1] = 1;
  depth[2] = depth[3] = depth[4] = 2;
  int m = log2(n);
  for (int u = 1; u <= n; u++) f[u][0] = parent[u];
  for (int k = 1; k <= m; k++)
    for (int u = 1; u <= n; u++) {
      int v = f[u][k - 1];
      f[u][k] = f[v][k - 1];
    }
}
void add(int u, int cha) {
  parent[u] = cha;
  depth[u] = depth[cha] + 1;
  f[u][0] = parent[u];
  int m = log2(n);
  for (int k = 1; k <= m; k++) {
    int v = f[u][k - 1];
    f[u][k] = f[v][k - 1];
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int m = log2(depth[u]);
  for (int i = m; i >= 0; i--) {
    int tmp = f[u][i];
    if (depth[u] - (1 << i) >= depth[v]) {
      u = f[u][i];
    }
  }
  if (u == v) return u;
  for (int i = m; i >= 0; i--) {
    int u1 = f[u][i];
    int v1 = f[v][i];
    if (u1 != -1 && u1 != v1) {
      u = u1;
      v = v1;
    }
  }
  return parent[u];
}
int get_path(int u, int v) {
  int cha = lca(u, v);
  return depth[u] + depth[v] - 2 * depth[cha];
}
int main() {
  ios::sync_with_stdio(false);
  Init();
  int q, v;
  cin >> q;
  int first_end = 2, second_end = 3, diameter = 2;
  while (q--) {
    cin >> v;
    add(++n, v);
    add(++n, v);
    int n_to_first = get_path(n, first_end);
    int n_to_second = get_path(n, second_end);
    if (n_to_first >= n_to_second && n_to_first > diameter) {
      second_end = n;
      diameter = n_to_first;
    } else if (n_to_second >= n_to_first && n_to_second > diameter) {
      first_end = n;
      diameter = n_to_second;
    }
    cout << diameter << endl;
  }
  return 0;
}
