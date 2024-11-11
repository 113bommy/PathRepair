#include <bits/stdc++.h>
using namespace std;
const int M = 2005;
int n, m, q;
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') y = (ch == '-' ? -1 : 1), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * y;
}
struct Edge {
  int nxt, to, w;
};
namespace NetWork_Flow {
Edge e[M];
int tot = 1, first[M], cur[M];
void add(int x, int y, int w) {
  e[++tot] = (Edge){first[x], y, w};
  first[x] = tot;
}
void addedge(int x, int y, int w) { add(x, y, w), add(y, x, 0); }
int S, T, de[M];
queue<int> Q;
bool bfs() {
  while (!Q.empty()) Q.pop();
  for (int i = 1; i <= n; i++) cur[i] = first[i], de[i] = 0;
  Q.push(S);
  de[S] = 1;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = first[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (!e[i].w || de[v]) continue;
      de[v] = de[u] + 1;
      Q.push(v);
      if (v == T) return 1;
    }
  }
  return 0;
}
int dfs(int u, int flow) {
  if (u == T || !flow) return flow;
  int f, tmp = 0;
  for (int i = cur[u]; i; i = cur[u] = e[i].nxt) {
    int v = e[i].to, w = e[i].w;
    if (de[v] != de[u] + 1 || !(f = dfs(v, min(w, flow - tmp)))) continue;
    e[i].w -= f, e[i ^ 1].w += f, tmp += f;
    if (tmp == flow) break;
  }
  return tmp;
}
void Init() {
  for (int i = 2; i <= tot; i += 2) e[i].w += e[i ^ 1].w, e[i ^ 1].w = 0;
}
int Dinic() {
  Init();
  int res = 0;
  while (bfs()) res += dfs(S, 1e9);
  return res;
}
}  // namespace NetWork_Flow
namespace MinCut_Tree {
Edge e[M];
int tot = 1, first[M], cur[M];
void add(int x, int y, int w) {
  e[++tot] = (Edge){first[x], y, w};
  first[x] = tot;
}
int d[M], t[M];
void Build(int l, int r) {
  if (l >= r) return;
  NetWork_Flow::S = d[l], NetWork_Flow::T = d[r];
  int Cut = NetWork_Flow::Dinic();
  int L = l, R = r;
  for (int i = l + 1; i < r; i++) {
    if (NetWork_Flow::de[d[i]])
      t[++L] = d[i];
    else
      t[--R] = d[i];
  }
  add(d[l], d[r], Cut), add(d[r], d[l], Cut);
  for (int i = l + 1; i < r; i++) d[i] = t[i];
  Build(l, L), Build(R, r);
}
int de[M], fath[M][15], minn[M][15];
void dfs(int u, int fa) {
  de[u] = de[fa] + 1;
  fath[u][0] = fa;
  for (int i = 1; i <= 10; i++)
    fath[u][i] = fath[fath[u][i - 1]][i - 1],
    minn[u][i] = min(minn[u][i - 1], minn[fath[u][i - 1]][i - 1]);
  for (int i = first[u]; i; i = e[i].nxt) {
    int v = e[i].to, w = e[i].w;
    if (v == fa) continue;
    minn[v][0] = w;
    dfs(v, u);
  }
}
int Get_min(int x, int y) {
  int res = 1e9;
  if (de[x] < de[y]) swap(x, y);
  for (int i = 10; i >= 0; i--)
    if (de[fath[x][i]] >= de[y]) res = min(res, minn[x][i]), x = fath[x][i];
  if (x == y) return res;
  for (int i = 10; i >= 0; i--)
    if (fath[x][i] != fath[y][i])
      res = min(res, min(minn[x][i], minn[y][i])), x = fath[x][i],
      y = fath[y][i];
  return min(res, min(minn[x][0], minn[y][0]));
}
}  // namespace MinCut_Tree
using namespace MinCut_Tree;
bool vis[M];
int a[M], Ans[M], mc[M][M];
void Find(int u, int id) {
  int Max = -1, x;
  vis[a[id] = u] = 1;
  if (id == n) return;
  for (int i = 1; i <= n; i++)
    if (!vis[i] && mc[u][i] > Max) Max = mc[u][i], x = i;
  a[0] += Max, Find(x, id + 1);
}
void solve() {
  n = read(), m = read(), Ans[0] = 0;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), w = read();
    NetWork_Flow::addedge(x, y, w), NetWork_Flow::addedge(y, x, w);
  }
  for (int i = 1; i <= n; i++) d[i] = i;
  Build(1, n);
  dfs(1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) mc[i][j] = mc[j][i] = Get_min(i, j);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) vis[j] = 0;
    a[0] = 0, Find(i, 1);
    if (a[0] > Ans[0])
      for (int j = 0; j <= n; j++) Ans[j] = a[j];
  }
  printf("%d\n", Ans[0]);
  for (int i = 1; i <= n; i++) printf("%d ", Ans[i]);
  printf("\n");
}
signed main() { solve(); }
