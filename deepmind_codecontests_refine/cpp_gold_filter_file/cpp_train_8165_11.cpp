#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e5 + 5;
int64_t mass[MAX];
int64_t dp[MAX][2];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t n;
  cin >> n;
  int64_t arr[n];
  for (int64_t i = 0; i < n; ++i) cin >> arr[i];
  for (int64_t i = 0; i < n; ++i) mass[arr[i]]++;
  for (int64_t i = 0; i < MAX; ++i) {
    if (i - 1 >= 0) dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = mass[i] * i;
    if (i - 1 >= 0) dp[i][1] += dp[i - 1][0];
  }
  cout << max(dp[MAX - 1][0], dp[MAX - 1][1]);
  return 0;
}
