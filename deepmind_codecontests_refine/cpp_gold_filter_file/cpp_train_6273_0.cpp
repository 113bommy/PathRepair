#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int N = 10004, M = 1024, inf = 0x3f3f3f3f;
queue<short> q;
struct zdl {
  struct edge {
    short v, f, nxt;
  } e[N << 1];
  short first[N], cur[N], cnt = 1;
  inline void add(short u, short v, short f) {
    e[++cnt].v = v;
    e[cnt].f = f;
    e[cnt].nxt = first[u];
    first[u] = cnt;
  }
  short dep[N], fr[N], s, t;
  int flow;
  inline bool bfs() {
    while (!q.empty()) q.pop();
    memset(dep, 0x3f, sizeof(short) * (t + 1));
    dep[s] = 1;
    q.push(s);
    while (!q.empty()) {
      short x = q.front();
      q.pop();
      for (short i = first[x], v; i; i = e[i].nxt) {
        v = e[i].v;
        if (!e[i].f || dep[v] <= dep[x] + 1) continue;
        dep[v] = dep[x] + 1;
        fr[v] = i;
        if (v == t) return 1;
        q.push(v);
      }
    }
    return 0;
  }
  int dfs(short x, int f) {
    if (x == t || !f) return f;
    int used = 0;
    for (short &i = cur[x], v, w; i; i = e[i].nxt) {
      v = e[i].v;
      if (!e[i].f || dep[v] != dep[x] + 1) continue;
      w = dfs(v, min(f, (int)e[i].f));
      if (!w) continue;
      e[i].f -= w;
      e[i ^ 1].f += w;
      f -= w;
      used += w;
      if (!f) return used;
    }
    return used;
  }
  inline void dinic() {
    while (bfs()) {
      memcpy(cur, first, sizeof(short) * (t + 1));
      flow += dfs(s, inf);
    }
  }
  inline void FF() {
    int x;
    while (bfs()) {
      flow++;
      x = t;
      while (x != s) {
        e[fr[x]].f--;
        e[fr[x] ^ 1].f++;
        x = e[fr[x] ^ 1].v;
      }
    }
  }
} G[M];
int n, m, k, Q, S, val[M];
int main() {
  n = read();
  m = read();
  k = read();
  Q = read();
  S = (1 << k) - 1;
  for (int i = 1, u, v, w; i <= m; i++) {
    u = read();
    v = read();
    w = read();
    G[0].add(u, v, w);
    G[0].add(v, u, 0);
  }
  G[0].s = 1;
  G[0].t = n;
  G[0].dinic();
  for (int s = 1; s <= S; s++) {
    for (int i = 1; i <= k; i++)
      if ((s >> (i - 1)) & 1) {
        G[s] = G[s ^ (1 << (i - 1))];
        G[s].e[i << 1].f = 25;
      }
    G[s].FF();
  }
  for (int ans; Q--;) {
    for (int i = 1; i <= k; i++) val[1 << (i - 1)] = read();
    ans = inf;
    for (int s = 0; s <= S; s++) {
      if (s) val[s] = val[s & -s] + val[s ^ (s & -s)];
      ans = min(ans, val[s] + G[S ^ s].flow);
    }
    cout << ans << "\n";
  }
  return (0 - 0);
}
