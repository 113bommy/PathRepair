#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int size = 100000;
int dp[310][100010];
vector<int> ve[size + 10];
int arr[size + 10];
int main() {
  cin.sync_with_stdio(false);
  int n, m, s, e;
  while (cin >> n >> m >> s >> e) {
    for (int i = 0; i <= size; ++i) {
      ve[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    int x;
    for (int i = 1; i <= m; ++i) {
      cin >> x;
      ve[x].push_back(i);
    }
    memset(dp, inf, sizeof(dp));
    for (int i = 0; i <= n; ++i) {
      dp[0][i] = 0;
    }
    for (int i = 1; i <= s / e; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i - 1][j - 1] != inf) {
          dp[i][j] = dp[i][j - 1];
          auto it = lower_bound(ve[arr[j]].begin(), ve[arr[j]].end(),
                                dp[i - 1][j - 1] + 1);
          if (it != ve[arr[j]].end()) {
            dp[i][j] = min(dp[i][j], *it);
          }
        }
      }
    }
    int res = -1;
    for (int i = 1; i <= s / e; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i * e + j + dp[i][j] <= s) {
          res = max(res, i);
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
