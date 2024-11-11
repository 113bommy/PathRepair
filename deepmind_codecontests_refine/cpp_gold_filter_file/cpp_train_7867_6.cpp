#include <bits/stdc++.h>
using namespace std;
struct edg {
  int t, next, id;
} e[100043];
int n, cnt1, m, hd[25002], ecnt, f[25001][15], id[25001][17], cnt, a, b,
    dep2[25003], cnt2, sid[25003];
struct edge {
  int t, v, next;
} ed[2000004];
int head[310000], cur[310000], dep[310000];
void adde(int f, int t, int w) {
  if (t == 0) return;
  ed[cnt].v = w;
  ed[cnt].next = head[f];
  ed[cnt].t = t;
  head[f] = cnt++;
  ed[cnt].v = 0;
  ed[cnt].next = head[t];
  ed[cnt].t = f;
  head[t] = cnt++;
}
void add(int f, int t) {
  e[++cnt1].t = t;
  e[cnt1].next = hd[f];
  hd[f] = cnt1;
  e[++cnt1].t = f;
  e[cnt1].next = hd[t];
  hd[t] = cnt1;
  e[cnt1].id = e[cnt1 - 1].id = ++cnt2;
}
void dfs1(int u, int fa) {
  dep2[u] = dep2[fa] + 1;
  f[u][0] = fa;
  id[u][0] = u + m;
  for (int i = 1; i <= 14; i++)
    f[u][i] = f[f[u][i - 1]][i - 1], id[u][i] = ++ecnt,
    adde(id[u][i], id[u][i - 1], 12312313),
    adde(id[u][i], id[f[u][i - 1]][i - 1], 12312313);
  for (int i = hd[u]; i; i = e[i].next)
    if (e[i].t != fa) sid[e[i].t] = e[i].id, dfs1(e[i].t, u);
}
bool bfs(int s, int t) {
  memset(dep, -1, sizeof(dep));
  memcpy(cur, head, sizeof(head));
  dep[s] = 0;
  queue<int> lsj;
  lsj.push(s);
  while (!lsj.empty()) {
    int p = lsj.front();
    lsj.pop();
    for (int i = head[p]; i != -1; i = ed[i].next)
      if (ed[i].v && dep[ed[i].t] == -1) {
        dep[ed[i].t] = dep[p] + 1;
        lsj.push(ed[i].t);
        if (ed[i].t == t) return 1;
      }
  }
  return 0;
}
int dfs(int u, int f, int t) {
  int tmp, ret = 0;
  if (u == t) return f;
  for (int& i = cur[u]; i != -1; i = ed[i].next)
    if (ed[i].v && (dep[ed[i].t] == dep[u] + 1) &&
        (tmp = dfs(ed[i].t, min(ed[i].v, f), t))) {
      ed[i].v -= tmp;
      ed[i ^ 1].v += tmp;
      f -= tmp;
      ret += tmp;
      if (!f) return ret;
    }
  return ret;
}
int dinic(int s, int t) {
  int ans = 0;
  while (bfs(s, t)) ans += dfs(s, 0x3f3f3f3f, t);
  return ans;
}
void que(int s, int x, int y) {
  if (dep2[x] < dep2[y]) x ^= y ^= x ^= y;
  for (int i = 14; i >= 0; i--)
    if (dep2[x] - dep2[y] >= 1 << i) adde(s, id[x][i], 12312313), x = f[x][i];
  if (x == y) return;
  for (int i = 14; i >= 0; i--)
    if (f[x][i] != f[y][i])
      adde(s, id[x][i], 12312313), adde(s, id[y][i], 12312313), x = f[x][i],
                                                                y = f[y][i];
  adde(s, id[x][0], 12312313);
  adde(s, id[y][0], 12312313);
  return;
}
int vis[1000001];
void dfs2(int s) {
  vis[s] = 1;
  for (int i = head[s]; i != -1; i = ed[i].next)
    if (ed[i].v && !vis[ed[i].t]) dfs2(ed[i].t);
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  ecnt = n + m;
  for (int i = 1; i < n; i++) scanf("%d%d", &a, &b), add(a, b);
  dfs1(1, 0);
  for (int i = 2; i <= n; i++) adde(i + m, 300001, 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    adde(0, i, 1);
    que(i, a, b);
  }
  printf("%d\n", dinic(0, 300001));
  dfs2(0);
  int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= m; i++)
    if (!vis[i]) ans1++;
  printf("%d ", ans1);
  for (int i = 1; i <= m; i++)
    if (!vis[i]) printf("%d ", i);
  printf("\n");
  for (int i = 2 + m; i <= n + m; i++)
    if (vis[i]) ans2++;
  printf("%d ", ans2);
  for (int i = 2 + m; i <= n + m; i++)
    if (vis[i]) printf("%d ", sid[i - m]);
}
