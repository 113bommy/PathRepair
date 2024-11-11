#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int dp[N][N][2];
int dpm[N][2];
void build_dp() {
  for (int d = 1; d < N; ++d) {
    dp[0][d][0] = -1;
  }
  for (int n = 1; n < N; ++n) {
    dpm[n][0] = N;
    for (int d = 0; d < N; ++d) {
      dp[n][d][0] = -1;
    }
    for (int k = 0; k < n; ++k) {
      int d1 = dpm[k][0];
      int d2 = dpm[k][1];
      int d3 = dpm[n - 1 - k][0];
      int d4 = dpm[n - 1 - k][1];
      int x = d1 + d3 + n - 1;
      int y = d2 + d4 + n - 1;
      if (dpm[n][0] == N) {
        while ((d1 != d2 || d3 != d4) && d1 + d3 + n - 1 < N) {
          dp[n][d1 + d3 + n - 1][0] = k;
          dp[n][d1 + d3 + n - 1][1] = d1;
          if (d1 != d2) {
            ++d1;
          } else {
            ++d3;
          }
        }
        if (d2 + d4 + n - 1 < N) {
          dp[n][d2 + d4 + n - 1][0] = k;
          dp[n][d2 + d4 + n - 1][1] = d2;
        }
      } else {
        while ((d1 != d2 || d3 != d4) && d1 + d3 + n - 1 < N) {
          dp[n][d1 + d3 + n - 1][0] = k;
          dp[n][d1 + d3 + n - 1][1] = d1;
          if (d1 != d2) {
            ++d1;
          } else {
            ++d3;
          }
          if (d1 + d3 >= dpm[n][0] && d1 + d3 <= dpm[n][1]) {
            d1 = min(d2, dpm[n][1] - d3 + 1);
            d3 = min(d4, dpm[n][1] - d1 + 1);
          }
        }
        if (d2 + d4 + n - 1 < N) {
          dp[n][d2 + d4 + n - 1][0] = k;
          dp[n][d2 + d4 + n - 1][1] = d2;
        }
      }
      dpm[n][0] = min(dpm[n][0], x);
      dpm[n][1] = max(dpm[n][1], y);
    }
  }
}
int ans[N];
void build_ans(int n, int d, int s = 0) {
  if (n) {
    build_ans(dp[n][d][0], dp[n][d][1], s + 1);
    build_ans(n - 1 - dp[n][d][0], d - (n - 1) - dp[n][d][1],
              s + 1 + dp[n][d][0]);
    if (dp[n][d][0]) {
      ans[s + 1] = s;
    }
    if (n - 1 - dp[n][d][0]) {
      ans[s + 1 + dp[n][d][0]] = s;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  build_dp();
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    if (dp[n][d][0] == -1) {
      cout << "NO\n";
    } else {
      build_ans(n, d);
      cout << "YES\n";
      for (int i = 1; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
