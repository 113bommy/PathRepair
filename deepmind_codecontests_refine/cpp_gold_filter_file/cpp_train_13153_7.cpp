#include <bits/stdc++.h>
using namespace std;
int n, m, t, K, las[101000], nxt[101000], to[101000], dat[101000], id[101000],
    S, T, tot = 1, d[101000], SS, TT, fl[101000], bz[101000], que[101000],
          e[101000][2], use[101000], ans[101000];
int co[610][310];
void putin(int x, int y, int z1) {
  nxt[++tot] = las[x];
  las[x] = tot;
  to[tot] = y;
  dat[tot] = z1;
  nxt[++tot] = las[y];
  las[y] = tot;
  to[tot] = x;
  dat[tot] = 0;
}
void link(int x, int y, int z1, int z2) {
  putin(x, y, z2 - z1);
  fl[x] = fl[x] - z1;
  fl[y] = fl[y] + z1;
}
bool bfs() {
  int he = 0, ta = 1;
  memset(bz, 0, sizeof(bz));
  que[1] = SS;
  bz[SS] = 1;
  while (he < ta) {
    int x = que[++he];
    for (int i = las[x]; i; i = nxt[i])
      if (dat[i]) {
        int y = to[i];
        if (bz[y] == 0) {
          que[++ta] = y;
          bz[y] = bz[x] + 1;
        }
      }
  }
  return bz[TT] > 0;
}
int dfs(int x, int t) {
  if (x == TT) return t;
  int ans = 0;
  for (int i = las[x]; i; i = nxt[i])
    if (dat[i]) {
      int y = to[i];
      if (bz[y] != bz[x] + 1) continue;
      int qq = dfs(y, min(t, dat[i]));
      dat[i] -= qq;
      dat[i ^ 1] += qq;
      ans += qq;
      t -= qq;
      if (t == 0) return ans;
    }
  if (ans == 0) bz[x] = -1;
  return ans;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &t, &K);
  for (int i = 1; i <= t; i++) scanf("%d%d", &e[i][0], &e[i][1]);
  S = n + m + 1;
  T = S + 1;
  SS = T + 1;
  TT = SS + 1;
  for (int k = 1; k <= K; k++) {
    memset(d, 0, sizeof(d));
    memset(fl, 0, sizeof(fl));
    memset(las, 0, sizeof(las));
    tot = 1;
    for (int i = 1; i <= t; i++)
      if (!use[i]) {
        link(e[i][0], n + e[i][1], 0, 1);
        d[e[i][0]]++;
        d[n + e[i][1]]++;
        id[i] = tot ^ 1;
      }
    for (int i = 1; i <= n; i++)
      link(S, i, d[i] / (K - k + 1), (d[i] - 1) / (K - k + 1) + 1);
    for (int i = 1; i <= m; i++)
      link(i + n, T, d[i + n] / (K - k + 1), (d[i + n] - 1) / (K - k + 1) + 1);
    for (int i = 1; i <= T; i++)
      if (fl[i] > 0)
        putin(SS, i, fl[i]);
      else
        putin(i, TT, -fl[i]);
    link(T, S, 0, 0x7fffffff);
    while (bfs()) dfs(SS, 0x7fffffff);
    for (int i = 1; i <= t; i++)
      if (use[i] == 0 && dat[id[i]] == 0) ans[i] = k, use[i] = 1;
  }
  for (int i = 1; i <= t; i++) {
    co[e[i][0]][ans[i]]++;
    co[e[i][1] + n][ans[i]]++;
  }
  int ans1 = 0;
  for (int i = 1; i <= n + m; i++) {
    int mx = 0;
    for (int j = 1; j <= K; j++)
      for (int k = j + 1; k <= K; k++) mx = max(mx, abs(co[i][j] - co[i][k]));
    ans1 += mx;
  }
  printf("%d\n", ans1);
  for (int i = 1; i <= t; i++) printf("%d ", ans[i]);
  printf("\n");
}
