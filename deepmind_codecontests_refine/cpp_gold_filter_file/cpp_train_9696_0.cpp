#include <bits/stdc++.h>
using namespace std;
const int N = 805, M = 2005, INF = 1000000000;
char a[N], b[N];
bool vis[M][N * 20];
int n, m, f[M][N * 20], g[N * 20][M], ans, tot;
int q[N * 20], head, tail, fail[N * 20], t[N * 20][10];
int T(int x, int c) {
  if (!t[x][c]) t[x][c] = ++tot;
  return t[x][c];
}
void build() {
  tot = 1;
  for (int i = 1; i <= n; ++i) a[i] -= 48;
  for (int i = 1; i <= m; ++i) b[i] -= 48;
  if (n == m) {
    int x = 1, y = 1;
    for (int i = 1; i <= n; ++i) {
      if (x == y) {
        for (int c = a[i] + 1; c <= b[i] - 1; ++c) ++g[T(x, c)][n - i];
      } else {
        for (int c = a[i] + 1; c <= 9; ++c) ++g[T(x, c)][n - i];
        for (int c = i > 1 ? 0 : 1; c <= b[i] - 1; ++c) ++g[T(y, c)][n - i];
      }
      x = T(x, a[i]);
      y = T(y, b[i]);
    }
    ++g[x][0];
    if (x != y) ++g[y][0];
  } else {
    int x = 1;
    for (int i = 1; i <= n; ++i) {
      for (int c = a[i] + 1; c <= 9; ++c) ++g[T(x, c)][n - i];
      x = T(x, a[i]);
    }
    ++g[x][0], x = 1;
    for (int i = 1; i <= m; ++i) {
      for (int c = i > 1 ? 0 : 1; c <= b[i] - 1; ++c) ++g[T(x, c)][m - i];
      x = T(x, b[i]);
    }
    ++g[x][0];
    for (int i = n + 1; i <= m - 1; ++i)
      for (int c = 1; c <= 9; ++c) ++g[T(1, c)][i - 1];
  }
}
void acam() {
  for (int i = 0; i <= 9; ++i) t[0][i] = 1;
  q[head = tail = 0] = 1;
  while (head <= tail) {
    int x = q[head++];
    for (int i = 0; i <= 9; ++i)
      if (t[x][i]) {
        q[++tail] = t[x][i];
        int k = fail[x];
        while (!t[k][i]) k = fail[k];
        fail[t[x][i]] = t[k][i];
      }
    for (int i = 0; i <= M - 1; ++i) g[x][i] += g[fail[x]][i];
  }
  for (int i = 1; i <= tot; ++i) {
    for (int j = 0; j <= 9; ++j) {
      int x = i;
      while (!t[x][j]) x = fail[x];
      t[i][j] = t[x][j];
    }
  }
  for (int x = 1; x <= tot; ++x)
    for (int i = 1; i <= M - 1; ++i) g[x][i] += g[x][i - 1];
}
void dp() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= tot; ++j) f[i][j] = -INF;
  f[0][1] = 0;
  for (int i = 0; i <= n - 1; ++i)
    for (int j = 1; j <= tot; ++j)
      if (f[i][j] >= 0)
        for (int c = 0; c <= 9; ++c) {
          int tmp = f[i][j] + g[t[j][c]][n - i - 1];
          f[i + 1][t[j][c]] = max(f[i + 1][t[j][c]], tmp);
        }
  ans = -INF;
  for (int i = 1; i <= tot; ++i) ans = max(ans, f[n][i]);
  for (int i = 1; i <= tot; ++i)
    if (ans == f[n][i]) vis[n][i] = 1;
  printf("%d\n", ans);
}
void pre() {
  for (int i = n - 1; i >= 0; --i)
    for (int j = 1; j <= tot; ++j)
      if (f[i][j] >= 0)
        for (int c = 0; c <= 9; ++c) {
          int tmp = f[i][j] + g[t[j][c]][n - i - 1];
          if (f[i + 1][t[j][c]] == tmp) vis[i][j] |= vis[i + 1][t[j][c]];
        }
}
void dfs(int L, int x) {
  if (L == n) return;
  for (int c = 0; c <= 9; ++c) {
    if (vis[L + 1][t[x][c]] &&
        f[L + 1][t[x][c]] == f[L][x] + g[t[x][c]][n - L - 1]) {
      printf("%d", c);
      dfs(L + 1, t[x][c]);
      return;
    }
  }
}
int main() {
  scanf("%s", a + 1), n = strlen(a + 1);
  scanf("%s", b + 1), m = strlen(b + 1);
  build();
  acam();
  dp();
  pre();
  dfs(0, 1);
  puts("");
  return 0;
}
