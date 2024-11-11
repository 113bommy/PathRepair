#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 2e9 + 5;
int head[maxn], mat[maxn], n, m, tot;
bool vis[maxn];
struct edge {
  int v, nex;
} e[maxn << 1];
void add(int u, int v) { e[++tot] = {v, head[u]}, head[u] = tot; }
vector<int> g[maxn];
bool find(int u) {
  for (auto &v : g[u])
    if (!vis[v]) {
      vis[v] = 1;
      if (!mat[v] || find(mat[v])) {
        mat[v] = u;
        return 1;
      }
    }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
  }
  int ans = inf;
  for (int cen = 1; cen <= n; cen++) {
    for (int i = 1; i <= maxn - 5; i++) g[i].clear(), mat[i] = 0;
    int in = 0, out = 0, cnt = 0, res = 0;
    bool ok = 0;
    for (int u = 1; u <= n; u++) {
      if (u == cen) {
        for (int i = head[u]; i; i = e[i].nex) {
          int v = e[i].v;
          out++;
          if (v == u) ok = 1;
        }
      } else {
        for (int i = head[u]; i; i = e[i].nex) {
          int v = e[i].v;
          if (v == cen) {
            in++;
            continue;
          }
          g[u].push_back(v);
        }
      }
    }
    if (ok) out--;
    res += (n - 1) * 2 - in - out;
    for (int i = 1; i <= n; i++)
      if (!g[i].empty()) {
        for (int i = 1; i <= maxn - 5; i++) vis[i] = 0;
        if (find(i)) cnt++;
      }
    if (ok)
      out++;
    else
      res++;
    res += m - in - out - cnt;
    res += n - 1 - cnt;
    ans = min(ans, res);
  }
  cout << ans << '\n';
  return 0;
}
