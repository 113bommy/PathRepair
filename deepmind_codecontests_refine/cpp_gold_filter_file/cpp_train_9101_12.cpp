#include <bits/stdc++.h>
using namespace std;
long long dp1[1005][1005];
long long dp2[1005][1005];
long long dp3[1005][1005];
long long dp4[1005][1005];
long long arr[1005][1005];
int n, m;
int main() {
  long long ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp1[i][j] = arr[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j > 0; --j) {
      dp2[i][j] = arr[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      dp3[i][j] = arr[i][j] + max(dp3[i + 1][j], dp3[i][j + 1]);
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = 1; j <= m; ++j) {
      dp4[i][j] = arr[i][j] + max(dp4[i + 1][j], dp4[i][j - 1]);
    }
  }
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      ans = max(ans,
                dp1[i - 1][j] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i][j - 1]);
      ans = max(ans,
                dp1[i][j - 1] + dp2[i - 1][j] + dp3[i][j + 1] + dp4[i + 1][j]);
    }
  }
  cout << ans << "\n";
}
