#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y;
} e[15];
struct node {
  int x, y, g;
} a[105];
bool chk(int x, int st) { return ((1 << x - 1) & st) != 0; }
int n, m, q;
int g[15][15];
long long f[15][((1 << 13) + 5)];
long long dfs(int x, int st) {
  if (f[x][st] != -1) return f[x][st];
  f[x][st] = 0;
  st ^= (1 << x - 1);
  int p = 1;
  while (!chk(p, st)) p++;
  for (int s = st; s; s = (s - 1) & st) {
    if (!chk(p, s)) continue;
    int flag = 1;
    for (int i = 1; i <= q; i++) {
      if (a[i].g == x && chk(a[i].x, s) && chk(a[i].y, s)) flag = 0;
      if (chk(a[i].g, s) && (!chk(a[i].x, s) || !chk(a[i].y, s))) flag = 0;
      if (!flag) break;
    }
    if (!flag) continue;
    for (int i = 1; i <= m; i++) {
      if (e[i].x != x && e[i].y != x && chk(e[i].x, s) != chk(e[i].y, s))
        flag = 0;
      if (!flag) break;
    }
    if (!flag) continue;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (g[x][i] && chk(i, s)) cnt++, p = i;
    }
    if (cnt > 1)
      continue;
    else if (cnt == 1)
      f[x][st ^ (1 << x - 1)] += dfs(p, s) * dfs(x, st ^ (1 << x - 1) ^ s);
    else {
      for (int i = 1; i <= n; i++) {
        if (chk(i, s))
          f[x][st ^ (1 << x - 1)] += dfs(i, s) * dfs(x, st ^ (1 << x - 1) ^ s);
      }
    }
  }
  return f[x][st ^ (1 << x - 1)];
}
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &e[i].x, &e[i].y);
    g[e[i].x][e[i].y] = g[e[i].y][e[i].x] = 1;
  }
  for (int i = 1; i <= q; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].g);
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; i++) {
    f[i][1 << (i - 1)] = 1;
  }
  cout << dfs(1, (1 << n) - 1) << endl;
  return 0;
}
