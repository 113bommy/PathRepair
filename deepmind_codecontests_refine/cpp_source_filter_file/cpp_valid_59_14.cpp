#include <bits/stdc++.h>
using namespace std;
const int N = 4005, inf = 1e9;
int n, m, a[N], b[N], lst[N];
vector<int> g[N];
long long dis[N];
bool rns[N];
bool asdf(long long &w) {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (rns[i])
      q.push(i), dis[i] = w, lst[i] = -1;
    else
      dis[i] = -1, lst[i] = -1;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : g[u])
      if (a[v] < dis[u] && !(rns[u] && rns[v]) && lst[u] != v) {
        if (dis[v] == -1)
          dis[v] = dis[u] + b[v], lst[v] = u, q.push(v);
        else {
          for (int x = u; !rns[x]; x = lst[x]) w += b[x], rns[x] = true;
          for (int x = v; !rns[x]; x = lst[x]) w += b[x], rns[x] = true;
          return true;
        }
      }
  }
  return false;
}
bool check(long long x) {
  for (int i = 1; i <= n; i++) rns[i] = i == 1;
  while (asdf(x))
    ;
  for (int i = 1; i <= n; i++)
    if (!rns[i]) return false;
  return true;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  int l = 0, r = inf;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) solve();
  return 0;
}
