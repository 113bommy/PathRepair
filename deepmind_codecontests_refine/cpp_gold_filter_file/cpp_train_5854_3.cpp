#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
const int INF = 0x3f3f3f3f, N = 4e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
constexpr int LOG = 19;
int n, k, r, sp[N], step[N], f[N];
vector<int> G[N];
int fa[N][22], dep[N];
void dfs(int u) {
  for (int i = 1; i <= LOG; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : G[u]) {
    if (v == fa[u][0]) continue;
    dep[v] = dep[u] + 1;
    fa[v][0] = u;
    dfs(v);
  }
}
int LCA(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int i = LOG; i >= 0; i--)
    if (dep[fa[y][i]] >= dep[x]) y = fa[y][i];
  if (x == y) return x;
  for (int i = LOG; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int up(int x, int d) {
  for (int i = LOG; i >= 0; i--)
    if ((d >> i) & 1) x = fa[x][i];
  return x;
}
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) f[x] = y;
}
void bfs() {
  queue<int> q;
  for (int i = 1; i <= 2 * n; i++) f[i] = i, step[i] = -1;
  for (int i = 1; i <= r; i++) q.push(sp[i]), step[sp[i]] = 0;
  while ((int)q.size()) {
    int u = q.front();
    q.pop();
    if (step[u] >= k) break;
    for (int v : G[u]) {
      merge(u, v);
      if (step[v] == -1) {
        step[v] = step[u] + 1;
        q.push(v);
      }
    }
  }
}
void walk(int &u, int v, int w, int k) {
  if (dep[u] - dep[w] >= k)
    u = up(u, k);
  else
    u = up(v, dep[v] - k + dep[u] - 2 * dep[w]);
}
bool ok(int u, int v) {
  int w = LCA(u, v);
  if (dep[u] + dep[v] - 2 * dep[w] <= 2 * k) return 1;
  walk(u, v, w, k);
  walk(v, u, w, k);
  if (find(u) == find(v)) return 1;
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &k, &r);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(n + i);
    G[v].push_back(n + i);
    G[n + i].push_back(u);
    G[n + i].push_back(v);
  }
  for (int i = 1; i <= r; i++) scanf("%d", &sp[i]);
  dep[1] = 1;
  dfs(1);
  bfs();
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (ok(u, v))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
