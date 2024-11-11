#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(20, -1));
  vector<int> last(20, n);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 20; ++j) {
      if (a[i] & (1 << j)) {
        dp[i][j] = i;
        for (int k = 0; k < 20; ++k) {
          dp[i][k] = max(dp[i][k], dp[last[j]][k]);
        }
        last[j] = i;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    bool reach = false;
    for (int j = 0; j < 20; ++j) {
      if (a[y] & (1 << j)) {
        if (dp[i][j] >= y) {
          reach = true;
          break;
        }
      }
    }
    if (reach) {
      cout << "Shi\n";
    } else {
      cout << "Fou\n";
    }
  }
}
