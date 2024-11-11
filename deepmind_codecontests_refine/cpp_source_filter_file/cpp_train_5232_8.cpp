#include <bits/stdc++.h>
using namespace std;
int main() {
  int nTest;
  cin >> nTest;
  while (nTest--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vector<int> b;
    vector<int> pos(n, 0);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a.push_back({x, i});
      b.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) pos[i] = a[i].second;
    int ans = 0;
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (pos[i - 1] < pos[i])
        dp[i] = dp[i - 1] + 1;
      else
        dp[i] = 1;
      ans = max(ans, dp[i]);
    }
    cout << n - ans << '\n';
  }
  return 0;
}
