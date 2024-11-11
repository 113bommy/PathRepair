#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4;
int n;
double dp[(1 << MAXN)][MAXN];
double a[MAXN][MAXN];
double solve(int mask, int start) {
  if (dp[mask][start] != -1.) {
    return dp[mask][start];
  }
  if (!(mask & 1)) {
    return dp[mask][start] = 0;
  }
  if (!(mask & (1 << start))) {
    return dp[mask][start] = 0;
  }
  dp[mask][start] = 0;
  int am{};
  for (int i{}; i < n; ++i) {
    if (!(mask & (1 << i))) {
      continue;
    }
    if (i == start) {
      continue;
    }
    ++am;
    dp[mask][start] = max(solve(mask ^ (1 << start), i) * a[i][start] +
                              solve(mask ^ (1 << i), start) * a[start][i],
                          dp[mask][start]);
  }
  return dp[mask][start];
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cout.precision(15);
  cin >> n;
  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i{}; i < (1 << n); ++i) {
    for (int j{}; j < n; ++j) {
      dp[i][j] = -1;
    }
  }
  dp[1][0] = 1;
  double ans = 0;
  for (int i{0}; i < n; ++i) {
    ans = max(ans, solve((1 << n) - 1, i));
  }
  cout << ans;
  return 0;
}
