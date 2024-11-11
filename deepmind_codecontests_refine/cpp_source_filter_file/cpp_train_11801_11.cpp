#include <bits/stdc++.h>
int next[16][500020], MAXS, n;
char a[16][12], b[5000020][12];
int cost[1 << 16][15], dp[1 << 16][200], simu[15];
int solve(int k) {
  memset(next, -1, sizeof(next));
  int i, j, tmp, inv, st, st2, maxinv = 0;
  for (i = 0; i < n; i++) {
    tmp = k + 1;
    for (j = k; j >= 1; j--) {
      next[i][j] = tmp;
      if (strcmp(a[i], b[j]) == 0) {
        next[i][j] = tmp;
        tmp = j;
      }
    }
    next[i][0] = tmp;
  }
  memset(dp, -1, sizeof(dp));
  memset(dp[0], 0, sizeof(dp[0]));
  for (st = 0; st <= MAXS; st++)
    for (j = 0; j <= maxinv; j++) {
      if (dp[st][j] == -1) continue;
      for (i = 0; i < n; i++)
        if (next[i][dp[st][j]] <= k)
          if (((1 << i) & st) == 0) {
            st2 = st | (1 << i);
            inv = j + cost[st][i];
            if (dp[st2][inv] == -1 || next[i][dp[st][j]] < dp[st2][inv]) {
              dp[st2][inv] = next[i][dp[st][j]];
              if (inv > maxinv) maxinv = inv;
            }
          }
    }
  for (i = 0; i <= maxinv; i++)
    if (dp[MAXS][i] > -1) break;
  return i == k + 1 ? -1 : i;
}
int main() {
  scanf("%d", &n);
  int i, st, j, k, m, mm, len, inver, ans = 1;
  MAXS = (1 << n) - 1;
  for (i = 0; i < n; i++) scanf("%s", a[i]);
  for (st = 0; st <= MAXS; st++)
    for (i = 0; i < n; i++)
      if (((1 << i) & st) == 0)
        for (j = i + 1; j < n; j++)
          if ((1 << j) & st) cost[st][i]++;
  scanf("%d", &m);
  for (mm = 1; mm <= m; mm++) {
    scanf("%d", &len);
    for (j = 1, k = 0; j <= len; j++) {
      scanf("%s", b[++k]);
      for (i = 0; i < n; i++)
        if (strcmp(b[k], a[i]) == 0) break;
      if (i == n) k--;
    }
    inver = solve(k);
    if (inver == -1)
      simu[mm] = -1;
    else
      simu[mm] = n * (n - 1) / 2 - inver + 1;
    if (simu[mm] > simu[ans]) ans = mm;
  }
  if (simu[ans] == -1)
    printf("Brand new problem!\n");
  else {
    printf("%d\n", ans);
    printf("[:");
    for (i = 1; i <= simu[ans]; i++) printf("|");
    printf(":]");
  }
}
