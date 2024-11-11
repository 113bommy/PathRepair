#include <bits/stdc++.h>
using namespace std;
int f[44], g[44][2];
char s[44];
long long dp[2][44];
int main() {
  int n, l, now, to;
  long long ans;
  scanf("%d", &n);
  ans = (1ll << n);
  scanf("%s", s + 1);
  l = strlen(s + 1);
  f[0] = f[1] = 0;
  for (int i = 2; i <= l; i++) {
    f[i] = f[i - 1];
    while (f[i] && s[f[i] + 1] != s[i]) f[i] = f[f[i]];
    if (s[f[i] + 1] == s[i]) f[i]++;
  }
  memset(g, 0, sizeof(g));
  g[0][s[1] - '0'] = 1;
  for (int i = 1; i <= l; i++) {
    g[i][0] = g[f[i]][0];
    g[i][1] = g[f[i]][1];
    if (i < l) g[i][s[i + 1] - '0'] = i + 1;
  }
  now = 0;
  to = 1;
  for (int i = 0; i < l; i++) {
    memset(dp, 0, sizeof(dp));
    dp[now][i] = 1;
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < l; k++)
        if (dp[now][k]) {
          dp[to][g[k][0]] += dp[now][k];
          dp[to][g[k][1]] += dp[now][k];
          dp[now][k] = 0;
        }
      swap(now, to);
    }
    ans -= dp[now][i];
  }
  printf("%I64d", ans);
  return 0;
}
