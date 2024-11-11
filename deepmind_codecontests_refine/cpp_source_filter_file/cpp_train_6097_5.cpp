#include <bits/stdc++.h>
const int MAXN = 200031, MAXL = 20;
std::vector<std::pair<int, int> > t[MAXN];
int n = 0, m = 0, s = 0;
namespace DS {
int f[MAXN];
void init() {
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
}
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
bool uni(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    f[fy] = fx;
  }
  return fx != fy;
}
}  // namespace DS
struct E {
  int u, v, w, c, id;
  bool operator<(const E &x) const { return w < x.w; }
} e[MAXN];
int p[MAXN][MAXL], d[MAXN];
std::pair<int, int> x[MAXN][MAXL];
std::vector<std::pair<int, int> > l;
long long process() {
  long long ans = 0;
  std::sort(e, e + m);
  DS::init();
  for (int i = 0; i < m; i++) {
    if (DS::uni(e[i].u, e[i].v)) {
      l.push_back(std::pair<int, int>(e[i].w, e[i].id));
      ans += e[i].w;
      t[e[i].u].push_back(std::pair<int, int>(e[i].v, i));
      t[e[i].v].push_back(std::pair<int, int>(e[i].u, i));
    }
  }
  return ans;
}
void DFS(int u) {
  for (int i = 1; i < MAXL; i++) {
    p[u][i] = p[p[u][i - 1]][i - 1];
    x[u][i] = std::max(x[u][i - 1], x[p[u][i - 1]][i - 1]);
  }
  for (auto &i : t[u]) {
    int v = i.first;
    if (v != p[u][0]) {
      p[v][0] = u;
      x[v][0] = std::pair<int, int>(e[i.second].w, e[i.second].id);
      d[v] = d[u] + 1;
      DFS(v);
    }
  }
}
std::pair<int, int> get(int u, int v) {
  std::pair<int, int> ans(0, 0);
  if (d[u] < d[v]) {
    std::swap(u, v);
  }
  for (int i = MAXL - 1; i >= 0; i--) {
    if (d[u] - (1 << i) >= d[v]) {
      ans = std::max(ans, x[u][i]);
      u = p[u][i];
    }
  }
  if (u == v) {
    return ans;
  }
  for (int i = MAXL - 1; i >= 0; i--) {
    if (p[u][i] != p[v][i]) {
      ans = std::max(ans, x[u][i]);
      ans = std::max(ans, x[v][i]);
      u = p[u][i];
      v = p[v][i];
    }
  }
  return std::max(ans, std::max(x[u][0], x[v][0]));
}
void solve() {
  long long sum = process();
  p[1][0] = 1;
  x[1][0] = std::pair<int, int>(0, 0);
  d[1] = 0;
  DFS(1);
  long long ans = sum;
  int del = 0, ins = 0, dis = 0;
  for (int i = 0; i < m; i++) {
    auto z = get(e[i].u, e[i].v);
    long long w = sum - z.first + e[i].w - (s / e[i].c);
    if (w < ans) {
      ans = w;
      del = z.second;
      ins = e[i].id;
      dis = e[i].w - (s / e[i].c);
    }
  }
  printf("%I64d\n", ans);
  for (auto &i : l) {
    if (i.second != del) {
      printf("%d %d\n", i.second, i.first);
    }
  }
  printf("%d %d\n", ins, dis);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &e[i].w);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &e[i].c);
  }
  for (int i = 0; i < m; i++) {
    int a = 0, b = 0;
    scanf("%d%d", &e[i].u, &e[i].v);
    e[i].id = i + 1;
  }
  scanf("%d", &s);
  solve();
  return 0;
}
