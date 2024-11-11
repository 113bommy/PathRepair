#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long mod2 = 1e9 + 9;
double eps = 1e-9;
const int MAX_SIZE = 1e7 + 1;
int n, t, m, q, k, p;
const int size = 1 << 10;
int dp1[size][size], dp2[size][size], dp3[size][size], dp4[size][size];
int mat[size][size];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> mat[i][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      dp1[i][j] = mat[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    for (int j = m; j >= 1; --j)
      dp4[i][j] = mat[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j)
      dp2[i][j] = mat[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
    for (int j = 1; j <= m; ++j)
      dp3[i][j] = mat[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
  }
  int ans = -1;
  for (int i = 2; i < n; ++i)
    for (int j = 2; j < m; ++j)
      ans = max(
          ans,
          max(dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1],
              dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]));
  cout << ans << '\n';
  cin >> n;
}
