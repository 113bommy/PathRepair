#include <bits/stdc++.h>
using namespace std;
const int base = 100003;
const long long MM = 1ll * 1000000007 * 1000000007;
int n, m, a[205], b[205];
int dp[205][512];
vector<int> And[205];
void Solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) And[i].push_back(a[i] & b[j]);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < (1 << 9); ++j)
      for (auto x : And[i]) dp[i][j | x] |= dp[i - 1][j];
  for (int i = 0; i < (1 << 9); ++i) {
    if (dp[n][i]) {
      cout << i;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) Solve();
}
