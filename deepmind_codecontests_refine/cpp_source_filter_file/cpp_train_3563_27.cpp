#include <bits/stdc++.h>
using namespace std;
const int sz = 81;
const int inf = 2e9;
int n, k;
int cost[sz][sz];
int dp[11][sz];
int color[sz];
inline void solve() {
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> cost[i][j];
  int otv = inf;
  for (int q = 0; q < 1488; q++) {
    for (int i = 0; i <= k; i++)
      for (int j = 0; j < n; j++) {
        dp[i][j] = inf;
      }
    for (int i = 0; i < n; i++) color[i] = rand() % 2;
    dp[k][0] = 0;
    for (int i = k; i > 0; i--)
      for (int j = 0; j < n; j++) {
        if (dp[i][j] == inf) continue;
        for (int to = 0; to < n; to++)
          if (color[j] != color[to])
            dp[i - 1][to] = min(dp[i - 1][to], dp[i][j] + cost[j][to]);
      }
    otv = min(otv, dp[0][0]);
  }
  cout << otv;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q = 1;
  for (; q > 0; q--) {
    solve();
    cout << '\n';
  }
}
