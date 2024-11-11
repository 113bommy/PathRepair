#include <bits/stdc++.h>
using namespace std;
int a[505], b[505], dp[505], pr[505];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    int o = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        dp[j] = dp[o] + 1;
        pr[j] = o;
      }
      if (a[i] > b[j] && dp[j] > dp[o]) {
        o = j;
      }
    }
  }
  int idx = 0;
  for (int i = 1; i <= m; ++i) {
    if (dp[i] > dp[idx]) {
      idx = i;
    }
  }
  vector<int> sol;
  while (idx) {
    sol.push_back(b[idx]);
    idx = pr[idx];
  }
  cout << sol.size() << endl;
  for (int i = sol.size() - 1; i >= 0; --i) {
    cout << sol[i] << ' ';
  }
  return 0;
}
