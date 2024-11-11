#include <bits/stdc++.h>
using namespace std;
const int size = 1005;
struct Edge {
  int u, v, w;
  Edge() {}
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};
vector<Edge> e;
vector<int> G[size];
vector<int> x, y;
vector<Edge> ans;
int a, b, c, d;
void dfs(int v, int f, int mode) {
  if (G[v].size() == 1) {
    if (mode == 0) {
      if (a == 0) a = v;
      b = v;
    }
    if (mode == 1) {
      if (c == 0) c = v;
      d = v;
    }
  }
  for (auto u : G[v]) {
    if (u == f) continue;
    dfs(u, v, mode);
  }
}
int main() {
  int n, u, v, w;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d%d", &u, &v, &w);
    e.push_back(Edge(u, v, w));
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (G[i].size() != 1 && G[i].size() < 3) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (auto ed : e) {
    u = ed.u, v = ed.v, w = ed.w;
    a = b = c = d = 0;
    dfs(u, v, 0);
    dfs(v, u, 1);
    ans.push_back(Edge(a, c, w / 2));
    ans.push_back(Edge(b, d, w / 2));
    if (a != b) ans.push_back(Edge(a, b, -w / 2));
    if (c != d) ans.push_back(Edge(c, d, -w / 2));
  }
  printf("%d\n", ans.size());
  for (auto e : ans) {
    printf("%d %d %d\n", e.u, e.v, e.w);
  }
}
