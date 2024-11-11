#include <bits/stdc++.h>
using std::make_pair;
using std::map;
using std::max;
using std::pair;
const int N = 300005;
long long s[3][N];
int pre[3][N], dp[N], n;
map<pair<int, int>, bool> vis;
map<long long, int> last;
map<pair<int, int>, int> f;
int solve(int x, int y) {
  pair<int, int> t = make_pair(x, y);
  if (vis[t]) return f[t];
  f[t] = dp[std::min(x, y)];
  if (x <= y && pre[2][y] > -1) f[t] = max(f[t], solve(x, pre[2][y]) + 1);
  if (x >= y && pre[1][x] > -1) f[t] = max(f[t], solve(pre[1][x], y) + 1);
  vis[t] = 1;
  return f[t];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &s[i][j]);
      s[i][j] += s[i][j - 1];
    }
  for (int i = 1; i <= n; i++) s[0][i] = s[1][i] + s[2][i];
  for (int i = 0; i <= 2; i++) {
    last.clear();
    last[0] = 0, pre[i][0] = -1;
    for (int j = 1; j <= n; j++) {
      long long x = s[i][j];
      if (last.count(x))
        pre[i][j] = last[x];
      else
        pre[i][j] = -1;
      pre[i][j] = max(pre[i][j], pre[i][j - 1]);
      last[x] = j;
    }
  }
  vis[make_pair(0, 0)] = 1;
  f[make_pair(0, 0)] = 0;
  for (int i = 1; i <= n; i++) {
    if (pre[0][i] >= 0) dp[i] = dp[pre[0][i]] + 1;
    dp[i] = max(dp[i], solve(i, i));
  }
  printf("%d\n", dp[n]);
}
