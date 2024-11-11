#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void solution() {
  int n, l;
  cin >> n >> l;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int dp[l + 1][101][n];
  for (int i = 0; i <= l; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int q = 0; q < n; q++) {
        dp[i][j][q] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] <= l) dp[a[i]][b[i]][i]++;
    if (b[i] <= l && a[i] != b[i]) dp[b[i]][a[i]][i]++;
  }
  for (int cur_len = 1; cur_len < l; cur_len++) {
    for (int last_height = 1; last_height <= 100; last_height++) {
      for (int last_type = 0; last_type < n; last_type++) {
        if (dp[cur_len][last_height][last_type] == 0) {
          continue;
        }
        for (int i = 0; i < n; i++) {
          if (i == last_type) continue;
          if (last_height == b[i]) {
            if (cur_len + b[i] <= l) {
              dp[cur_len + b[i]][a[i]][i] +=
                  dp[cur_len][last_height][last_type];
              dp[cur_len + b[i]][a[i]][i] %= mod;
            }
          }
          if (last_height == a[i] && a[i] != b[i]) {
            if (cur_len + a[i] <= l) {
              dp[cur_len + a[i]][b[i]][i] +=
                  dp[cur_len][last_height][last_type];
              dp[cur_len + a[i]][b[i]][i] %= mod;
            }
          }
        }
      }
    }
  }
  int answer = 0;
  for (int last_height = 1; last_height <= 100; last_height++) {
    for (int last_type = 0; last_type < n; last_type++) {
      answer = (answer + dp[l][last_height][last_type]) % mod;
    }
  }
  cout << answer << "\n";
}
void include_file() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int main() {
  solution();
  return 0;
}
