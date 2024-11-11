#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
int main() {
  std::ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<int> dp(n, 0);
  dp[n - 1] = 1 - v[n - 1];
  for (int i = n - 1; i > 0; --i) {
    if (v[i - 1] == 0)
      dp[i - 1] = dp[i] + 1;
    else
      dp[i - 1] = dp[i];
  }
  int ct = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] == 1) {
      ct += dp[i];
    }
  }
  cout << ct << endl;
  return 0;
}
