#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
const long long inf = 998244353;
vector<int> adj[200010], vis(200010, 0), par(200010, 0), dis(200010, 0),
    di(200010, 0), fin(200010, 0);
int myrandom(int i) { return std::rand() % i; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  int dp[n + 3][n + 3];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (i != j)
        dp[i][j] = inf;
      else
        dp[i][j] = 1;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n - i; j++) {
      dp[j][j + i] = min(dp[j][j + i], 1 + dp[j + 1][j + i]);
      if (v[j] == v[j + 1]) {
        dp[j][j + i] = 1 + dp[j + 2][j + i];
        for (int k = j + 2; k <= j + i; k++) {
          if (v[k] == v[j]) {
            dp[j][j + i] =
                min(dp[j][j + i], dp[j + 1][k - 1] + dp[k + 1][j + i]);
          }
        }
      } else {
        for (int k = j + 1; k <= j + i; k++) {
          if (v[k] == v[j]) {
            dp[j][j + i] =
                min(dp[j][j + i], dp[j + 1][k - 1] + dp[k + 1][j + i]);
          }
        }
      }
    }
  }
  cout << dp[1][n] << '\n';
}
