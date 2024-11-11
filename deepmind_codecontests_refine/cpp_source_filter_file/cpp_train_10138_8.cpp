#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n, a[200005];
long long dp[2][200005];
bool was[2][200005];
void dfs(int v, bool dir) {
  if (was[dir][v]) return;
  was[dir][v] = 1;
  int to = v;
  if (dir)
    to -= a[v];
  else
    to += a[v];
  if (to < 0 || to >= n) {
    dp[dir][v] = a[v];
    return;
  }
  dfs(to, dir ^ 1);
  if (!dp[dir ^ 1][to])
    dp[dir][v] = 0;
  else
    dp[dir][v] = dp[dir ^ 1][to] + a[v];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    dfs(i, 1);
    if (dp[1][i] == 0)
      printf("-1\n");
    else
      printf("%I64d\n", dp[1][i]);
  }
  return 0;
}
