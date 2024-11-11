#include <bits/stdc++.h>
using namespace std;
int n, h, to[5001 * 2], head[5001], nxt[5001 * 2];
int p[5001], f[5001][5001], op[5001];
void add(int u, int v) {
  to[++h] = v;
  nxt[h] = head[u];
  head[u] = h;
}
void dfs(int d, int fa) {
  p[d] = 1;
  f[d][0] = 1;
  for (int i = head[d]; i; i = nxt[i]) {
    int j = to[i];
    if (j != fa) {
      dfs(j, d);
      p[d] += p[j];
      for (int i = n - 2; i >= p[j]; i--) f[d][i] |= f[d][i - p[j]];
    }
  }
  int fu = n - 1 - p[d];
  for (int i = n - 2; i >= fu; i--) {
    f[d][i] |= f[d][i - fu];
  }
  for (int i = 1; i < n - 1; i++) op[i] |= f[d][i];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 1; i < n - 1; i++)
    if (op[i]) ans++;
  printf("%d\n", ans);
  for (int i = 1; i < n - 1; i++) {
    if (op[i]) {
      printf("%d %d\n", i, n - 1 - i);
    }
  }
}
