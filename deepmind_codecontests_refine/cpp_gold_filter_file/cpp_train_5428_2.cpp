#include <bits/stdc++.h>
using namespace std;
int n, m;
long long dp[41][(1 << 6)][(1 << 6)];
bool valid(int prv, int cur, int nxt) {
  int mask = prv | (cur << 1) | cur | (cur >> 1) | nxt;
  if ((((1 << m) - 1) & mask) == ((1 << m) - 1)) {
    return 1;
  }
  return 0;
}
long long solve(int row, int cur, int nxt) {
  if (dp[row][cur][nxt] != -1) {
    return dp[row][cur][nxt];
  }
  if (row == 1) {
    if (valid(0, cur, nxt)) {
      return __builtin_popcount(cur);
    } else {
      return 1000000007;
    }
  }
  long long &ret = dp[row][cur][nxt];
  ret = 1000000007;
  for (long long i = 0; i <= (1 << m) - 1; ++i) {
    if (valid(i, cur, nxt)) {
      ret = min(ret, solve(row - 1, i, cur) + __builtin_popcount(cur));
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  if (n < m) {
    swap(n, m);
  }
  long long ans = 1000000007;
  for (long long i = 0; i <= (1 << m) - 1; ++i) {
    ans = min(ans, solve(n, i, 0));
  }
  cout << n * m - ans;
  return 0;
}
