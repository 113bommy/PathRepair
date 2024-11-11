#include <bits/stdc++.h>
using namespace std;
const int MX_N = 85;
const int MX_SZ = 2000 + 42;
const int INF = 1e+9 + 42;
int d[MX_SZ][MX_SZ];
int dp[MX_N][MX_N][MX_N][2];
bool was[MX_N][MX_N][MX_N][2];
int n;
void init() {
  for (int i = 0; i < MX_N; ++i) {
    for (int j = 0; j < MX_N; ++j) {
      for (int k = 0; k < MX_N; ++k) {
        dp[i][j][k][0] = INF;
        dp[i][j][k][1] = INF;
      }
    }
  }
}
void get(int l, int r, int rem, int left) {
  if (was[l][r][rem][left]) {
    return;
  }
  was[l][r][rem][left] = true;
  if (rem == 1) {
    dp[l][r][rem][left] = 0;
    return;
  } else if (r == l) {
    dp[l][r][rem][left] = INF;
    return;
  }
  if (left) {
    for (int to = l + 1; to <= r; ++to) {
      if (d[l][to] != -1) {
        get(to, r, rem - 1, true);
        get(l + 1, to, rem - 1, false);
        dp[l][r][rem][left] = min(
            dp[l][r][rem][left], d[l][to] + min(dp[to][r][rem - 1][true],
                                                dp[l + 1][to][rem - 1][false]));
      }
    }
  } else if (!left) {
    for (int to = l; to < r; ++to) {
      if (d[r][to] != -1) {
        get(l, to, rem - 1, false);
        get(to, r - 1, rem - 1, true);
        dp[l][r][rem][left] = min(dp[l][r][rem][left],
                                  d[r][to] + min(dp[l][to][rem - 1][false],
                                                 dp[to][r - 1][rem - 1][true]));
      }
    }
  }
}
int main() {
  memset(d, -1, sizeof(d));
  init();
  ios_base::sync_with_stdio(false);
  int k;
  cin >> n >> k;
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int v, u, cost;
    cin >> v >> u >> cost;
    if (d[v][u] == -1 or d[v][u] > cost) {
      d[v][u] = cost;
    }
  }
  int ans = INF;
  for (int l = 1; l <= n; ++l) {
    for (int r = l + 1; r <= n; ++r) {
      get(l - 1, r, k, 0);
      get(l, r + 1, k, 1);
      ans = min(ans, min(dp[l - 1][r][k][0], dp[l][r + 1][k][1]));
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
}
