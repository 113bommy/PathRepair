#include <bits/stdc++.h>
long long int a, n, m, l, r;
const int N = 2003;
long long int rain[N], umbrella[N], dp[N];
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    for (int j = l; j <= r; j++) rain[j] = 1;
  }
  for (int i = 0; i <= a; i++) umbrella[i] = 1e18;
  for (int i = 1; i <= a; i++) dp[i] = 1e18;
  dp[0] = 0;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    umbrella[l] = min(umbrella[l], r);
  }
  for (int i = 0; i < a; i++) {
    if (dp[i] == 1e18) continue;
    if (rain[i] == 0) {
      dp[i + 1] = min(dp[i + 1], dp[i]);
    }
    if (umbrella[i] != 1e18) {
      for (int j = i + 1; j <= a; j++) {
        dp[j] = min(dp[j], dp[i] + abs(i - j) * umbrella[i]);
      }
    }
  }
  if (dp[a] == 1e18)
    cout << "-1";
  else
    cout << dp[a];
  return 0;
}
