#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  if (flag) x = -x;
}
int n1, n2, m, v1, v2, s, t, S, T, now, ans;
int in[400010], dis[400010];
bool vis[400010];
char str[400010];
struct edge {
  int to, nxt, v, c;
  edge(int x = 0, int y = 0, int z = 0, int w = 0) {
    to = x, nxt = y, v = z, c = w;
  }
} e[400010];
int head[400010], edge_cnt = 1;
void add(int from, int to, int l, int r, int cost) {
  in[from] -= l, in[to] += l;
  e[++edge_cnt] = edge(to, head[from], r - l, cost), head[from] = edge_cnt;
  e[++edge_cnt] = edge(from, head[to], 0, -cost), head[to] = edge_cnt;
}
bool spfa() {
  for (int i = s; i <= t; ++i) vis[i] = false, dis[i] = 1000000000;
  queue<int> q;
  q.push(s), vis[s] = true, dis[s] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop(), vis[x] = false;
    for (int i = head[x]; i; i = e[i].nxt) {
      int y = e[i].to, c = e[i].c;
      if (dis[y] <= dis[x] + c || !e[i].v) continue;
      dis[y] = dis[x] + c;
      if (!vis[y]) q.push(y), vis[y] = true;
    }
  }
  return dis[t] != 1000000000;
}
int dfs(int x, int lim) {
  if (x == t) return lim;
  vis[x] = true;
  int res = lim, flow;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to, v = e[i].v;
    if (dis[y] != dis[x] + e[i].c || vis[y] || !v) continue;
    if (flow = dfs(y, min(res, v))) {
      res -= flow, e[i].v -= flow, e[i ^ 1].v += flow;
      if (!res) break;
    }
  }
  return lim - res;
}
int dinic() {
  int v = 0, flow;
  while (spfa())
    while (flow = dfs(s, 1000000000)) v += flow * dis[t];
  return v;
}
bool check() {
  for (int i = head[s]; i; i = e[i].nxt)
    if (e[i].v) return false;
  return true;
}
int main() {
  read(n1), read(n2), read(m), read(v1), read(v2), S = n1 + n2 + 1, T = S + 1,
                                                   t = S + 2;
  scanf("%s", str + 1);
  for (int i = 1; i <= n1; ++i) {
    if (str[i] == 'R')
      add(S, i, 1, 1000000000, 0);
    else if (str[i] == 'B')
      add(i, T, 1, 1000000000, 0);
    else
      add(S, i, 0, 1000000000, 0), add(i, T, 0, 1000000000, 0);
  }
  scanf("%s", str + 1);
  for (int i = 1; i <= n2; ++i) {
    if (str[i] == 'R')
      add(i + n1, T, 1, 1000000000, 0);
    else if (str[i] == 'B')
      add(S, i + n1, 1, 1000000000, 0);
    else
      add(S, i + n1, 0, 1000000000, 0), add(i + n1, T, 0, 1000000000, 0);
  }
  add(T, S, 0, 1000000000, 0), now = edge_cnt + 1;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    read(x), read(y);
    add(x, y + n1, 0, 1, v1), add(y + n1, x, 0, 1, v2);
  }
  for (int i = 1; i <= T; ++i) {
    if (in[i] > 0)
      add(s, i, 0, in[i], 0);
    else
      add(i, t, 0, -in[i], 0);
  }
  ans = dinic();
  if (!check()) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans);
  for (int i = now; i - now + 1 <= 4 * m; i += 4) {
    if (!e[i].v)
      putchar('R');
    else if (!e[i + 2].v)
      putchar('B');
    else
      putchar('U');
  }
  return 0;
}
