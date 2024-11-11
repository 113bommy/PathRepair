#include <bits/stdc++.h>
using namespace std;
struct name {
  int v;
  int l;
  int r;
} p;
vector<name> g[1001];
int viz[10001], n, m, i, j, x, y, l, r, mid;
vector<int> test;
void dfs(int v, int tl, int tr) {
  viz[v] = 1;
  for (int k = 0; k < g[v].size(); k++) {
    if (viz[g[v][k].v] == 0 && g[v][k].l <= tl && g[v][k].r >= tr)
      dfs(g[v][k].v, tl, tr);
  };
};
bool f(int len) {
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) viz[j] = 0;
    dfs(1, test[i], test[i] + len);
    if (viz[n] == 1) return 1;
  };
  return 0;
};
int main() {
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y >> p.l >> p.r;
    test.push_back(p.l);
    p.v = y;
    g[x].push_back(p);
    p.v = x;
    g[y].push_back(p);
  };
  l = 0;
  r = 1000000;
  while (l < r) {
    if (l == r - 1) {
      if (f(r)) l = r;
      break;
    };
    mid = (l + r) / 2;
    if (f(mid))
      l = mid;
    else
      r = mid - 1;
  };
  if (f(l) == 0) {
    cout << "Nice work, Dima!";
    return 0;
  };
  cout << l + 1;
  return 0;
}
