#include <bits/stdc++.h>
using namespace std;
const int mn = 2005;
int n, m, k;
struct edge {
  int u, v, color, id;
  int to(int x) { return x == u ? v : u; }
} e[100005];
int d[mn];
int usedcolor[mn][mn];
int ans;
void dfs(int x, int c1, int c2) {
  edge &E = e[usedcolor[x][c1]];
  int nxt = E.to(x);
  if (usedcolor[nxt][c2])
    dfs(nxt, c2, c1);
  else
    usedcolor[nxt][c1] = 0;
  E.color = c2;
  usedcolor[nxt][c2] = E.id;
  usedcolor[x][c2] = E.id;
}
void paint() {
  for (int i = 1; i <= k; i++) {
    if (!e[i].color) {
      int c1 = -1, c2 = 0;
      bool flag = 0;
      for (int j = 1; j <= ans; j++) {
        if (!usedcolor[e[i].u][j]) c1 = j;
        if (!usedcolor[e[i].v][j]) c2 = j;
        if (c1 == c2) {
          flag = 1;
          break;
        }
      }
      if (!flag) dfs(e[i].v, c1, c2);
      e[i].color = c1;
      usedcolor[e[i].u][c1] = i;
      usedcolor[e[i].v][c1] = i;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[i].u = u;
    e[i].v = v + n;
    d[u]++;
    d[v + n]++;
    e[i].id = i;
  }
  for (int i = 1; i <= n + m; i++) ans = max(ans, d[i]);
  printf("%d\n", ans);
  paint();
  for (int i = 1; i <= k; i++) printf("%d ", e[i].color);
  return 0;
}
