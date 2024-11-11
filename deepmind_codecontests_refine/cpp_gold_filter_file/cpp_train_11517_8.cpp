#include <bits/stdc++.h>
using namespace std;
const int inf = ~0u >> 1, MOD = 1e9 + 7;
inline int rd() {
  int first = 0, c = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar()) f = c != '-';
  for (; c >= '0' && c <= '9'; c = getchar()) first = first * 10 + c - '0';
  return f ? first : -first;
}
const int N = 2e5 + 11;
struct Edge {
  int v, id;
  Edge *nex;
} pl[N << 1], *cur = pl, *G[N];
void ins(int u, int v, int id) {
  cur->v = v, cur->id = id;
  cur->nex = G[u], G[u] = cur++;
}
int wx[N], wy[N], n, m;
int f[N], vis[N], g[N];
void dfs(int first) {
  vis[first] = 1;
  for (Edge *i = G[first]; i; i = i->nex)
    if (!vis[i->v]) {
      dfs(i->v);
      if (f[i->v]) {
        f[i->v] = 0;
        f[first] ^= 1;
        g[i->id] ^= 1;
      }
    }
}
int q[N];
int main() {
  n = rd(), m = rd();
  for (int i = (1), i_end = (m); i <= i_end; i++) {
    wx[i] = rd(), wy[i] = rd();
    ins(wx[i], wy[i], i), ins(wy[i], wx[i], i);
    f[wx[i]] ^= 1;
  }
  for (int i = (1), i_end = (n); i <= i_end; i++)
    if (!vis[i]) dfs(i);
  int ans = m;
  for (int i = (1), i_end = (n); i <= i_end; i++)
    if (f[i]) ans--;
  printf("%d\n", ans >> 1);
  for (int first = (1), x_end = (n); first <= x_end; first++) {
    int cnt = 0;
    for (Edge *i = G[first]; i; i = i->nex)
      if ((wy[i->id] != first) ^ g[i->id]) {
        q[++cnt] = (wx[i->id] ^ wy[i->id] ^ first);
      }
    for (int i = 1; i < cnt; i += 2) {
      printf("%d %d %d\n", q[i], first, q[i + 1]);
    }
  }
}
