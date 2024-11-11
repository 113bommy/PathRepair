#include <bits/stdc++.h>
using namespace std;
struct transf {
  int S, T, F;
};
int a[305], b[305];
int p[305];
long long s[305];
vector<int> e[305];
transf tr[2 * 305 * 305];
int n, m, v, k;
bool flag;
int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
void prt(int x, int y, int z) {
  if (z) {
    k++;
    tr[k].S = x;
    tr[k].T = y;
    tr[k].F = z;
    a[x] -= z;
    a[y] += z;
  }
}
void pre(int x, int fa) {
  s[x] = a[x] - b[x];
  for (int i = 0; i < e[x].size(); i++) {
    int y = e[x][i];
    if (y != fa) {
      pre(y, x);
      s[x] += s[y];
    }
  }
}
void dfs(int x, int fa, int z) {
  int y, w, t;
  for (int i = 0; i < e[x].size(); i++) {
    y = e[x][i];
    if (y != fa)
      if (s[y] > 0 && (w = s[y] < z ? s[y] : z) > 0) {
        z -= w;
        if (a[y] >= w) {
          prt(y, x, w);
          if (a[y] < b[y]) dfs(y, x, b[y] - a[y]);
        } else {
          t = a[y];
          prt(y, x, t);
          dfs(y, x, w);
          prt(y, x, w - t);
        }
      }
  }
}
int main() {
  while (scanf("%d%d%d", &n, &v, &m) != EOF) {
    for (int i = 1; i <= n; i++) p[i] = i, e[i].clear();
    k = 0;
    memset(tr, 0, sizeof(tr));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (find(x) != find(y)) {
        p[find(x)] = find(y);
        e[x].push_back(y);
        e[y].push_back(x);
      }
    }
    memset(s, 0, sizeof(s));
    flag = true;
    for (int i = 1; i <= n; i++) s[find(i)] += a[i] - b[i];
    for (int i = 1; i <= n; i++)
      if (s[i] > 0) {
        puts("NO");
        flag = false;
        break;
      }
    if (!flag) continue;
    for (int i = 1; i <= n; i++)
      if (a[i] < b[i]) {
        pre(i, 0);
        dfs(i, 0, b[i] - a[i]);
      }
    printf("%d\n", k);
    for (int i = 1; i <= k; i++)
      printf("%d %d %d\n", tr[i].S, tr[i].T, tr[i].F);
  }
  return 0;
}
