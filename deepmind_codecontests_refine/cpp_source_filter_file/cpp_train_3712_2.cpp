#include <bits/stdc++.h>
using namespace std;
const int N = 1002, M = 20002, HM = 10002;
int to[M], nxt[M], head[HM], dis[N], diss[N], tot = 0, n, m, s, t, a, b,
                                              ans = 0;
bool yb[N][N], vis[N];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    que;
template <typename T>
void Read(T &t) {
  char c;
  t = 0;
  int f = 1;
  while ((c = getchar()) < '0' && c > '9')
    if (c == '-') f = -1;
  while (c >= '0' && c <= '9') (t *= 10) += c - '0', c = getchar();
  t *= f;
}
void add_edge(int x, int y) {
  to[++tot] = y;
  nxt[tot] = head[x];
  head[x] = tot;
  to[++tot] = x;
  nxt[tot] = head[y];
  head[y] = tot;
  return;
}
void dijkstra_first() {
  memset(dis, 0x3f / 3, sizeof(dis));
  dis[s] = 0;
  que.push(make_pair(0, s));
  while (!que.empty()) {
    int x = que.top().second;
    que.pop();
    if (vis[x]) continue;
    vis[x] = true;
    for (register int i = head[x]; i; i = nxt[i]) {
      int y = to[i];
      if (dis[x] + 1 < dis[y]) {
        dis[y] = dis[x] + 1;
        que.push(make_pair(dis[y], y));
      }
    }
  }
}
void dijkstra_second() {
  memset(diss, 0x3f / 3, sizeof(diss));
  memset(vis, 0, sizeof(vis));
  diss[t] = 0;
  que.push(make_pair(0, t));
  while (!que.empty()) {
    int x = que.top().second;
    que.pop();
    if (vis[x]) continue;
    vis[x] = true;
    for (register int i = head[x]; i; i = nxt[i]) {
      int y = to[i];
      if (diss[x] + 1 < diss[y]) {
        diss[y] = diss[x] + 1;
        que.push(make_pair(diss[y], y));
      }
    }
  }
}
int main() {
  Read(n);
  Read(m);
  Read(s);
  Read(t);
  while (m--) {
    Read(a);
    Read(b);
    add_edge(a, b);
    yb[a][b] = true;
    yb[b][a] = true;
  }
  dijkstra_first();
  dijkstra_second();
  for (register int i = 1; i <= n; i++) {
    for (register int j = i + 1; j <= n; j++) {
      if (!yb[i][j] && dis[i] + diss[j] + 1 >= dis[t] &&
          dis[j] + diss[i] + 1 >= dis[s])
        ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
