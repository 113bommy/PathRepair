#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 2205;
int dp[N][N], mi[N][N], v[N], m;
void dfs(int x) {
  if (x < m / 2) {
    dfs(x * 2);
    dfs(x * 2 + 1);
    for (int i = 0; i < N; i++)
      if (i >= v[x * 2] && i >= v[x * 2 + 1]) {
        int a = mi[x * 2][i - v[x * 2]], b = mi[x * 2 + 1][i - v[x * 2 + 1]];
        if (a == -1 || b == -1) continue;
        if (dp[x][i] == -1 || dp[x][i] > a + b) dp[x][i] = a + b;
      }
    mi[x][0] = dp[x][0];
    for (int i = 1; i < N; i++)
      if (dp[x][i] != -1) {
        if (mi[x][i - 1] != -1) mi[x][i] = mi[x][i - 1] + 1;
        if (mi[x][i] == -1 || mi[x][i] > dp[x][i]) mi[x][i] = dp[x][i];
      }
  } else {
    for (int i = 0; i < N; i++) mi[x][i] = i;
  }
}
int main() {
  int n, i;
  scanf("%d", &n);
  m = (1 << (n + 1));
  for (i = 2; i < m; i++) scanf("%d", &v[i]);
  memset(dp, -1, sizeof(dp));
  memset(mi, -1, sizeof(mi));
  dfs(1);
  int ret = N;
  for (i = 0; i < N; i++)
    if (dp[1][i] != -1)
      if (ret > dp[1][i]) ret = dp[1][i];
  printf("%d\n", ret);
  return 0;
}
