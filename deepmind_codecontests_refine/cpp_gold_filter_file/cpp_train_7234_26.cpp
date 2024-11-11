#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const long long INF = 1e18;
const int MX = 100005;
int N;
long long a[MX], ans = 1, dp[MX], dist = 0;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = (0); i < (N); ++i) {
    cin >> a[i];
  }
  while (N - 1 - dist >= dist) {
    dp[dist] = dp[N - 1 - dist] = dist + 1;
    if (a[dist] < dp[dist]) dp[dist] = a[dist];
    if (a[N - 1 - dist] < dp[N - 1 - dist]) dp[N - 1 - dist] = a[N - 1 - dist];
    ++dist;
  }
  for (int i = (1); i < (N); ++i) {
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }
  for (int i = (N - 1) - 1; i >= (0); --i) {
    dp[i] = min(dp[i], dp[i + 1] + 1);
    if (dp[i] > ans) ans = dp[i];
  }
  cout << ans;
  return 0;
}
