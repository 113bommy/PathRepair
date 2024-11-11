#include <bits/stdc++.h>
using namespace std;
const int M = 105;
const int MOD = 1e9 + 7;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, m;
char s[M];
struct Automaton {
  int c[M][4], val[M], fail[M], cnt;
  int dp[1005][M][11];
  void ins(char *s) {
    int len = strlen(s), now = 0;
    for (int i = 0; i < len; i++) {
      int v = 0;
      if (s[i] == 'A') v = 0;
      if (s[i] == 'C') v = 1;
      if (s[i] == 'T') v = 2;
      if (s[i] == 'G') v = 3;
      if (!c[now][v]) c[now][v] = ++cnt;
      now = c[now][v];
    }
    val[now] = len;
  }
  void build() {
    queue<int> q;
    for (int i = 0; i < 4; i++)
      if (c[0][i]) q.push(c[0][i]);
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      val[t] = max(val[t], val[fail[t]]);
      for (int i = 0; i < 4; i++)
        if (c[t][i])
          fail[c[t][i]] = c[fail[t]][i], q.push(c[t][i]);
        else
          c[t][i] = c[fail[t]][i];
    }
    memset(dp, -1, sizeof dp);
  }
  int dfs(int x, int p, int w) {
    if (w >= 10) return 0;
    if (x == 0) return w == 0;
    if (dp[x][p][w] != -1) return dp[x][p][w];
    dp[x][p][w] = 0;
    for (int i = 0; i < 4; i++) {
      int to = c[p][i];
      dp[x][p][w] =
          (dp[x][p][w] + dfs(x - 1, to, (val[to] > w) ? 0 : w + 1)) % MOD;
    }
    return dp[x][p][w];
  }
} AC;
signed main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    AC.ins(s);
  }
  AC.build();
  printf("%d\n", AC.dfs(n, 0, 0));
}
