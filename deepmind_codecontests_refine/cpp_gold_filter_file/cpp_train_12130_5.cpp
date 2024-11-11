#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int n;
int dp[MAX + 3], b[MAX + 3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    cin >> b[x];
  }
  if (b[0]) dp[0] = 1;
  for (int i = 1; i <= MAX; i++) {
    if (!b[i])
      dp[i] = dp[i - 1];
    else if (b[i] >= i)
      dp[i] = 1;
    else
      dp[i] = dp[i - b[i] - 1] + 1;
  }
  cout << n - *max_element(dp, dp + MAX + 2) << '\n';
  return 0;
}
