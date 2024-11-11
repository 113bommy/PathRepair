#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, k1, fa[N], c[N], mx[N], q[N], d[N];
int mxx, rt1, rt2;
bool in[N];
vector<int> g[N];
void fail() {
  printf("No\n");
  exit(0);
}
void dfs(int x, int d, int f = -1) {
  if (d > mxx) mxx = d, rt2 = x;
  for (int i = 0; i < g[x].size(); ++i)
    if (g[x][i] != f) {
      dfs(g[x][i], d + 1, x);
    }
}
void dfs1(int x) {
  for (int i = 0; i < g[x].size(); ++i)
    if (g[x][i] != fa[x]) {
      int y = g[x][i];
      fa[y] = x;
      d[y] = d[x] + 1;
      dfs1(y);
    }
}
void dfs2(int x) {
  mx[x] = !in[x];
  for (int i = 0; i < g[x].size(); ++i)
    if (g[x][i] != fa[x]) {
      int y = g[x][i];
      dfs2(y);
      mx[x] = max(mx[x], mx[y] + (!in[x]));
    }
}
void dfs3(int x, int d) {
  for (int i = 0; i < g[x].size(); ++i)
    if (g[x][i] != fa[x] && !in[g[x][i]]) {
      int y = g[x][i];
      c[y] = (c[x] + d + k) % k;
      dfs3(y, d);
    }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  rt1 = rt2;
  mxx = 0;
  dfs(rt1, 0);
  dfs1(rt1);
  for (int x = rt2;; x = fa[x]) {
    c[x] = k1++;
    k1 %= k;
    in[x] = 1;
    q[++q[0]] = x;
    if (x == rt1) break;
  }
  dfs2(rt1);
  if (k == 1) {
    printf("Yes\n");
    for (int i = 1; i <= n; ++i) printf("%d ", 1);
    return 0;
  }
  if (k == 2) {
    printf("Yes\n");
    for (int i = 1; i <= n; ++i) printf("%d ", (d[i] & 1) + 1);
    return 0;
  }
  for (int t = 1; t <= q[0]; ++t) {
    int x = q[t];
    for (int i = 0; i < g[x].size(); ++i)
      if (g[x][i] != fa[x] && !in[g[x][i]]) {
        int y = g[x][i];
        bool flag1 = (mx[y] + t) >= k;
        bool flag2 = (mx[y] + q[0] - t + 1) >= k;
        if (flag1 && flag2) fail();
      }
    dfs3(rt1, (t <= q[0] / 2) ? -1 : 1);
  }
  printf("Yes\n");
  for (int i = 1; i <= n; ++i) printf("%d ", c[i] + 1);
}
