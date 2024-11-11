#include <bits/stdc++.h>
using namespace std;
const int N = 610, inf = 0x3f3f3f3f;
int n, m, k, x, y, rd[N], s, t, cnt = 1, head[N], stk[N], col[N], tot, sum,
                                vis[N];
struct edge {
  int to, nxt, c;
} e[N * 20];
void Adde(int x, int y, int c) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
  e[cnt].c = c;
}
void adde(int x, int y, int c) {
  Adde(x, y, c);
  Adde(y, x, 0);
}
void gg() {
  for (int i = (1); i <= (m); i++) printf("0 ");
  puts("");
}
bool bfs() {
  queue<int> q;
  q.push(s);
  for (int i = (1); i <= (t); i++) vis[i] = -1;
  vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u], v; i; i = e[i].nxt)
      if (v = e[i].to, e[i].c && vis[v] == -1) vis[v] = vis[u] + 1, q.push(v);
  }
  return vis[t] != -1;
}
int dfs(int u, int flow) {
  if (u == t) return flow;
  int used = 0, w;
  for (int i = head[u], v; i; i = e[i].nxt)
    if (v = e[i].to, e[i].c && vis[v] == vis[u] + 1) {
      w = dfs(v, min(e[i].c, flow - used));
      e[i].c -= w;
      e[i ^ 1].c += w;
      used += w;
      if (used == flow) return flow;
    }
  if (!used) vis[u] = -1;
  return used;
}
int dinic() {
  int res = 0;
  while (bfs()) res += dfs(s, inf);
  return res;
}
int Main() {
  scanf("%d%d%d", &n, &m, &k);
  s = n + m + 1, t = s + 1;
  tot = sum = 0;
  for (int i = (1); i <= (m); i++) {
    scanf("%d%d", &x, &y), rd[x]++, rd[y]++;
    adde(i + n, x, 1), adde(i + n, y, 1), adde(s, i + n, 1);
  }
  for (int i = (1); i <= (n); i++)
    if (rd[i] >= k) adde(i, t, 2 * (rd[i] - k)), sum += 2 * (rd[i] - k);
  if (dinic() == sum) {
    memset(col, 0, n + 1 << 2);
    for (int u = (1); u <= (n); u++) {
      int top = 0;
      for (int i = head[u]; i; i = e[i].nxt)
        if (e[i].c) stk[++top] = e[i].to - n;
      for (int i = 1; i <= top; i += 2) col[stk[i]] = col[stk[i + 1]] = ++tot;
    }
    for (int i = (1); i <= (m); i++)
      if (!col[i]) col[i] = ++tot;
    for (int i = (1); i <= (m); i++) printf("%d ", col[i]);
    puts("");
  } else
    gg();
  cnt = 1;
  memset(head, 0, t + 1 << 2);
  memset(rd, 0, n + 1 << 2);
  return 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) Main();
  return 0;
}
