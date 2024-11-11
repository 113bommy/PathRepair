#include <bits/stdc++.h>
using namespace std;
long long n, m, u, cnt = 1, ch[4000005][4], dp[4000005][4], dpp[40][4][4];
long long rev[2][4], nw = 0, ans = 0;
char s[100005];
const long long inf = 2e18;
void dfs(int p) {
  for (int i = 0; i < 4; i++) dp[p][i] = inf;
  for (int i = 0; i < 4; i++) {
    if (!ch[p][i])
      dp[p][i] = 0;
    else {
      dfs(ch[p][i]);
      for (int j = 0; j < 4; j++) dp[p][j] = min(dp[p][j], dp[ch[p][i]][j] + 1);
    }
  }
}
int main() {
  scanf("%lld%s", &n, s + 1);
  m = strlen(s + 1);
  for (int i = 1; i <= m; i++) {
    int lim = min(m, 1ll * i + 39);
    u = 1;
    for (int j = i; j <= lim; j++) {
      int le = s[j] - 'A';
      if (!ch[u][le]) ch[u][le] = ++cnt;
      u = ch[u][le];
    }
  }
  dfs(1);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) dpp[0][i][j] = dp[ch[1][i]][j] + 1;
  for (int i = 1; i < 40; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        dpp[i][j][k] = inf;
        for (int u = 0; u < 4; u++)
          dpp[i][j][k] = min(dpp[i][j][k], dpp[i - 1][j][u] + dpp[i - 1][u][k]);
      }
    }
  }
  ans = 0;
  for (int i = 39; i >= 0; i--) {
    for (int j = 0; j < 4; j++) rev[!nw][j] = inf;
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        rev[!nw][k] = min(rev[!nw][k], rev[nw][j] + dpp[i][j][k]);
    long long sum = inf;
    for (int j = 0; j < 4; j++) sum = min(sum, rev[!nw][j]);
    if (sum < n) {
      ans += (1ll << i);
      for (int j = 0; j < 4; j++)
        if (rev[!nw][j] >= n) rev[!nw][j] = inf;
    } else
      for (int j = 0; j < 4; j++) rev[!nw][j] = rev[nw][j];
    nw = !nw;
  }
  printf("%lld\n", ans + 1);
  return 0;
}
