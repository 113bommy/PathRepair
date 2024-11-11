#include <bits/stdc++.h>
const int fin = 0, maxn = 40;
int n, m, ans;
char g[maxn][maxn], ai[maxn][maxn];
int T[300], R[maxn][maxn];
int b[maxn][maxn], c[20], v[20];
int w[20][20], col[60];
bool check() {
  int i, j;
  memset(w, 0, sizeof(w));
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (g[i][j] != '.') col[R[i][j]] = c[b[i][j]];
  for (i = 0; i < 28; ++i) ++w[col[i]][col[i + 28]];
  for (i = 0; i < 7; ++i)
    for (j = i; j < 7; ++j)
      if (w[i][j] + ((i == j) ? 0 : w[j][i]) != 1) return 0;
  return 1;
}
void dfs(int n) {
  int i, j;
  if (n == 15) {
    if (check())
      if (++ans, ans == 1)
        for (i = 1; i <= n; ++i)
          for (j = 1; j <= m; ++j)
            if (g[i][j] != '.') ai[i][j] = c[b[i][j]] + '0';
    return;
  }
  for (i = 0; i < 7; ++i)
    if (v[i] == 1) {
      ++v[i], c[n] = i;
      dfs(n + 1);
      --v[i], c[n] = 0;
    }
  for (i = 0; i < 7 && v[i]; ++i)
    ;
  if (i != 7) {
    ++v[i], c[n] = i;
    dfs(n + 1);
    --v[i], c[n] = 0;
  }
}
int main() {
  if (fin) {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
  }
  int i, j, t;
  scanf("%d%d\n", &n, &m);
  for (i = 1; i <= n; ++i) gets(g[i] + 1);
  memcpy(ai, g, sizeof(g));
  for (i = 'a'; i <= 'z'; ++i) T[i] = i - 'a';
  for (i = 'A'; i <= 'B'; ++i) T[i] = i - 'A' + 26;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (g[i][j] != '.')
        if (t = T[g[i][j]], !v[t])
          v[t] = 1, R[i][j] = t;
        else
          R[i][j] = t + 28;
  for (t = 0, i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (g[i][j] != '.' && !b[i][j])
        b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = ++t;
  memset(v, 0, sizeof(v));
  dfs(1);
  printf("%I64d\n", (long long)ans * 5040LL);
  for (i = 1; i <= n; ++i) printf("%s\n", ai[i] + 1);
  return 0;
}
