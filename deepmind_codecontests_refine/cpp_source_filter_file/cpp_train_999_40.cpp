#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const long long linf = 1ll * inf * inf;
const int N = 300000 + 7;
const int M = 22;
const int multipleTest = 0;
int dp[N][M];
int n;
int a[N];
void solve() {
  cin >> n;
  for (int i = (0), _b = (N); i < _b; ++i)
    for (int j = (0), _b = (M); j < _b; ++j) dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = (1), _b = (n + 1); i < _b; ++i) {
    int u;
    scanf("%d", &u);
    u /= 100;
    for (int j = 0; j < M; ++j) {
      for (int t = 1, _m = min(u, j); t <= _m; ++t)
        dp[i][j - t] = min(dp[i][j - t], dp[i - 1][j] + u - t);
      if (j + u / 10 < M)
        dp[i][j + u / 10] = min(dp[i][j + u / 10], dp[i - 1][j] + u);
    }
  }
  int res = inf;
  for (int j = (0), _b = (M); j < _b; ++j) res = min(res, dp[n][j]);
  cout << res * 100;
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
