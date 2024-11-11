#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 20020, M = 1000010;
int n, m, S, T, cnt, tot = 1;
int id[N][20], fa[N][20];
int dep[N], de[N];
int fi[M], ne[M], to[M], w[M];
vector<pair<int, int>> g[N];
inline void add(int x, int y, int z) {
  if (!x || !y) return;
  ne[++tot] = fi[x];
  to[fi[x] = tot] = y;
  w[tot] = z;
  ne[++tot] = fi[y];
  to[fi[y] = tot] = x;
  w[tot] = z;
}
inline void link(int x, int y, int k) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int i = 14; ~i; --i)
    if (dep[fa[x][i]] >= dep[y]) add(k, id[x][i], inf), x = fa[x][i];
  if (x == y) return;
  for (int i = 14; ~i; --i)
    if (fa[x][i] != fa[y][i])
      add(k, id[x][i], inf), add(k, id[y][i], inf), x = fa[x][i], y = fa[y][i];
  add(k, id[x][0], inf);
  add(k, id[y][0], inf);
  return;
}
void dfs(int x) {
  dep[x] = dep[fa[x][0]] + 1;
  for (int i = 1; i <= 14; ++i)
    fa[x][i] = fa[fa[x][i - 1]][i - 1], id[x][i] = ++cnt,
    add(id[x][i], id[x][i - 1], inf),
    add(id[x][i], id[fa[x][i - 1]][i - 1], inf);
  for (auto i : g[x])
    if (i.first != fa[x][0])
      fa[i.first][0] = x, id[i.first][0] = i.second, dfs(i.first);
}
bool bfs() {
  for (int i = 0; i <= T; ++i) de[i] = 0;
  queue<int> s;
  s.push(S);
  de[S] = 1;
  while (!s.empty()) {
    int x = s.front();
    s.pop();
    for (int i = fi[x]; i; i = ne[i])
      if (!de[to[i]] && w[i]) de[to[i]] = de[x] + 1, s.push(to[i]);
  }
  return de[T];
}
int dfs(int x, int fl) {
  if (x == T) return fl;
  int la = fl;
  for (int i = fi[x]; i && la; i = ne[i])
    if (de[to[i]] == de[x] + 1 && w[i]) {
      int p = dfs(to[i], min(la, w[i]));
      if (!p) {
        de[to[i]] = 0;
        continue;
      }
      w[i] -= p, w[i ^ 1] += p, la -= p;
    }
  return fl - la;
}
int dinic(int ans = 0) {
  while (bfs()) ans += dfs(S, inf);
  return ans;
}
int main() {
  cin >> n >> m;
  cnt = m + n - 1;
  for (int i = 1, x, y; i < n; ++i)
    cin >> x >> y, g[x].push_back(make_pair(y, m + i)),
        g[y].push_back(make_pair(x, m + i));
  dfs(1);
  S = ++cnt, T = ++cnt;
  for (int i = 1; i < n; ++i) add(m + i, T, 1);
  for (int i = 1; i <= m; ++i) add(S, i, 1);
  for (int i = 1, x, y; i <= m; ++i) cin >> x >> y, link(x, y, i);
  cout << dinic() << endl;
  bfs();
  vector<int> a, b;
  for (int i = 1; i <= m; ++i)
    if (!de[i]) a.push_back(i);
  for (int i = m + 1; i < m + n; ++i)
    if (de[i]) b.push_back(i - m);
  cout << a.size() << " ";
  for (int i : a) cout << i << " ";
  puts("");
  cout << b.size() << " ";
  for (int i : b) cout << i << " ";
  puts("");
  return 0;
}
