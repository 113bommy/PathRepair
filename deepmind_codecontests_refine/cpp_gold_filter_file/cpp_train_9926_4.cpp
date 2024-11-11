#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
int Id[10000005], n, m, x, y, z, lnk[1000005], Now, nxt[1000005], tot, N,
    son[1000005], Q[1000005], Nx[1000005], w[1000005], fa[1000005];
long long heap[10000005], dis[1000005], Ans = INF;
bool vis[1000005];
struct lc {
  int x, y;
  long long z;
  bool operator<(const lc b) const { return z < b.z; }
} e[1000005];
inline int read() {
  int ret = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch <= '9' && ch >= '0') ret = ret * 10 + ch - '0', ch = getchar();
  return ret;
}
inline void Swap(int x, int y) {
  swap(heap[x], heap[y]);
  swap(Id[x], Id[y]);
}
inline void add(int x, int y, int z) {
  nxt[++tot] = lnk[x];
  lnk[x] = tot;
  son[tot] = y;
  w[tot] = z;
}
inline void Put(int id, long long x) {
  heap[Now = ++tot] = x;
  Id[tot] = id;
  while (Now > 1 && heap[Now] < heap[Now >> 1]) Swap(Now, Now >> 1), Now >>= 1;
}
inline int Get() {
  int Mi = Id[1];
  Id[1] = Id[tot], heap[1] = heap[tot], tot--, Now = 1;
  int Son = 2;
  while (Son <= tot) {
    if (Son < tot && heap[Son + 1] < heap[Son]) Son++;
    if (heap[Now] > heap[Son])
      Swap(Now, Son), Now = Son, Son = Now << 1;
    else
      break;
  }
  return Mi;
}
inline void Dij() {
  for (int i = 1; i <= n; i++) Nx[i] = vis[i] = 0, dis[i] = INF;
  tot = 0;
  for (int i = 1; i <= N; i++) dis[Q[i]] = 0, Nx[Q[i]] = Q[i], Put(Q[i], 0);
  while (tot) {
    int Nn = Get();
    if (vis[Nn]) continue;
    vis[Nn] = 1;
    for (int i = lnk[Nn]; i; i = nxt[i])
      if (!vis[son[i]] && dis[Nn] + w[i] < dis[son[i]])
        dis[son[i]] = dis[Nn] + w[i], Nx[son[i]] = Nx[Nn],
        Put(son[i], dis[son[i]]);
  }
}
inline int Getfa(int x) { return fa[x] == x ? x : fa[x] = Getfa(fa[x]); }
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++)
    x = read(), y = read(), z = read(), add(x, y, z), add(y, x, z),
    e[i] = (lc){x, y, z};
  Q[++N] = 1;
  tot = 0;
  Dij();
  N = read();
  for (int i = 1; i <= N; i++) Q[i] = read(), Ans = min(Ans, dis[Q[i]]);
  Dij();
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    e[i].z += dis[e[i].x] + dis[e[i].y];
    e[i].x = Nx[e[i].x], e[i].y = Nx[e[i].y];
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m; i++) {
    int fx = Getfa(e[i].x), fy = Getfa(e[i].y);
    if (fx == fy) continue;
    Ans += e[i].z;
    fa[fx] = fy;
  }
  printf("%lld", Ans);
  return 0;
}
