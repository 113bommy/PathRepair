#include <bits/stdc++.h>
using namespace std;
int head[5005];
int deg[5005];
int nxt[10005];
int to[10005];
int f[5005][5005][2];
int n, tot, cnt, root = 1;
int siz[5005];
void dfs(int x, int fa) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    dfs(to[i], x);
    siz[x] += siz[to[i]];
  }
  if (!siz[x]) {
    f[x][1][1] = f[x][0][0] = 0;
    ++cnt;
    siz[x] = 1;
    return;
  } else {
    f[x][0][1] = f[x][0][0] = 0;
  }
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    for (int j = siz[x]; j >= 0; --j) {
      int tmpa = 0x3f3f3f3f, tmpb = 0x3f3f3f3f;
      for (int k = 0; k <= siz[to[i]]; ++k) {
        if (k > j) continue;
        tmpa = min(tmpa, f[x][j - k][0] + f[to[i]][k][1] + 1);
        tmpa = min(tmpa, f[x][j - k][0] + f[to[i]][k][0]);
        tmpb = min(tmpb, f[x][j - k][1] + f[to[i]][k][1]);
        tmpb = min(tmpb, f[x][j - k][1] + f[to[i]][k][0] + 1);
      }
      f[x][j][0] = tmpa;
      f[x][j][1] = tmpb;
    }
  }
}
int main() {
  memset(f, 0x3f, sizeof(f));
  scanf("%d", &n);
  for (int x, y, i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    nxt[++tot] = head[x], head[x] = tot, to[tot] = y;
    nxt[++tot] = head[y], head[y] = tot, to[tot] = x;
    ++deg[x], ++deg[y];
  }
  while (deg[root] == 1) ++root;
  dfs(1, 0);
  printf("%d", min(f[root][cnt >> 1][0], f[root][cnt >> 1][1]));
  return 0;
}
