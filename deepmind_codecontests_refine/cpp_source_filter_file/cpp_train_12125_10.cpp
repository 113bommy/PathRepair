#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn][12];
int pos[maxn], L[maxn], R[maxn], n, m, q;
pair<int, int> dp[maxn][12];
pair<int, int> dfs(int x, int y, int lim) {
  if (dp[x][y].first != 0 || dp[x][y].second != 0) return dp[x][y];
  pair<int, int> res = {0, 0};
  if (s[x][y] == '<') {
    if (y == 1)
      res = {x, y - 1};
    else if (s[x][y - 1] == '>')
      res = {-1, -1};
    else
      res = dfs(x, y - 1, lim);
  } else if (s[x][y] == '>') {
    if (y == m)
      return res = {x, y + 1};
    else if (s[x][y + 1] == '<')
      res = {-1, -1};
    else
      res = dfs(x, y + 1, lim);
  } else if (s[x][y] == '^') {
    if (x == lim)
      res = {x - 1, y};
    else
      res = dfs(x - 1, y, lim);
  }
  return dp[x][y] = res;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int block = sqrt(n + 0.5);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    pos[i] = (i - 1) / block + 1;
  }
  int tot = n / block;
  if (n % block) tot++;
  for (int i = 1; i <= tot; i++) {
    L[i] = (i - 1) * block + 1;
    R[i] = i * block;
    if (i == tot) R[i] = min(R[i], n);
    for (int j = L[i]; j <= R[i]; j++) {
      for (int k = 1; k <= m; k++) dp[j][k] = dfs(j, k, L[i]);
    }
  }
  while (q--) {
    char op[2], c[2];
    int x, y;
    scanf("%s%d%d", op, &x, &y);
    if (op[0] == 'C') {
      scanf("%s", c);
      s[x][y] = c[0];
      for (int i = L[pos[x]]; i <= R[pos[x]]; i++) {
        for (int j = 1; j <= m; j++) dp[i][j] = {0, 0};
      }
      for (int i = L[pos[x]]; i <= R[pos[x]]; i++) {
        for (int j = 1; j <= m; j++) dp[i][j] = dfs(i, j, L[pos[x]]);
      }
    } else if (op[0] == 'A') {
      while (1) {
        if (x == -1 && y == -1) break;
        if (x == 0 || y == 0 || x == m + 1 || y == m + 1) break;
        int tx = dp[x][y].first;
        int ty = dp[x][y].second;
        x = tx, y = ty;
      }
      printf("%d %d\n", x, y);
    }
  }
  return 0;
}
