#include <bits/stdc++.h>
using namespace std;
long long a[100009];
long long dp[5][100009];
long long from[5][100009];
signed main() {
  long long n;
  cin >> n;
  for (long long i = 1; i < n + 1; ++i) cin >> a[i];
  for (long long i = 0; i < 5; ++i) dp[i][1] = 1;
  for (long long i = 1; i < n; ++i)
    for (long long j = 0; j < 5; ++j)
      for (long long k = 0; k < 5; ++k) {
        if (a[i] < a[i + 1] && k > j && dp[j][i]) {
          dp[k][i + 1] = 1;
          from[k][i + 1] = j;
        } else if (a[i] > a[i + 1] && k < j && dp[j][i]) {
          dp[k][i + 1] = 1;
          from[k][i + 1] = j;
        } else if (a[i] == a[i + 1] && j != k && dp[j][i]) {
          dp[k][i + 1] = 1;
          from[k][i + 1] = j;
        }
      }
  long long ok = 0;
  for (long long i = 0; i < 5; ++i) ok |= dp[i][n];
  if (!ok) return cout << -1, 0;
  vector<long long> ans;
  long long now = 0;
  for (long long i = 0; i < 5; ++i)
    if (dp[i][n]) now = i;
  while (n) {
    ans.push_back(now);
    now = from[now][n];
    --n;
  }
  reverse((ans).begin(), (ans).end());
  for (auto i : ans) cout << i + 1 << " ";
}
