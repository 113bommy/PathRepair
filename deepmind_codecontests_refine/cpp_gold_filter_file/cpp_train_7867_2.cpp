#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int data = 0, w = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    data = (data << 1) + (data << 3) + (ch ^ 48), ch = getchar();
  return data * w;
}
int cnt = 1, h[1000005], pre[1000005], cur[1000005];
struct node {
  int to, next, v;
} w[1000005 << 1];
void add(int x, int y, int v) {
  w[++cnt] = (node){y, h[x], v};
  h[x] = cnt;
  w[++cnt] = (node){x, h[y], 0};
  h[y] = cnt;
}
int q[1000005], d[1000005], tot, S, T;
bool BFS() {
  memset(d, -1, sizeof(int) * (tot + 1));
  int l = 1, r = 0;
  q[++r] = S;
  d[S] = 1;
  while (l <= r) {
    int x = q[l++];
    if (x == T) return 1;
    for (int i = h[x]; i; i = w[i].next) {
      int y = w[i].to;
      if (w[i].v && d[y] == -1) q[++r] = y, d[y] = d[x] + 1;
    }
  }
  return 0;
}
int DFS(int x, int mf) {
  if (x == T) return mf;
  int ret = 0;
  for (int &i = cur[x]; i; i = w[i].next) {
    int y = w[i].to;
    if (w[i].v && d[y] == d[x] + 1) {
      int dlt = DFS(y, min(mf, w[i].v));
      if (!dlt) d[y] = -1;
      ret += dlt;
      mf -= dlt;
      w[i].v -= dlt;
      w[i ^ 1].v += dlt;
      if (!mf) return ret;
    }
  }
  return ret;
}
const int inf = 0x3f3f3f3f;
int dinic() {
  int ans = 0;
  while (BFS()) memcpy(cur, h, 4 * (tot + 1)), ans += DFS(S, inf);
  return ans;
}
int n, m, Log[1000005], dep[1000005], p[20005][23], di[20005][23];
vector<pair<int, int> > v[20005];
void dfs(int x, int fa) {
  p[x][0] = fa;
  dep[x] = dep[fa] + 1;
  di[x][0] = ++tot;
  for (int i = 1; i <= Log[dep[x]]; i++) {
    p[x][i] = p[p[x][i - 1]][i - 1];
    if (p[x][i])
      di[x][i] = ++tot, add(di[x][i], di[x][i - 1], inf),
      add(di[x][i], di[p[x][i - 1]][i - 1], inf);
  }
  for (auto y : v[x])
    if (y.first != fa) pre[y.first] = y.second, dfs(y.first, x);
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = Log[dep[x]]; i >= 0; i--)
    if (dep[p[x][i]] >= dep[y]) x = p[x][i];
  if (x == y) return x;
  for (int i = Log[dep[x]]; i >= 0; i--)
    if (p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
  return p[x][0];
}
void Link(int v, int x, int pr) {
  if (x == pr) return;
  int t = dep[x] - dep[pr], k = Log[t], jp = dep[x] - dep[pr] - (1 << k);
  add(v, di[x][k], inf);
  for (int i = 17; i >= 0; i--)
    if (jp >> i & 1) x = p[x][i];
  add(v, di[x][k], inf);
}
bool vis[1000005];
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  for (int i = h[x]; i; i = w[i].next)
    if (w[i].v) dfs(w[i].to);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n - 1; i++) {
    int x = read(), y = read();
    v[x].push_back(make_pair(y, i));
    v[y].push_back(make_pair(x, i));
  }
  Log[0] = -1;
  for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  tot = m;
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), LCA = lca(x, y);
    Link(i, x, LCA);
    Link(i, y, LCA);
  }
  S = ++tot, T = ++tot;
  for (int i = 2; i <= n; i++) add(di[i][0], T, 1);
  for (int i = 1; i <= m; i++) add(S, i, 1);
  cout << dinic() << '\n';
  dfs(S);
  int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= m; i++)
    if (!vis[i]) ++ans1;
  for (int i = 1; i <= n; i++)
    if (vis[di[i][0]]) ++ans2;
  cout << ans1 << ' ';
  for (int i = 1; i <= m; i++)
    if (!vis[i]) cout << i << ' ';
  puts("");
  cout << ans2 << ' ';
  for (int i = 2; i <= n; i++)
    if (vis[di[i][0]]) cout << pre[i] << ' ';
  return 0;
}
