#include <bits/stdc++.h>
using namespace std;
const int Inf = 1e9 + 7;
const int N = 204;
int dp[N][N][N];
char s[N], t[N], str[2 * N];
int mem[N][N][N];
int n, m;
int dfs(int i, int j, int k) {
  if (k < 0 || k > 4) return Inf;
  if (i == n + 1 && j == m + 1) {
    if (k == 0)
      return 0;
    else
      return k;
  }
  if (dp[i][j][k] != -1) return dp[i][j][k];
  int res = Inf;
  int f = 0, g = 0;
  if (i <= n && s[i] == '(') f = 1;
  if (j <= m && t[j] == '(') g = 1;
  int res1 = 1 + dfs(i + f, j + g, k + 1);
  f = 0, g = 0;
  if (i <= n && s[i] == ')') f = 1;
  if (j <= m && t[j] == ')') g = 1;
  int res2 = 1 + dfs(i + f, j + g, k - 1);
  if (res1 < res2)
    mem[i][j][k] = 0;
  else
    mem[i][j][k] = 1;
  res = min(res1, res2);
  dp[i][j][k] = res;
  return res;
}
int idx = 1;
void solve(int i, int j, int k) {
  if (i == n + 1 && j == m + 1) {
    while (k--) str[idx++] = ')';
    return;
  }
  if (mem[i][j][k] == 0) {
    str[idx++] = '(';
    int f = 0, g = 0;
    if (i <= n && s[i] == '(') f = 1;
    if (j <= m && t[j] == '(') g = 1;
    solve(i + f, j + g, k + 1);
  } else {
    str[idx++] = ')';
    int f = 0, g = 0;
    if (i <= n && s[i] == ')') f = 1;
    if (j <= m && t[j] == ')') g = 1;
    solve(i + f, j + g, k - 1);
  }
}
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  memset(dp, -1, sizeof(dp));
  int ans = dfs(1, 1, 0);
  solve(1, 1, 0);
  printf("%s\n", str + 1);
  return 0;
}
