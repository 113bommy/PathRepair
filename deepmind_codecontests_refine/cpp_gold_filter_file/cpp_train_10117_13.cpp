#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v(500001, 0);
  vector<vector<int>> dp(1001, vector<int>(1001, 0));
  int q;
  cin >> q;
  for (int t = 0; t < q; t++) {
    int k, x, y;
    cin >> k >> x >> y;
    if (k == 1) {
      v[x] += y;
      for (int i = 1; i <= 1000; i++) dp[i][(x % i)] += y;
    } else {
      if (x <= 1000 && y <= 1000) {
        cout << dp[x][y] << "\n";
      } else {
        int sum = 0;
        for (int i = y; i <= 500000; i += x) {
          sum += v[i];
        }
        cout << sum << "\n";
      }
    }
  }
}
