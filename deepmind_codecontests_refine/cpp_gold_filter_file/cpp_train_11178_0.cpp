#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  float y;
  vector<int> v;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(x);
  }
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int ans = -99;
    for (int j = 0; j < i; j++) {
      if (v[j] <= v[i]) {
        ans = max(ans, 1 + dp[j]);
      }
    }
    if (ans != -99)
      dp[i] = ans;
    else
      dp[i] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
  cout << n - ans;
  return 0;
}
