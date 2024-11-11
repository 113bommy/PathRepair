#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct edge {
  int to, next;
} e[N * 2];
int head[N], tot;
int n, k, vis[N], lvl[N];
int dep[N], fa[N][20];
void add(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
}
void dfs(int x) {
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa[x][0]) {
      fa[e[i].to][0] = x;
      dep[e[i].to] = dep[x] + 1;
      dfs(e[i].to);
    }
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int tmp = dep[x] - dep[y];
  for (int i = (int)(18); i >= (int)(0); i--)
    if (tmp & (1 << i)) x = fa[x][i];
  for (int i = (int)(18); i >= (int)(0); i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return x == y ? x : fa[x][0];
}
int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[LCA(x, y)]; }
int findmx(int x) {
  int mxv = -1, mxid;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int val = dis(x, i);
    if (val > mxv) mxv = val, mxid = i;
  }
  return mxid;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1);
  if (k == 2) {
    puts("Yes");
    for (int i = (int)(1); i <= (int)(n); i++) printf("%d ", dep[i] % 2 + 1);
    return 0;
  }
  for (int i = (int)(1); i <= (int)(18); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      fa[j][i] = fa[fa[j][i - 1]][i - 1];
  int S = findmx(1);
  int T = findmx(S);
  int dia = dis(S, T);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int d1 = dis(S, i), d2 = dis(T, i);
    if (d1 + d2 == dia) vis[i] = 1, lvl[i] = d1;
  }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!vis[i]) {
      int d1 = dis(S, i), d2 = dis(T, i);
      if (d1 >= k - 1 && d2 >= k - 1) return puts("No"), 0;
      if (d1 >= d2)
        lvl[i] = d1;
      else
        lvl[i] = dia - d2;
    }
  puts("Yes");
  for (int i = (int)(1); i <= (int)(n); i++) printf("%d ", lvl[i] % k + 1);
}
