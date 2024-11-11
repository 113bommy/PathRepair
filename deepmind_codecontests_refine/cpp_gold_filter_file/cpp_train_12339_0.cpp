#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2505;
int n, tot, Lowcost[MAXN], Dst[MAXN][MAXN], fa[MAXN], G[MAXN][MAXN];
bool vis[MAXN];
struct Edge {
  int tot, lnk[MAXN], son[MAXN << 1], nxt[MAXN << 1], W[MAXN << 1];
  void Add(int x, int y, int w) {
    son[++tot] = y;
    W[tot] = w;
    nxt[tot] = lnk[x];
    lnk[x] = tot;
  }
} E;
void DFS(int x, int fa, int s, int w) {
  Dst[s][x] = w;
  for (int j = E.lnk[x]; j; j = E.nxt[j])
    if (E.son[j] != fa) DFS(E.son[j], x, s, max(E.W[j], w));
}
char nc() {
  static char buf[100000], *L = buf, *R = buf;
  return (L == R && (R = (L = buf) + fread(buf, 1, 100000, stdin), L == R)
              ? EOF
              : *L++);
}
int read() {
  int ret = 0;
  char ch = nc();
  bool f = 1;
  for (; !isdigit(ch); ch = nc()) f ^= !(ch ^ '-');
  for (; isdigit(ch); ch = nc()) ret = ret * 10 + ch - 48;
  return f ? ret : -ret;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) G[i][j] = read();
  for (int i = 1; i <= n; i++)
    if (G[i][i]) {
      printf("NOT MAGIC\n");
      return 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (G[i][j] != G[j][i]) {
        printf("NOT MAGIC\n");
        return 0;
      }
  vis[1] = 1;
  for (int i = 2; i <= n; i++) Lowcost[i] = G[1][i], fa[i] = 1;
  for (int i = 1; i < n; i++) {
    int MIN = 1 << 30, k = 0;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && MIN > Lowcost[j]) MIN = Lowcost[j], k = j;
    vis[k] = 1;
    E.Add(fa[k], k, MIN), E.Add(k, fa[k], MIN);
    for (int j = 1; j <= n; j++)
      if (!vis[j] && G[k][j] < Lowcost[j]) fa[j] = k, Lowcost[j] = G[k][j];
  }
  for (int i = 1; i <= n; i++) DFS(i, 0, i, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (Dst[i][j] != G[i][j]) {
        printf("NOT MAGIC\n");
        return 0;
      }
  printf("MAGIC\n");
  return 0;
}
