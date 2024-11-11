#include <bits/stdc++.h>
using i64 = long long;
int k, diameter;
std::vector<std::vector<int>> g;
std::vector<int> dist, color;
std::pair<int, int> dfs(int v, int p) {
  auto ret = std::make_pair(0, v);
  for (int to : g[v]) {
    if (to == p) continue;
    auto r = dfs(to, v);
    r.first++;
    if (r.first > ret.first) std::swap(r, ret);
  }
  dist[v] = ret.first;
  return ret;
}
void dfs2(int v, int p, int c) {
  color[v] = c;
  for (int to : g[v])
    if (to != p) dfs2(to, v, !c);
}
void dfsk(int v, int p, int c, bool rev = false) {
  color[v] = (c % k + k) % k;
  for (int to : g[v])
    if (to != p) {
      if (rev)
        dfsk(to, v, c - 1, true);
      else if (c >= diameter / 2)
        dfsk(to, v, c + 1);
      else if (dist[to] + c + 2 == diameter)
        dfsk(to, v, c + 1);
      else
        dfsk(to, v, c - 1, true);
    }
}
bool check(int v, int p, int o) {
  int a[] = {o ? o : -1, -1, -1};
  for (int to : g[v]) {
    if (to == p) continue;
    int d = dist[to] + 1;
    if (d > a[0]) {
      a[2] = a[1];
      a[1] = a[0];
      a[0] = d;
    } else if (d > a[1]) {
      a[2] = a[1];
      a[1] = d;
    } else if (d > a[2]) {
      a[2] = d;
    }
  }
  if (a[2] >= 0) {
    if (a[1] + a[2] + 1 >= k) return false;
  }
  for (int to : g[v]) {
    if (to == p) continue;
    int l = dist[to] + 1 == a[0] ? a[1] + 1 : a[0] + 1;
    if (!check(to, v, l)) return false;
  }
  return true;
}
int main() {
  int n;
  scanf("%d%d", &n, &k);
  g.resize(n);
  dist.resize(n);
  color.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (k == 2) {
    printf("Yes\n");
    dfs2(0, -1, 0);
    for (auto c : color) printf("%d ", c + 1);
    printf("\n");
    return 0;
  }
  int root = dfs(0, -1).second;
  diameter = dfs(root, -1).first + 1;
  fprintf(stderr, "root = %d, diameter = %d\n", root + 1, diameter);
  if (!check(root, -1, 0)) {
    printf("No\n");
    return 0;
  }
  dfsk(root, -1, 0);
  printf("Yes\n");
  for (auto c : color) printf("%d ", c + 1);
  printf("\n");
  return 0;
}
