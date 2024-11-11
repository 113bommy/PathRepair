#include <bits/stdc++.h>
using namespace std;
int n, s, t, head[5000 + 5], cnt = 0, d[5000 + 5], cur[5000 + 5], deg[5000 + 5];
struct edge {
  int end, next, val, cost;
} e[100000 + 5];
queue<int> Q;
bool vis[5000 + 5];
void add_edge(int u, int v, int l, int r, int money) {
  deg[u] -= l;
  deg[v] += l;
  e[++cnt].end = v;
  e[cnt].next = head[u];
  e[cnt].val = r - l;
  e[cnt].cost = money;
  head[u] = cnt;
  e[++cnt].end = u;
  e[cnt].next = head[v];
  e[cnt].val = 0;
  e[cnt].cost = -money;
  head[v] = cnt;
}
bool SPFA() {
  int i;
  for (i = 1; i <= n; i++) cur[i] = head[i];
  memset(d, 0x3f, sizeof(d));
  memset(vis, false, sizeof(vis));
  while (!Q.empty()) Q.pop();
  Q.push(s);
  d[s] = 0;
  vis[s] = true;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    vis[u] = false;
    for (i = head[u]; i > 0; i = e[i].next) {
      int v = e[i].end;
      if (e[i].val > 0 && d[v] > d[u] + e[i].cost) {
        d[v] = d[u] + e[i].cost;
        if (!vis[v]) Q.push(v);
        vis[v] = true;
      }
    }
  }
  if (d[t] > 1e9) return false;
  return true;
}
int Dfs(int u, int bound) {
  int i;
  if (u == t) return bound;
  int total = 0;
  vis[u] = true;
  for (i = cur[u]; i > 0; i = e[i].next) {
    int v = e[i].end;
    if (e[i].val != 0 && !(vis[v]) && d[v] == d[u] + e[i].cost) {
      int gain = Dfs(v, min(bound, e[i].val));
      e[i].val -= gain;
      e[i ^ 1].val += gain;
      total += gain;
      bound -= gain;
      if (bound == 0) break;
    }
    cur[u] = e[i].next;
  }
  vis[u] = false;
  return total;
}
string s1, s2;
int main() {
  int n1, n2, flow = 0, last = 0, m, i, Rc, Bc, ss, tt, tot = 0;
  long long money = 0;
  scanf("%d%d%d%d%d", &n1, &n2, &m, &Rc, &Bc);
  cin >> s1 >> s2;
  cnt = 1;
  n = n1 + n2;
  ss = n + 1;
  tt = n + 2;
  s = n + 3;
  t = n + 4;
  n = t;
  for (i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y + n1, 0, 1, Rc);
    add_edge(y + n1, x, 0, 1, Bc);
  }
  for (i = 1; i <= n1; i++) {
    if (s1[i - 1] == 'R') add_edge(ss, i, 1, 1e9, 0);
    if (s1[i - 1] == 'B') add_edge(i, tt, 1, 1e9, 0);
    if (s1[i - 1] == 'U')
      add_edge(ss, i, 0, 1e9, 0), add_edge(i, tt, 0, 1e9, 0);
  }
  for (i = 1; i <= n2; i++) {
    if (s2[i - 1] == 'B') add_edge(ss, i + n1, 1, 1e9, 0);
    if (s2[i - 1] == 'R') add_edge(i + n1, tt, 1, 1e9, 0);
    if (s2[i - 1] == 'U')
      add_edge(ss, i + n1, 0, 1e9, 0), add_edge(i + n1, tt, 0, 1e9, 0);
  }
  add_edge(tt, ss, 0, 1e9, 0);
  for (i = 1; i <= tt; i++) {
    if (deg[i] > 0)
      tot += deg[i], add_edge(s, i, 0, deg[i], 0);
    else if (deg[i] < 0)
      add_edge(i, t, 0, -deg[i], 0);
  }
  while (SPFA()) {
    memset(vis, false, sizeof(vis));
    flow += Dfs(s, 1e9);
    money += 1ll * (flow - last) * d[t];
    last = flow;
  }
  if (flow != tot) {
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", money);
  for (i = 2; i <= 4 * m + 1; i += 4) {
    if (!e[i].val)
      printf("R");
    else if (!e[i + 2].val)
      printf("L");
    else
      printf("U");
  }
  printf("\n");
}
