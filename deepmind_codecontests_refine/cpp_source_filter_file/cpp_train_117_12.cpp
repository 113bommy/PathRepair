#include <bits/stdc++.h>
const int N = 1e5 + 2;
using namespace std;
int n, sl;
long long st[4][N];
int top[4];
long long dp[10], Pre[10];
bool ss(int x, int y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= 9; i++) Pre[i] = -1e18;
  for (int i = 1; i <= n; i++) {
    cin >> sl;
    top[1] = top[2] = top[3] = 0;
    for (int j = 1; j <= sl; j++) {
      int x, y;
      cin >> x >> y;
      st[x][++top[x]] = y;
    }
    sort(st[1] + 1, st[1] + top[1] + 1, ss);
    sort(st[2] + 1, st[2] + top[2] + 1, ss);
    sort(st[3] + 1, st[3] + top[3] + 1, ss);
    for (int j = 0; j <= 9; j++) dp[j] = -1e18;
    for (int j = 0; j <= 9; j++) {
      long long val;
      dp[j] = max(dp[j], Pre[j]);
      val = -1e18;
      if (top[1]) val = max(val, st[1][1]);
      if (top[2]) val = max(val, st[1][2]);
      if (top[3]) val = max(val, st[1][3]);
      if (j < 9)
        dp[j + 1] = max(dp[j + 1], Pre[j] + val);
      else
        dp[0] = max(dp[0], Pre[j] + 2ll * val);
      if (j < 8) {
        val = -1e18;
        if (top[1] > 1) val = max(val, st[1][1] + st[1][2]);
        if (top[1] && top[2]) val = max(val, st[1][1] + st[2][1]);
        dp[j + 2] = max(dp[j + 2], Pre[j] + val);
      } else {
        val = -1e18;
        if (top[1] > 1)
          val =
              max(val, 2ll * max(st[1][1], st[1][2]) + min(st[1][1], st[1][2]));
        if (top[1] && top[2])
          val =
              max(val, 2ll * max(st[1][1], st[2][1]) + min(st[1][1], st[2][1]));
        dp[j - 8] = max(dp[j - 8], Pre[j] + val);
      }
      if (top[1] > 2) {
        if (j < 7)
          dp[j + 3] = max(dp[j + 3], Pre[j] + st[1][1] + st[1][2] + st[1][3]);
        else {
          long long mx = max(st[1][1], max(st[1][2], st[1][3]));
          long long mi = min(st[1][1], min(st[1][2], st[1][3]));
          long long en = st[1][1] + st[1][2] + st[1][3] - mx - mi;
          dp[j - 7] = max(dp[j - 7], Pre[j] + mi + 2ll * mx + en);
        }
      }
    }
    for (int j = 0; j <= 9; j++) Pre[j] = dp[j];
  }
  long long res = -1e18;
  for (int j = 0; j <= 9; j++) res = max(res, dp[j]);
  cout << res;
}
