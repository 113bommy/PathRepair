#include <bits/stdc++.h>
using namespace std;
const uint64_t seed =
    std::chrono::system_clock::now().time_since_epoch().count();
mt19937_64 rnd(seed);
const int MOD = 998244353;
int dp[81][3200][81];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = 0;
  vector<int> tt;
  int nn = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      tt.push_back(cnt);
      cnt = 0;
      nn--;
    } else
      cnt++;
  }
  tt.push_back(cnt);
  vector<int> sum(tt.size() + 1, 0);
  for (int i = 0; i < tt.size(); i++) sum[i + 1] = sum[i] + tt[i];
  int T = n * (n - 1) / 2 + 1;
  for (int i = 0; i <= tt.size(); i++) {
    for (int j = 0; j <= T; j++) {
      for (int k = 0; k <= nn; k++) {
        if (i == 0) {
          if (k != 0)
            dp[i][j][k] = INT_MAX;
          else
            dp[i][j][k] = 0;
        } else {
          dp[i][j][k] = INT_MAX;
          int t1 = tt[i - 1] + k - sum[i];
          for (int t = 0; t <= k; t++) {
            int d = abs(t1 - t);
            if (d > j) continue;
            if (dp[i - 1][j - d][k - t] == INT_MAX) continue;
            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - d][k - t] + t * t);
          }
        }
      }
    }
  }
  for (int i = 0; i <= T; i++) {
    cout << (nn * nn - dp[tt.size()][i][nn]) / 2 << " ";
  }
  cout << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  int T = 1;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  cout.flush();
  return 0;
}
