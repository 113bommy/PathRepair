#include <bits/stdc++.h>
using namespace std;
int mequal[53][53], in[53] = {0};
int visit[53][53][53][53], dp[53][53][53][53] = {{{{0}}}};
char card[53][3];
int mequall(int a, int b) {
  return card[a][0] == card[b][0] || card[a][1] == card[b][1];
}
int check(int n, int a, int b, int c) {
  if (n == 1)
    return 1;
  else if (n == 2)
    return mequal[c][b];
  else
    return (mequal[c][b] && mequal[c][a]);
}
int dfs(int n, int a, int b, int c) {
  if (visit[n][a][b][c] != 0) return dp[n][a][b][c];
  visit[n][a][b][c] = 1;
  if (n == 0)
    dp[n][a][b][c] = check(3, a, b, c);
  else {
    if (mequal[c][b]) dp[n][a][b][c] = dfs(n - 1, in[n], a, c);
    if (dp[n][a][b][c] != 1 && mequal[n][c])
      dp[n][a][b][c] = dfs(n - 1, c, a, b);
  }
  return dp[n][a][b][c];
}
int main() {
  int n;
  map<string, int> ma;
  memset(visit, 0, sizeof(visit));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%s", card[i]), ma[card[i]] = i;
  for (int i = 1; i <= n; ++i) in[i] = ma[card[i]];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) mequal[i][j] = mequall(i, j);
  if (n <= 3)
    printf("%s", check(n, n - 2, n - 1, n) == 1 ? "YES" : "NO");
  else
    printf("%s", dfs(n - 3, in[n - 2], in[n - 1], in[n]) == 1 ? "YES" : "NO");
  return 0;
}
