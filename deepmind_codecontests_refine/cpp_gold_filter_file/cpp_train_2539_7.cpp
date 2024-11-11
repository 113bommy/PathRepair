#include <bits/stdc++.h>
using namespace std;
int n, m, last;
int nxt[50505 * 11 * 2][26], link[50505 * 11 * 2], dp[50505 * 11 * 2],
    cnt[50505 * 11 * 2], ord[50505 * 11 * 2], occur[50505 * 11 * 2][11],
    f[50505 * 11 * 2];
char s[11][50505];
int l[11], r[11];
bool vis[50505 * 11 * 2];
void extend(int c) {
  if (nxt[last][c] && dp[nxt[last][c]] == dp[last] + 1) {
    last = nxt[last][c];
    return;
  }
  int x = last, y = last = ++m;
  dp[y] = dp[x] + 1;
  while (x && !nxt[x][c]) nxt[x][c] = y, x = link[x];
  if (!x)
    link[y] = 1;
  else {
    int z = nxt[x][c];
    if (dp[z] == dp[x] + 1)
      link[y] = z;
    else {
      int u = ++m;
      memcpy(nxt[u], nxt[z], sizeof nxt[u]);
      link[u] = link[z], link[z] = link[y] = u;
      dp[u] = dp[x] + 1;
      while (x && nxt[x][c] == z) nxt[x][c] = u, x = link[x];
    }
  }
}
int main() {
  scanf("%s", s[0]);
  last = ++m;
  for (int j = 0, len = strlen(s[0]); j < len; j++)
    extend(s[0][j] - 'a'), occur[last][0]++;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d %d", s[i], &l[i], &r[i]);
    last = 1;
    for (int j = 0, len = strlen(s[i]); j < len; j++)
      extend(s[i][j] - 'a'), occur[last][i]++;
  }
  for (int i = 1; i <= m; i++) cnt[dp[i]]++;
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= m; i++) ord[cnt[dp[i]]--] = i;
  for (int i = m; i >= 1; i--) {
    int x = ord[i];
    for (int j = 0; j <= n; j++) occur[link[x]][j] += occur[x][j];
  }
  for (int i = 1; i <= m; i++)
    if (occur[i][0]) {
      bool ok = 1;
      for (int j = 1; j <= n && ok; j++) {
        if (occur[i][j] < l[j] || occur[i][j] > r[j]) ok = 0;
      }
      if (ok) f[i] = dp[i] - dp[link[i]];
    }
  long long ans = 0;
  int x = 1;
  for (int i = 0, len = strlen(s[0]); i < len; i++) {
    x = nxt[x][s[0][i] - 'a'];
    for (int y = x; y && !vis[y]; y = link[y]) ans += f[y], vis[y] = 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
