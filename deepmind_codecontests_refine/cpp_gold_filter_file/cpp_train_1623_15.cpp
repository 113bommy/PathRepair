#include <bits/stdc++.h>
using namespace std;
int n, k;
char a[105];
bool vis[105][105][105];
bool memo[105][105][2];
bool dp(int i, int x, int flag) {
  if (x < 0) return false;
  if (i == -1) return (x == 0 || flag);
  if (vis[i][x][flag]) return memo[i][x][flag];
  vis[i][x][flag] = true;
  if (x == 0) flag = true;
  if (a[i] == 'N')
    return memo[i][x][flag] = dp(i - 1, x - 1, flag);
  else if (a[i] == 'Y')
    return memo[i][x][flag] = dp(i - 1, k, flag);
  else
    return memo[i][x][flag] = (dp(i - 1, x - 1, flag) || dp(i - 1, k, flag));
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf(" %c", &a[i]);
  memset(vis, 0, sizeof vis);
  printf("%s\n", dp(n - 1, k, 0) ? "YES" : "NO");
}
