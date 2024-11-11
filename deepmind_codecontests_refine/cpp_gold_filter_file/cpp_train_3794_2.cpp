#include <bits/stdc++.h>
using namespace std;
const int N = 66;
long long n, m, dp[N][N];
int d, bit[N], vis[N][N];
long long dfs(int len, int j, int lim) {
  if (len == -1) return j == d - 1;
  if (!lim && vis[len][j]) return dp[len][j];
  int up = lim ? bit[len] : 1;
  long long tmp = 0;
  for (int i = 0; i <= up; ++i) {
    tmp += dfs(len - 1, j + (i == 1), lim && i == up);
  }
  if (lim) return tmp;
  vis[len][j] = 1;
  return dp[len][j] = tmp;
}
long long check(long long x) {
  long long ret = 0;
  int left;
  for (int i = 0; i < 64; ++i, x >>= 1)
    if (bit[i] = x & 1) left = i;
  memset(vis, 0, sizeof(vis));
  memset(dp, 0, sizeof(dp));
  ret += -dfs(left - 1, 0, 1);
  for (int i = left; i; --i) bit[i] = bit[i - 1];
  bit[0] = 0;
  memset(vis, 0, sizeof(vis));
  memset(dp, 0, sizeof(dp));
  ret += dfs(left, 0, 1);
  for (int i = left - 1; i >= 0; --i) bit[i] = 1;
  memset(vis, 0, sizeof(vis));
  memset(dp, 0, sizeof(dp));
  ret += dfs(left - 1, 0, 1);
  return ret;
}
int main() {
  cin >> m >> d;
  long long l = 1, r = 1e18;
  while (l <= r) {
    long long mid = l + r >> 1;
    long long res = check(mid);
    if (res == m) {
      cout << mid << endl;
      break;
    } else if (res < m)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return 0;
}
