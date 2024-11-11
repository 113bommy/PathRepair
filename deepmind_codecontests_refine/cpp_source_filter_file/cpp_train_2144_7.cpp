#include <bits/stdc++.h>
using namespace std;
int dp[83][83][83][83];
vector<pair<int, int>> gr[83];
int main() {
  int n, k, m, a, b, c;
  cin >> n >> k >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    a, b;
    gr[a].push_back(make_pair(b, c));
  }
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n + 2; j++) {
      for (int z = 0; z <= n + 2; z++) {
        for (int f = 0; f <= n; f++) dp[i][j][z][f] = 1e9;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[1][0][n + 1][i] = 0;
  }
  int next, cost;
  for (int i = 1; i < k; i++) {
    for (int j = 0; j <= n + 1; j++) {
      for (int z = 0; z <= n + 1; z++) {
        for (int f = 1; f <= n; f++) {
          if (dp[i][j][z][f] == 1e9) continue;
          for (int x = 0; x < gr[f].size(); x++) {
            next = gr[f][x].first;
            cost = gr[f][x].second;
            if (next > f) {
              if (next >= z) continue;
              dp[i + 1][f][z][next] =
                  min(dp[i + 1][f][z][next], dp[i][j][z][f] + cost);
            } else {
              if (next <= j) continue;
              dp[i + 1][j][f][next] =
                  min(dp[i + 1][j][f][next], dp[i][j][z][f] + cost);
            }
          }
        }
      }
    }
  }
  int ans = 1e9;
  for (int j = 0; j <= n + 1; j++) {
    for (int z = 0; z <= n + 1; z++) {
      for (int f = 0; f < n; f++) ans = min(ans, dp[k][j][z][f]);
    }
  }
  if (ans == 1e9)
    cout << -1;
  else
    cout << ans;
  return 0;
}
