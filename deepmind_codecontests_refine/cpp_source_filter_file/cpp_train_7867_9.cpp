#include <bits/stdc++.h>
using namespace std;
const int MAXN = (2e4 + 5) * 30, MAXM = 2e4 + 5, INF = 2e9;
int n, m, cnt, f[MAXN][16];
int id[MAXN][16], dep[MAXN];
int tot = 1, h[MAXN], cur[MAXN];
struct edge {
  int to, nxt, val;
} e[MAXN];
vector<int> pre[MAXN], pred[MAXN];
queue<int> q;
void add(int x, int y, int z) {
  e[++tot] = (edge){y, h[x], z};
  h[x] = tot;
}
void Dfs(int k, int fa) {
  dep[k] = dep[fa] + 1, f[k][0] = fa;
  for (int i = 1; i <= 15 && f[k][i - 1]; ++i) {
    f[k][i] = f[f[k][i - 1]][i - 1], id[k][i] = ++cnt;
    int flag = 1;
    if (id[k][i - 1])
      add(cnt, id[k][i - 1], INF), add(id[k][i - 1], cnt, 0), flag = 0;
    if (id[f[k][i - 1]][i - 1])
      add(cnt, id[f[k][i - 1]][i - 1], INF),
          add(id[f[k][i - 1]][i - 1], cnt, 0), flag = 0;
    if (flag) id[k][i] = 0, --cnt;
  }
  for (int i = 0; i < pre[k].size(); ++i)
    if (pre[k][i] != fa) id[pre[k][i]][0] = pred[k][i], Dfs(pre[k][i], k);
}
void LCA(int x, int y, int frm) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int i = 15; ~i; --i)
    if (dep[f[y][i]] >= dep[x]) {
      if (id[y][i]) add(frm, id[y][i], INF), add(id[y][i], frm, 0);
      y = f[y][i];
    }
  if (x == y) return;
  for (int i = 15; ~i; --i)
    if (f[x][i] != f[y][i]) {
      if (id[x][i]) add(frm, id[x][i], INF), add(id[x][i], frm, 0);
      x = f[x][i];
      if (id[y][i]) add(frm, id[y][i], INF), add(id[y][i], frm, 0);
      y = f[y][i];
    }
  if (id[x][0]) add(frm, id[x][0], INF), add(id[x][0], frm, 0);
  if (id[y][0]) add(frm, id[y][0], INF), add(id[y][0], frm, 0);
  return;
}
int bfs() {
  memset(dep, 0, sizeof(dep));
  q.push((1)), dep[(1)] = 1;
  while (q.size()) {
    int k = q.front();
    q.pop();
    for (int u = h[k]; u; u = e[u].nxt)
      if (!dep[e[u].to] && e[u].val) dep[e[u].to] = dep[k] + 1, q.push(e[u].to);
  }
  return dep[(2)] ? 1 : 0;
}
int dfs(int k, int flow) {
  if (k == (2)) return flow;
  int ans = 0, ret = 0;
  for (int &u = cur[k]; u; u = e[u].nxt)
    if (e[u].val && dep[e[u].to] == dep[k] + 1) {
      ret = dfs(e[u].to, min(e[u].val, flow - ans));
      ans += ret, e[u].val -= ret, e[u ^ 1].val += ret;
      if (flow == ans) return ans;
    }
  return ans;
}
int Dinic() {
  int ans = 0;
  while (bfs()) {
    memcpy(cur, h, sizeof(cur));
    ans += dfs((1), INF);
  }
  return ans;
}
void DFS(int k) {
  cur[k] = 1;
  for (int u = h[k]; u; u = e[u].nxt)
    if (e[u].val && !cur[e[u].to]) DFS(e[u].to);
}
int main() {
  int i, j, k;
  int x, y, z, ans, Ans;
  scanf("%d%d", &n, &m), cnt = m + n + 1;
  for (i = 1; i <= m; ++i) add((1), (i + 2), 1), add((i + 2), (1), 0);
  for (i = 1; i < n; ++i) add((i + m + 2), (2), 1), add((2), (i + m + 2), 0);
  for (i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    pre[x].push_back(y), pred[x].push_back((i + m + 2));
    pre[y].push_back(x), pred[y].push_back((i + m + 2));
  }
  Dfs(1, 0);
  for (i = 1; i <= m; ++i) scanf("%d%d", &x, &y), LCA(x, y, (i + 2));
  printf("%d\n", ans = Dinic());
  memset(cur, 0, sizeof(cur));
  DFS((1)), Ans = 0;
  for (int u = h[(1)]; u; u = e[u].nxt)
    if (!cur[e[u].to]) ++Ans;
  printf("%d ", Ans);
  for (int u = h[(1)]; u; u = e[u].nxt)
    if (!cur[e[u].to]) printf("%d ", e[u].to - 2);
  Ans = 0, printf("\n");
  for (int u = h[(2)]; u; u = e[u].nxt)
    if (cur[e[u].to]) ++Ans;
  printf("%d ", Ans);
  for (int u = h[(2)]; u; u = e[u].nxt)
    if (cur[e[u].to]) printf("%d ", e[u].to - m - 2);
  return 0;
}
