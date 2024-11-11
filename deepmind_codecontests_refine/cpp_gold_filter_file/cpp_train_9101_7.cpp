#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int32_t main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long> > v(n + 1, vector<long long>(m + 1, 0)),
      dp1(n + 2, vector<long long>(m + 1, 0)),
      dp2(n + 2, vector<long long>(m + 1, 0)),
      dp3(n + 2, vector<long long>(m + 2, 0)),
      dp4(n + 2, vector<long long>(m + 2, 0));
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> v[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + v[i][j];
    }
  }
  for (long long i = n; i > 0; i--) {
    for (long long j = 1; j <= m; j++) {
      dp2[i][j] = max(dp2[i + 1][j], dp2[i][j - 1]) + v[i][j];
    }
  }
  for (long long i = n; i > 0; i--) {
    for (long long j = m; j > 0; j--) {
      dp3[i][j] = max(dp3[i + 1][j], dp3[i][j + 1]) + v[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = m; j > 0; j--) {
      dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + v[i][j];
    }
  }
  long long ans = 0;
  for (long long i = 2; i < n; i++) {
    for (long long j = 2; j < m; j++) {
      long long a =
          (dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1]);
      long long b =
          (dp2[i + 1][j] + dp4[i - 1][j] + dp1[i][j - 1] + dp3[i][j + 1]);
      ans = max(ans, max(a, b));
    }
  }
  cout << ans << endl;
}
