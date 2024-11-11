#include <bits/stdc++.h>
using namespace std;
const int lmt = 1e3 + 100;
int n, k, a[lmt][6], pos[lmt][6], dp[lmt], ans = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int c = 1; c <= k; c++) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i][c];
      pos[a[i][c]][c] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      bool ok = 1;
      for (int c = 1; c <= k; c++) {
        if (pos[a[i][1]][c] < pos[a[j][1]][c]) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      ans = max(ans, dp[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}
