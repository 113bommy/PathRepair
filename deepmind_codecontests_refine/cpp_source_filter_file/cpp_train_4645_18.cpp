#include <bits/stdc++.h>
using namespace std;
const int N = 7e5;
stack<int> s, t;
int n, fa[N][20], dep[N];
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
void pt() { printf("%d\n", s.size() + t.size()); }
int main() {
  cin >> n;
  n++;
  for (int i = 0; i < 20; i++) fa[1][i] = 1;
  for (int i = 2, x, y; i <= n; i++) {
    scanf("%d", &x), fa[i][0] = x;
    dep[i] = dep[x] + 1;
    for (int j = 1; j < 20; j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
  }
  s.push(1), t.push(2);
  puts("2");
  int now = 1;
  for (int i = 3; i <= n; i++) {
    int x = lca(i, s.top()), y = lca(i, t.top()),
        mx = max(dep[i] + dep[s.top()] - dep[x] * 2,
                 dep[i] + dep[t.top()] - dep[y] * 2);
    if (mx < now) {
      pt();
      continue;
    }
    if (mx == now) {
      if (dep[i] + dep[s.top()] - dep[x] * 2 == mx)
        s.push(i);
      else
        t.push(i);
      pt();
      continue;
    }
    now++;
    if (dep[i] + dep[s.top()] - dep[x] * 2 != mx) {
      while (!s.empty()) {
        int z = s.top(), u = lca(i, z);
        s.pop();
        if (dep[z] + dep[i] - dep[u] * 2 == now) t.push(u);
      }
      s.push(i);
    } else {
      while (!t.empty()) {
        int z = t.top(), u = lca(i, z);
        t.pop();
        if (dep[z] + dep[i] - dep[u] * 2 == now) s.push(u);
      }
      t.push(i);
    }
    pt();
  }
}
