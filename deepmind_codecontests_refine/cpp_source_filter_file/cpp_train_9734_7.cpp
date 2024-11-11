#include <bits/stdc++.h>
using namespace std;
int a[3405], p, dp[3405][3405][2][2];
long long f1, f2, ans;
bool vis[3405][3405][2][2];
int dfs(int x, int y, int A, int b) {
  if (y < 0 || x < y) return 0;
  if (vis[x][y][A][b]) return dp[x][y][A][b];
  if (!x) return 0;
  vis[x][y][A][b] = 1;
  long long ret;
  if (A & b)
    ret = (1ll * a[x] * (p + p - a[x] - 1) / 2 % 1000000007 *
               dfs(x - 1, y - 1, 0, 0) +
           1ll * (p - 1 - a[x]) * dfs(x - 1, y - 1, 0, 1) +
           1ll * a[x] * (p + p - a[x] + 1) / 2 % 1000000007 *
               dfs(x - 1, y - 1, 1, 0) +
           1ll * (p - a[x]) * dfs(x - 1, y - 1, 1, 1)) %
          1000000007;
  else if (A)
    ret = (1ll * a[x] * (a[x] + 1) / 2 % 1000000007 * dfs(x - 1, y, 0, 0) +
           1ll * (a[x] + 1) * dfs(x - 1, y, 0, 1) +
           1ll * a[x] * (a[x] - 1) / 2 % 1000000007 * dfs(x - 1, y, 1, 0) +
           1ll * a[x] * dfs(x - 1, y, 1, 1)) %
          1000000007;
  else if (b)
    ret = (f2 * dfs(x - 1, y - 1, 0, 0) + f1 * dfs(x - 1, y - 1, 1, 0)) %
          1000000007;
  else
    ret = (f1 * dfs(x - 1, y, 0, 0) + f2 * dfs(x - 1, y, 1, 0)) % 1000000007;
  return dp[x][y][A][b] = ret;
}
int k, l, i, cnt;
char s[3405];
long long val;
void div() {
  for (val = 0, i = l; i; --i) val = val * 10 + s[i], s[i] = val / p, val %= p;
  while (l && !s[l]) --l;
  a[++cnt] = val;
}
int main() {
  scanf("%d%d%s", &p, &k, s + 1);
  f1 = 1ll * p * (p + 1) / 2 % 1000000007;
  f2 = 1ll * p * (p - 1) / 2 % 1000000007;
  l = strlen(s + 1);
  dp[0][0][0][0] = dp[0][0][0][1] = vis[0][0][0][0] = vis[0][0][0][1] = 1;
  for (i = 1; i <= l; ++i) s[i] -= '0';
  for (i = 1; (i << 1) <= l; ++i) swap(s[i], s[l + 1 - i]);
  while (l) div();
  for (; k < cnt; ++k) ans += dfs(cnt + 1, k, 0, 1);
  cout << ans % 1000000007;
}
