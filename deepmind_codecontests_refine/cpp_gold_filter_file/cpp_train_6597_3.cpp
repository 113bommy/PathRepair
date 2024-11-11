#include <bits/stdc++.h>
using namespace std;
long long v[100010];
int c[100010];
long long dp[100010];
bool vis[100010];
int main() {
  std::ios_base::sync_with_stdio(false);
  ;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i <= n - 1; i++) {
    cin >> v[i];
  }
  for (int i = 0; i <= n - 1; i++) {
    cin >> c[i];
  }
  for (int i = 0; i <= q - 1; i++) {
    long long a, b;
    cin >> a >> b;
    long long cha = -11000000000;
    for (int i = 0; i <= n; i++) {
      dp[i] = cha;
    }
    memset((vis), 0, sizeof(vis));
    pair<long long, long long> mx = make_pair(-1, cha);
    pair<long long, long long> smx = make_pair(-1, cha);
    for (int i = 0; i <= n - 1; i++) {
      int col = c[i];
      if (vis[col]) {
        dp[col] = max(dp[col], dp[col] + (v[i] * a));
      }
      vis[col] = 1;
      if ((mx.first != -1) && (c[mx.first] != col)) {
        dp[col] = max(dp[col], mx.second + (v[i] * b));
      } else if ((smx.first != -1) && (c[smx.first] != col)) {
        dp[col] = max(dp[col], smx.second + (v[i] * b));
      }
      dp[col] = max(dp[col], 0 + (v[i] * b));
      if (mx.first == -1) {
        mx = make_pair(i, dp[col]);
      } else if ((c[mx.first] == col)) {
        if ((dp[col] > mx.second)) {
          mx = make_pair(i, dp[col]);
        }
      } else if (smx.first == -1) {
        if ((dp[col] > mx.second)) {
          smx = mx;
          mx = make_pair(i, dp[col]);
        } else {
          smx = make_pair(i, dp[col]);
        }
      } else {
        if (dp[col] > mx.second) {
          smx = mx;
          mx = make_pair(i, dp[col]);
        } else if (dp[col] > smx.second) {
          smx = make_pair(i, dp[col]);
        }
      }
    }
    cout << max(0LL, mx.second) << "\n";
  }
  return 0;
}
