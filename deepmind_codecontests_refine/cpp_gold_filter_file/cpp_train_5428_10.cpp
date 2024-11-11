#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, m;
int dp[41][(1 << 6)][(1 << 6)];
int solve(int col, int last, int cur) {
  int &ret = dp[col][last][cur];
  if (ret != -1) return ret;
  if (col == m - 1) {
    ret = -INF;
    for (long long i = 0; i <= n - 1; ++i) {
      bool ok = 0;
      for (long long d = -1; d <= 1; ++d) {
        int ii = i + d;
        if (ii < 0 || ii > n - 1) continue;
        if (cur & (1 << ii)) {
          ok = 1;
          break;
        }
      }
      if (last & (1 << i)) ok = 1;
      if (!ok) return ret;
    }
    ret = 0;
    for (long long i = 0; i <= n - 1; ++i) {
      if (!(cur & (1 << i))) ret++;
    }
  } else {
    ret = -INF;
    for (long long mask = 0; mask <= (1 << n) - 1; ++mask) {
      bool valid_mask = 1;
      for (long long i = 0; i <= n - 1; ++i) {
        bool ok = 0;
        for (long long d = -1; d <= 1; ++d) {
          int ii = i + d;
          if (ii < 0 || ii > n - 1) continue;
          if (cur & (1 << ii)) {
            ok = 1;
            break;
          }
        }
        if (last & (1 << i)) ok = 1;
        if (mask & (1 << i)) ok = 1;
        if (!ok) {
          valid_mask = 0;
          break;
        }
      }
      if (!valid_mask) continue;
      int val = solve(col + 1, cur, mask);
      for (long long i = 0; i <= n - 1; ++i) {
        if (!(cur & (1 << i))) val++;
      }
      ret = max(ret, val);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n > m) swap(n, m);
  memset(dp, -1, sizeof(dp));
  int ans = -INF;
  for (long long i = 0; i <= (1 << n) - 1; ++i) {
    ans = max(ans, solve(0, 0, i));
  }
  cout << ans;
  return 0;
}
