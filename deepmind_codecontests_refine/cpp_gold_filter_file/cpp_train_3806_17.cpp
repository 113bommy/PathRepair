#include <bits/stdc++.h>
using namespace std;
int n, m, L, s, t;
int b[1010], c2;
struct Edge {
  int fr, to, next, id;
  bool ext;
  long long w;
} e[10010 * 2], E[10010];
int c1, head[1010];
inline void add_edge(int u, int v, long long w, int id) {
  e[c1].to = v;
  e[c1].w = w;
  e[c1].id = id;
  e[c1].next = head[u];
  head[u] = c1++;
}
long long dis[1010];
void mem() {
  for (int i = 0; i < 1010; ++i) dis[i] = 1e14;
}
struct node {
  long long d;
  int k;
  node(int _d = 0, int _k = 0) {
    d = _d;
    k = _k;
  }
  friend bool operator<(const node &u, const node &v) { return u.d > v.d; }
};
priority_queue<node> Q;
bool vis[1010];
int pre[1010], la[1010];
void dij() {
  mem();
  Q.push(node(0, s));
  dis[s] = 0;
  memset(vis, 0, sizeof vis);
  memset(pre, 0, sizeof pre);
  memset(la, 0, sizeof la);
  while (!Q.empty()) {
    int u = Q.top().k;
    Q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = e[i].next) {
      int v = e[i].to;
      long long w = e[i].w, id = e[i].id;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pre[v] = u;
        la[v] = id;
        Q.push(node(dis[v], v));
      }
    }
  }
}
int use[10010];
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
  for (int i = 1; i <= m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    E[i].fr = x;
    E[i].to = y;
    E[i].w = z;
    E[i].ext = 1;
    if (!z) {
      E[i].ext = 0;
      continue;
    }
    add_edge(x, y, z, i);
    add_edge(y, x, z, i);
    E[i].id = c1 - 1;
  }
  dij();
  if (dis[t] < L) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    int u = E[i].fr, v = E[i].to;
    long long &w = E[i].w;
    if (!w) add_edge(u, v, 1, i), add_edge(v, u, 1, i), w = 1, E[i].id = c1 - 1;
  }
  dij();
  if (dis[t] > L) {
    puts("NO");
    return 0;
  }
  if (dis[t] == L) {
    puts("YES");
    for (int i = 1; i <= m; ++i)
      printf("%d %d %lld\n", E[i].fr, E[i].to, E[i].w);
    return 0;
  }
  int now = t, I = 1;
  while (now != s) {
    if (!E[la[now]].ext) b[++c2] = la[now], use[la[now]] = I;
    now = pre[now];
  }
  for (int i = 1; i <= m; ++i) {
    int id = E[i].id;
    if (use[i] == I || E[i].ext) continue;
    e[id ^ 1].w = e[id].w = 1000000010;
    E[i].w = 1000000010;
  }
  for (int i = 1; i <= c2; ++i) {
    int id = E[b[i]].id;
    E[b[i]].w = e[id ^ 1].w = e[id].w = e[id].w + L - dis[t];
    break;
  }
  while (dis[t] < L) {
    ++I;
    dij();
    int now = t;
    while (now != s) {
      if (!E[la[now]].ext) use[la[now]] = I;
      now = pre[now];
    }
    for (int i = 1; i <= c2; ++i) {
      int id = E[b[i]].id;
      if (use[b[i]] == I) continue;
      e[id ^ 1].w = e[id].w = 1000000010;
      E[b[i]].w = 1000000010;
    }
    for (int i = 1; i <= c2; ++i) {
      int id = E[b[i]].id;
      if (use[b[i]] != I) continue;
      E[b[i]].w = e[id ^ 1].w = e[id].w = e[id].w + L - dis[t];
      break;
    }
  }
  puts("YES");
  for (int i = 1; i <= m; ++i) printf("%d %d %lld\n", E[i].fr, E[i].to, E[i].w);
  return 0;
}
