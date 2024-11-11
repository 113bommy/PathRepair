#include <bits/stdc++.h>
using namespace std;
int n, d, c[55];
int dp[500010];
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(c, c + n);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 500000 - c[i]; j >= 0; j--)
      if (dp[j] != -1) dp[j + c[i]] = max(dp[j + c[i]], dp[j] + 1);
  }
  int l, r;
  for (l = 0, r = 0; r <= 500000 && r - l <= d; r++) {
    if (dp[r] != -1) l = r;
  }
  int days = 0;
  for (int i = 1, prev = 0, j = 0; i <= l; i++) {
    if (dp[i] != -1) {
      if (i - prev > d) {
        days++;
        prev = j;
      }
      j = i;
    }
  }
  cout << l << ' ' << days + (days != 0) << '\n';
}
