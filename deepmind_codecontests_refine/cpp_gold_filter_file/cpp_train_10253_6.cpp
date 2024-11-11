#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll inf = 1e15 + 15102019;
void solve() {
  static ll dp[102][15102];
  int v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;
  for (int i = 0; i < 102; i++)
    for (int j = 0; j < 15102; j++) dp[i][j] = -1;
  dp[0][v1] = 0;
  for (int i = 0; i <= t; i++) {
    for (int j = 0; j <= v1 + t * d; ++j) {
      if (dp[i][j] != -1) {
        for (int p = -d; p <= d; ++p)
          if (j + p >= 0 && j + p < 15100)
            dp[i + 1][j + p] = max(dp[i + 1][j + p], dp[i][j] + j);
      }
    }
  }
  cout << dp[t - 1][v2] + v2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q = 1;
  while (q--) solve();
  return 0;
}
