#include <bits/stdc++.h>
using namespace std;
int head[5010];
int from[5010];
int to[100010];
int nex[100010];
int dep[5010];
int q[5010];
int cnt;
int vis[5010];
int bel[5010];
int num[100010];
double ans;
int tot;
int x, y, n, m;
int f[5010][17];
void add(int x, int y, int z) {
  nex[++tot] = head[x];
  head[x] = tot;
  to[tot] = y;
  num[tot] = z;
}
bool dfs(int x, int fa) {
  vis[x] = 1;
  for (int i = head[x]; i; i = nex[i]) {
    if (num[i] != fa) {
      if (vis[to[i]]) {
        for (int j = x; j != to[i]; j = from[j]) {
          q[++cnt] = j;
        }
        q[++cnt] = to[i];
        return true;
      } else {
        from[to[i]] = x;
        if (dfs(to[i], num[i])) {
          return true;
        }
      }
    }
  }
  return false;
}
void find(int x, int fa, int rt) {
  bel[x] = rt;
  dep[x] = dep[fa] + 1;
  f[x][0] = fa;
  for (int i = 1; i <= 15; i++) {
    f[x][i] = f[f[x][i - 1]][i - 1];
  }
  for (int i = head[x]; i; i = nex[i]) {
    if (to[i] != fa && !vis[to[i]]) {
      find(to[i], x, rt);
    }
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  int d = dep[x] - dep[y];
  for (int i = 0; i <= 15; i++) {
    if (d & (1 << i)) {
      x = f[x][i];
    }
  }
  if (x == y) {
    return x;
  }
  for (int i = 15; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    x++, y++;
    add(x, y, i);
    add(y, x, i);
  }
  dfs(1, 0);
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= cnt; i++) {
    vis[q[i]] = 1;
  }
  for (int i = 1; i <= cnt; i++) {
    find(q[i], 0, i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (bel[i] == bel[j]) {
        ans += (double)1 / (dep[i] + dep[j] - 2 * dep[lca(i, j)] + 1);
      } else {
        int X = dep[i] + dep[j];
        int Y = abs(bel[i] - bel[j]) - 1;
        int Z = cnt - Y - 2;
        ans +=
            (double)1 / (X + Y) + (double)1 / (X + Z) - (double)1 / (X + Y + Z);
      }
    }
  }
  printf("%.7f", ans);
}
