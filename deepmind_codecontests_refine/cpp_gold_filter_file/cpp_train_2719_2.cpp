#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[505];
int sz;
int val[505];
int ch[505][11];
void insert() {
  int f, k = 0;
  scanf("%s%d", s, &f);
  for (int i = 0; s[i]; ++i) {
    int c = s[i] - '0';
    if (!ch[k][c]) ch[k][c] = ++sz;
    k = ch[k][c];
  }
  val[k] += f;
}
void init() {
  scanf("%d%d", &n, &m);
  while (n--) insert();
}
int dep[505];
int dp[505][505][15], f[505][15];
void dfs(int i) {
  if (val[i])
    for (int l = 0; l <= dep[i]; ++l)
      for (int k = 0; k <= m; ++k) dp[i][l][k] = l * val[i];
  for (int c = 0; c < 11; ++c) {
    int j = ch[i][c];
    if (!j) continue;
    dep[j] = dep[i] + 1;
    dfs(j);
    memcpy(f, dp[i], sizeof(f));
    memset(dp[i], 0x3f, sizeof(dp[i]));
    for (int l = 0; l <= dep[i]; ++l)
      for (int k = m; ~k; --k)
        for (int p = 0; p <= k; ++p) {
          dp[i][l][k] = min(dp[i][l][k], f[l][k - p] + dp[j][l + 1][p]);
          if (p) dp[i][l][k] = min(dp[i][l][k], f[l][k - p] + dp[j][0][p - 1]);
        }
  }
}
void solve() {
  dfs(0);
  printf("%d\n", dp[0][0][m]);
}
int main() {
  init();
  solve();
  return 0;
}
