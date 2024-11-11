#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
int c[maxn];
int dp[maxn][maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int len = n - 1; len > 0; len--) {
    for (int i = 0; i < n - len + 1; i++) {
      if (i != 0 && c[i] == c[i - 1]) continue;
      if (i != n - len && c[i + len - 1] == c[i + len]) continue;
      int l = max(i - 1, 0);
      while (true) {
        if (l == 0 || c[l] != c[l - 1]) break;
        l--;
      }
      int r = min(i + len, n - 1);
      while (true) {
        if (r == n - 1 || c[r] != c[r + 1]) break;
        r++;
      }
      if (c[l] == c[r] || i == 0 || i == n - len)
        dp[len][i] = dp[r - l + 1][l] + 1;
      else {
        dp[len][i] = min(dp[r - i + 1][i], dp[i + len - l][l]) + 1;
      }
    }
  }
  int last = 0, ans = 1e9;
  for (int i = 0; i < n; i++) {
    if (i == n - 1 || c[i] != c[i + 1]) {
      ans = min(ans, dp[i - last + 1][last]);
      last = i + 1;
    }
  }
  cout << ans;
  return 0;
}
