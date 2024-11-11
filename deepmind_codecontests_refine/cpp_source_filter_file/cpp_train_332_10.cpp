#include <bits/stdc++.h>
using namespace std;
const int N = 100000, LOG = 20;
vector<vector<int>> g(N), p(N, vector<int>(LOG));
vector<int> d(N), tin(N), tout(N), c(N);
int f = 1;
void dfs(int u, int pr, int depth) {
  p[u][0] = pr;
  tin[u] = f++;
  for (int i = 1; i < LOG; i++) {
    p[u][i] = p[p[u][i - 1]][i - 1];
  }
  d[u] = depth;
  c[u] = d[u] % 2;
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u, depth + 1);
    }
  }
  tout[u] = f++;
}
bool is_ancestor(int u, int v) { return tin[u] < tin[v] && tout[u] > tout[v]; }
int lca(int u, int v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  if (is_ancestor(v, u)) {
    return v;
  }
  for (int i = LOG - 1; i >= 0; i--) {
    if (!is_ancestor(p[u][i], v)) {
      u = p[u][i];
    }
  }
  return p[u][0];
}
int dist(int u, int v) {
  int a = lca(u, v);
  return d[u] + d[v] - 2 * d[a];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  dfs(0, 0, 0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a, b, x, y, k;
    scanf("%d %d %d %d %d", &x, &y, &a, &b, &k);
    --a, --b, --x, --y;
    int distance = dist(a, b);
    if (distance <= k && distance % 2 == k % 2) {
      puts("yes");
      continue;
    }
    distance = dist(a, x);
    distance += dist(b, y) + 1;
    if (distance <= k && distance % 2 == k % 2) {
      puts("yes");
      continue;
    }
    distance = dist(a, y);
    distance += dist(b, x) + 1;
    if (distance <= k && distance % 2 == k % 2) {
      puts("yes");
      continue;
    }
    puts("no");
  }
}
