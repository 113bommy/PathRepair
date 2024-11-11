#include <bits/stdc++.h>
using namespace std;
char G[205][205];
struct LOOP {
  int mask;
} LP[205 * 205];
int shu[205][205], flag[205][205];
int dp[205][205], data[10][2], n, m, nct, nn;
bool judge(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return false;
  return true;
}
char s[1000005];
int mk[1 << 10], ans;
int dfs(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  if (shu[x][y]) {
    if (mk[LP[shu[x][y]].mask] == 0) ans = 1;
    return dp[x][y] = mk[LP[shu[x][y]].mask];
  }
  int ha = G[x][y] - '0';
  int xx = x + data[ha][0], yy = y + data[ha][1];
  int d = dfs(xx, yy);
  dp[x][y] = d;
  if (d == 0) return d;
  if (s[d - 1] == ha) dp[x][y] = dp[xx][yy] - 1;
  if (dp[x][y] == 0) ans = 1;
  return dp[x][y];
}
int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%s", G[i] + 1);
  for (int i = 0; i < 10; i++) scanf("%d%d", &data[i][0], &data[i][1]);
  nct = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int ha = G[i][j] - '0';
      if (judge(i + data[ha][0], j + data[ha][1]) == 0) {
        shu[i][j] = nct;
        LP[nct++].mask = 1 << ha;
        flag[i][j] = 1;
      }
    }
  nn = 2;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (flag[i][j] == 0) {
        flag[i][j] = nn;
        int x = i, y = j, tmp = 0;
        while (1) {
          int ha = G[x][y] - '0';
          x += data[ha][0];
          y += data[ha][1];
          if (flag[x][y]) {
            if (flag[x][y] == nn) tmp = 1;
            break;
          }
          flag[x][y] = nn;
        }
        if (tmp) {
          shu[i][j] = nct;
          int ha = G[i][j] - '0';
          x = i + data[ha][0];
          y = j + data[ha][1];
          LP[nct].mask = 1 << ha;
          while (x != i || y != j) {
            ha = G[x][y] - '0';
            shu[x][y] = nct;
            LP[nct].mask |= 1 << ha;
            x += data[ha][0];
            y += data[ha][1];
          }
          nct++;
        }
        nn++;
      }
  while (q--) {
    memset(dp, -1, sizeof(dp));
    scanf("%s", s);
    int len = strlen(s);
    int ho = 0;
    for (int i = 1; i < (1 << 10); i++) mk[i] = len;
    for (int i = len - 1; i >= 0; i--) {
      ho |= 1 << (s[i] - '0');
      mk[ho] = min(mk[ho], i);
    }
    for (int i = 1; i < (1 << 10); i++)
      for (int j = i & (i - 1); j; j = i & (j - 1)) mk[i] = min(mk[i], mk[j]);
    ans = 0;
    for (int i = 1; i <= n && ans == 0; i++)
      for (int j = 1; j <= m && ans == 0; j++)
        if (dp[i][j] == -1) {
          dfs(i, j);
        }
    if (ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
