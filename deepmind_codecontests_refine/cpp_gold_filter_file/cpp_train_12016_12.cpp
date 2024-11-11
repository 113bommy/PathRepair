#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, L = 20;
int n, k, stamp, now;
int fa[N][L];
int ver[N], bg[N], dep[N];
vector<int> e[N];
set<int> s;
void dfs(int v, int f) {
  dep[v] = dep[f] + 1;
  bg[v] = ++stamp;
  ver[stamp] = v;
  fa[v][0] = f;
  for (int i = 1; i < L; ++i) fa[v][i] = fa[fa[v][i - 1]][i - 1];
  for (auto u : e[v])
    if (u != f) {
      dfs(u, v);
    }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int d = dep[x] - dep[y];
  for (int i = L - 1; i >= 0; --i)
    if (d >> i & 1) x = fa[x][i];
  if (x == y) return x;
  for (int i = L - 1; i >= 0; --i) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i], y = fa[y][i];
    }
  }
  return fa[x][0];
}
int dis(int x, int y) {
  x = ver[x], y = ver[y];
  return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void add(int i) {
  i = bg[i];
  if (!s.empty()) {
    auto lhs = i < *s.begin() ? --s.end() : --s.lower_bound(i);
    auto rhs = i > *--s.end() ? s.begin() : s.lower_bound(i);
    int tmp = dis(*lhs, i) + dis(*rhs, i) - dis(*lhs, *rhs);
    now += tmp / 2;
  } else {
    now += 1;
  }
  s.insert(i);
}
void remove(int i) {
  i = bg[i];
  s.erase(i);
  if (!s.empty()) {
    auto lhs = i < *s.begin() ? --s.end() : --s.lower_bound(i);
    auto rhs = i > *--s.end() ? s.begin() : s.lower_bound(i);
    int tmp = dis(*lhs, i) + dis(*rhs, i) - dis(*lhs, *rhs);
    now -= tmp / 2;
  } else {
    now -= 1;
  }
}
void run() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(1, 0);
  int ans = 1;
  int qh = 1;
  for (int qt = 1; qt <= n; ++qt) {
    add(qt);
    while (now > k) {
      remove(qh++);
    }
    ans = max(ans, qt - qh + 1);
  }
  printf("%d\n", ans);
}
int main() {
  run();
  return 0;
}
