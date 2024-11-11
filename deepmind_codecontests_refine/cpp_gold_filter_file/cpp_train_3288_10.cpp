#include <bits/stdc++.h>
using namespace std;
const int N = 507, LOG = 60;
bitset<N> matrix[2][LOG][N];
bitset<N> dp[2];
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int v, u, t;
    cin >> v >> u >> t;
    v--;
    u--;
    matrix[t][0][v][u] = 1;
  }
  for (int i = 1; i < LOG; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (matrix[0][i - 1][j][k]) {
          matrix[0][i][j] |= matrix[1][i - 1][k];
        }
        if (matrix[1][i - 1][j][k]) {
          matrix[1][i][j] |= matrix[0][i - 1][k];
        }
      }
    }
  }
  long long ans = 0;
  dp[0][0] = 1;
  bool act = 0;
  for (int i = LOG - 1; i >= 0; --i) {
    bool flag = 0;
    for (int j = 0; j < n; ++j) {
      if (!dp[0][j]) {
        continue;
      }
      flag |= matrix[act][i][j].any();
      dp[1] |= matrix[act][i][j];
    }
    if (flag) {
      dp[0].reset();
      swap(dp[0], dp[1]);
      ans += 1ll << i;
      act = !act;
    }
  }
  if (ans > 1e18) {
    ans = -1;
  }
  cout << ans << "\n";
  return 0;
}
