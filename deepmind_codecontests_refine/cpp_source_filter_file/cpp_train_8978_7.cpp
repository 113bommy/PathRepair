#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(2 * n + 1);
  for (long long i = 1; i <= 2 * n; i++) {
    cin >> v[i];
  }
  vector<long long> groups;
  long long cur = 2 * n;
  for (long long i = 1; i <= 2 * n; i++) {
    long long mx = 0, pos;
    for (long long j = 1; j <= cur; j++) {
      if (mx < v[j]) {
        mx = v[j];
        pos = j;
      }
    }
    if ((cur - pos + 1)) {
      groups.push_back(cur - pos + 1);
    }
    cur = pos - 1;
  }
  const long long N = (long long)groups.size();
  vector<vector<long long>> dp(N + 1, vector<long long>(2 * n + 1, 0));
  dp[0][0] = 1;
  sort(groups.begin(), groups.end());
  42;
  for (long long i = 1; i <= N; i++) {
    for (long long j = 0; j <= n; j++) {
      if (j == 0) {
        dp[i][j] = 1;
        continue;
      }
      dp[i][j] |= dp[i - 1][j];
      if (~(j - groups[i - 1])) {
        dp[i][j] |= dp[i - 1][j - groups[i - 1]];
      }
    }
  }
  42;
  cout << (dp[N][n] ? "Yes" : "No") << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
