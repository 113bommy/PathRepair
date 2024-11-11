#include <bits/stdc++.h>
using namespace std;
int dp[2][5001][2600];
vector<int> a;
int n;
int solve(int pos, int k, bool can) {
  if (k == 0) return 0;
  if (pos >= n) {
    return 1e9;
  }
  if (pos == n - 1) {
    if (k > 1) return 1e9;
    if (k == 1 and not can) return 1e9;
    return 0;
  }
  int &d = dp[can][pos][k];
  if (d == -1) {
    d = solve(pos + 1, k, false);
    int add = max(0, a[pos] - a[pos + 1] + 1);
    d = min(d, solve(pos + 1, k, true) + add);
    if (can) {
      add = max(0, a[pos + 1] - a[pos] + 1);
      d = min(d, solve(pos + 2, k - 1, false) + add);
      if (pos + 2 < n) {
        add = max(0, a[pos + 1] - a[pos] + 1);
        int val = min(a[pos] - 1, a[pos + 1]);
        add += max(0, val - a[pos + 2] + 1);
        d = min(d, solve(pos + 2, k - 1, true) + add);
      }
    }
  }
  return d;
}
int main() {
  cout.setf(ios::fixed);
  cout.precision(15);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a = vector<int>(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5001; ++j) {
      memset(dp[i][j], -1, sizeof(int) * 2600);
    }
  }
  for (int i = 1; i <= (n + 1) / 2; ++i) {
    cout << solve(0, i, true) << " ";
  }
  cout << endl;
}
