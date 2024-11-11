#include <bits/stdc++.h>
using namespace std;
namespace INPUT {
const int L = 1 << 15;
char _buf[L], *S, *T, c;
char _gc() {
  if (S == T) {
    T = (S = _buf) + fread(_buf, 1, L, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
void readi(int &X) {
  for (c = _gc(); c < '0' || c > '9'; c = _gc())
    ;
  X = c & 15;
  for (c = _gc(); c >= '0' && c <= '9'; X = X * 10 + (c & 15), c = _gc())
    ;
}
}  // namespace INPUT
using INPUT::readi;
const int Maxn = 5E4 + 5;
int N, Q;
int a[Maxn];
struct E {
  int v, nxt;
} adj[Maxn << 1];
int hed[Maxn], TE;
int dep[Maxn];
int fa[Maxn], _fa[Maxn];
int mx[Maxn][257];
bool is[Maxn][512];
int mxx[Maxn][257];
void addedge(int u, int v) {
  adj[++TE].v = v, adj[TE].nxt = hed[u], hed[u] = TE;
}
void Dfs(int u, int Fa) {
  fa[u] = Fa, dep[u] = dep[Fa] + 1;
  for (int k = hed[u]; ~k; k = adj[k].nxt)
    if (adj[k].v != Fa) Dfs(adj[k].v, u);
}
int main() {
  readi(N), readi(Q);
  for (int i = 1; i <= N; ++i) readi(a[i]);
  memset(hed, -1, sizeof(hed));
  for (int u, v, i = 1; i < N; ++i)
    readi(u), readi(v), addedge(u, v), addedge(v, u);
  Dfs(1, 0);
  memset(mx, 0, sizeof(mx)), memset(is, false, sizeof(is));
  for (int i = 1; i <= N; ++i) {
    is[i][1] = true;
    if (dep[i] >= 256) {
      for (int u = i; dep[u] > dep[i] - 256; u = fa[u]) {
        int tmp = (a[u] >> 8), nd = 1;
        mx[i][tmp] = max(mx[i][tmp], (a[u] & 255) ^ (dep[i] - dep[u]));
        for (int k = 7; k >= 0; --k)
          nd = (nd << 1) | ((tmp >> k) & 1), is[i][nd] = true;
        _fa[i] = fa[u];
      }
      for (int j = 0; j < 256; ++j) {
        int tmp = 0, tmp2 = 0, nd = 1;
        for (int k = 7; k >= 0; --k) {
          int x = (((j >> k) & 1) == 0);
          if (!is[i][(nd << 1) | x])
            tmp += ((!x) << k), nd = (nd << 1) | (!x);
          else
            tmp += (x << k), tmp2 += (1 << k), nd = (nd << 1) | x;
        }
        mxx[i][j] = max(mxx[i][j], (tmp2 << 8) + mx[i][tmp]);
      }
    }
  }
  while (Q--) {
    int u, v, vv, Ans = 0;
    readi(u), readi(v), vv = v;
    int cnt = 0, tmp, tmp2, nd;
    while (dep[v] - 256 >= dep[u] - 1) {
      Ans = max(Ans, mxx[v][tmp]);
      v = _fa[v], ++cnt;
    }
    while (dep[v] >= dep[u])
      Ans = max(Ans, a[v] ^ (dep[vv] - dep[v])), v = fa[v];
    printf("%d\n", Ans);
  }
  return 0;
}
