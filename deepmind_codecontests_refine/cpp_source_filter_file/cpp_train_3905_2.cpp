#include <bits/stdc++.h>
const int N = 1e3 + 2, M = 2.5e4 + 2, K = 52, p = 1e9 + 7;
int dp[M][K][2][2], c[M][10], f[M], dl[M], s[N], s1[K], s2[K];
int n, m, i, j, k, tou = 1, wei, cc, d, ds, x;
bool ed[M];
inline void add(int &x, int y) {
  if ((x = x + y) >= p) x -= p;
}
int sol(int a[], int typ) {
  int ans = 0;
  memset(dp, 0, sizeof(dp));
  dp[0][0][1][0] = 1;
  for (i = 0; i < d; i++)
    for (j = 0; j <= ds; j++) {
      for (k = 0; k <= 9; k++) {
        add(dp[i + 1][c[j][k]][0][1], dp[i][j][0][1]);
        if (ed[c[j][k]])
          add(dp[i + 1][c[j][k]][0][1], dp[i][j][0][0]);
        else
          add(dp[i + 1][c[j][k]][0][0], dp[i][j][0][0]);
      }
      for (k = 0; k < a[i + 1]; k++) {
        add(dp[i + 1][c[j][k]][0][1], dp[i][j][1][1]);
        if (ed[c[j][k]])
          add(dp[i + 1][c[j][k]][0][1], dp[i][j][1][0]);
        else
          add(dp[i + 1][c[j][k]][0][0], dp[i][j][1][0]);
      }
      k = a[i + 1];
      add(dp[i + 1][c[j][k]][1][1], dp[i][j][1][1]);
      if (ed[c[j][k]])
        add(dp[i + 1][c[j][k]][1][1], dp[i][j][1][0]);
      else
        add(dp[i + 1][c[j][k]][1][0], dp[i][j][1][0]);
    }
  for (i = 0; i <= ds; i++) add(ans, dp[d][i][0][1]);
  if (typ)
    for (i = 0; i <= ds; i++) add(ans, dp[d][i][1][1]);
  return ans;
}
int main() {
  cc = getchar();
  while ((cc < 48) || (cc > 57)) cc = getchar();
  while ((cc >= 48) && (cc <= 57)) {
    s[++n] = cc ^ 48;
    cc = getchar();
  }
  cc = getchar();
  while ((cc < 48) || (cc > 57)) cc = getchar();
  while ((cc >= 48) && (cc <= 57)) {
    s1[++d] = cc ^ 48;
    cc = getchar();
  }
  cc = getchar();
  while ((cc < 48) || (cc > 57)) cc = getchar();
  s2[1] = cc ^ 48;
  m = d >> 1;
  n = n - m + 1;
  for (i = 2; i <= d; i++) s2[i] = getchar() ^ 48;
  for (i = 1; i <= n; ed[x] = 1, i++)
    for (x = j = 0; j < m; j++)
      if (c[x][s[i + j]])
        x = c[x][s[i + j]];
      else
        x = c[x][s[i + j]] = ++ds;
  for (i = 0; i <= 9; i++)
    if (c[0][i]) dl[++wei] = c[0][i];
  while (tou <= wei)
    for (x = dl[tou++], i = 0; i <= 9; i++)
      if (c[x][i])
        f[dl[++wei] = c[x][i]] = c[f[x]][i];
      else
        c[x][i] = c[f[x]][i];
  printf("%d", (sol(s2, 1) - sol(s1, 0) + p) % p);
}
