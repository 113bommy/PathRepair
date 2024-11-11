#include <bits/stdc++.h>
using namespace std;
long long f[10];
int n, m;
bool vis[51][51];
int s[1 << 21];
int cnt[51];
void dfs(int i, int S) {
  if (i > n / 2) {
    s[S]++;
    return;
  }
  dfs(i + 1, S);
  if (cnt[i]) return;
  for (int j = i + 1; j <= n / 2; j++) cnt[j] += vis[i][j];
  dfs(i + 1, S | (1 << (i - 1)));
  for (int j = i + 1; j <= n / 2; j++) cnt[j] -= vis[i][j];
  return;
}
void work() {
  int N = n / 2;
  for (int step = 1; step < (1 << N); step <<= 1)
    for (int i = 0; i < (1 << N); i += step << 1)
      for (int j = i; j < i + step; j++) s[j + step] += s[j];
  return;
}
void dfs2(int i, int S) {
  if (i > n) {
    f[1] += s[S];
    return;
  }
  dfs2(i + 1, S);
  if (cnt[i]) return;
  for (int j = i + 1; j <= n; j++) cnt[j] += vis[i][j];
  for (int j = 1; j <= n / 2; j++)
    if (vis[i][j] && (S & (1 << (j - 1)))) S ^= 1 << (j - 1);
  dfs2(i + 1, S);
  for (int j = i + 1; j <= n; j++) cnt[j] -= vis[i][j];
  return;
}
bool book[51];
void dfs3(int u) {
  book[u] = true;
  for (int i = 1; i <= n; i++)
    if (vis[u][i] && !book[i]) dfs3(i);
  return;
}
int col[51];
bool can = true;
void dfs4(int u) {
  for (int i = 1; can && i <= n; i++)
    if (vis[u][i]) {
      if (!col[i]) {
        col[i] = 3 - col[u];
        dfs4(i);
      } else if (col[i] != 3 - col[u])
        can = false;
    }
}
int main() {
  scanf("%d %d", &n, &m);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    vis[u][v] = true;
    vis[v][u] = true;
  }
  f[0] = 1ll << n;
  dfs(1, 0);
  work();
  dfs2(n / 2 + 1, (1 << (n / 2)) - 1);
  f[2] = 1;
  for (int i = 1; i <= n; i++)
    if (!book[i]) {
      dfs3(i);
      f[2] <<= 1;
    }
  f[3] = f[1];
  f[4] = 1;
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = 1; j <= n; j++)
      if (vis[i][j]) flag = false;
    if (flag) f[4] <<= 1;
  }
  for (int i = 1; can && i <= n; i++)
    if (!col[i]) {
      col[i] = 1;
      dfs4(i);
    }
  if (can)
    f[5] = f[2];
  else
    f[5] = 0;
  f[6] = f[4];
  if (m == 0)
    f[7] = 1ll << n;
  else
    f[7] = 0;
  printf("%I64d\n", f[0] - f[1] - f[2] - f[3] + f[4] + f[5] + f[6] - f[7]);
  return 0;
}
