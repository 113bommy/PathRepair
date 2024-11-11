#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
bool typetest;
inline void fastIOfileinput() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  typetest = 0;
}
const int N = 1e3 + 5;
int m, n;
ll a[N][N];
ll dp1[N][N], dp2[N][N], dp3[N][N], dp4[N][N];
void Read() {
  cin >> m >> n;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
}
void Solve() {
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
  for (int i = 1; i <= m; ++i)
    for (int j = n; j; --j)
      dp2[i][j] = max(dp2[i - 1][j], dp2[i][j + 1]) + a[i][j];
  for (int i = m; i; --i)
    for (int j = 1; j <= n; ++j)
      dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + a[i][j];
  for (int i = m; i; --i)
    for (int j = n; j; --j)
      dp4[i][j] = max(dp4[i + 1][j], dp4[i][j + 1]) + a[i][j];
  ll ans(0);
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      ll tmp = dp1[i - 1][j] + dp2[i][j + 1] + dp4[i + 1][j] + dp3[i][j - 1];
      ans = max(ans, tmp);
      tmp = dp1[i][j - 1] + dp2[i - 1][j] + dp4[i][j + 1] + dp3[i + 1][j];
      ans = max(ans, tmp);
    }
  cout << ans;
}
int32_t main() {
  fastIOfileinput();
  if (typetest) {
    int t;
    cin >> t;
    for (int v = 1; v <= t; ++v) {
      Read();
      Solve();
    }
  } else {
    Read();
    Solve();
  }
}
