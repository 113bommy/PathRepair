#include <bits/stdc++.h>
const int MAXN = 5010;
const int MAXM = MAXN * 2;
const int INF = 0x3f3f3f3f;
int n, head[MAXN], e[MAXM], next[MAXM], size;
int rt, d[MAXN], g[MAXN], fa[MAXN];
int f[MAXN][MAXN][2], t[MAXN][2];
inline void addEdge(int u, int v) {
  next[size] = head[u];
  e[size] = v;
  head[u] = size++;
}
inline void bAddEdge(int u, int v) {
  d[u]++;
  d[v]++;
  addEdge(u, v);
  addEdge(v, u);
}
inline int min(int a, int b) { return (a < b) ? a : b; }
void solve(int x, int fa) {
  if (d[x] == 1) {
    g[x] = 1;
    f[x][1][1] = f[x][0][0] = 0;
    return;
  }
  f[x][0][0] = f[x][0][1] = 0;
  g[x] = 0;
  for (int i = head[x]; i != -1; i = next[i]) {
    if (e[i] == fa) continue;
    solve(e[i], x);
    for (int a = 0; a <= g[x] + g[e[i]]; a++) t[a][0] = t[a][1] = INF;
    for (int a = 0; a <= g[x]; a++)
      for (int b = 0; b <= g[e[i]]; b++) {
        t[a + b][0] = min(t[a + b][0], f[x][a][0] + f[e[i]][b][0]);
        t[a + b][0] = min(t[a + b][0], f[x][a][0] + f[e[i]][b][1] + 1);
        t[a + b][1] = min(t[a + b][1], f[x][a][1] + f[e[i]][b][0] + 1);
        t[a + b][1] = min(t[a + b][1], f[x][a][1] + f[e[i]][b][1]);
      }
    g[x] += g[e[i]];
    for (int a = 0; a <= g[x]; a++) {
      f[x][a][0] = t[a][0];
      f[x][a][1] = t[a][1];
    }
  }
}
void lucky() {
  int u, v;
  memset(head, -1, sizeof(head));
  size = 0;
  memset(d, 0, sizeof(d));
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    bAddEdge(u, v);
  }
}
int main() {
  lucky();
  for (int i = 1; i <= n; i++)
    if (d[i] > 1) {
      rt = i;
      break;
    }
  memset(f, 0x3f, sizeof(f));
  solve(rt, 0);
  printf("%d\n", min(f[rt][g[rt] >> 1][0], f[rt][g[rt] >> 1][1]));
  return 0;
}
