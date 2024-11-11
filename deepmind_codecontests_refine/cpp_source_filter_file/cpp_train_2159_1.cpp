#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int ans[5005][5005];
int solve(int l, int r) {
  if (dp[l][r]) {
    return dp[l][r];
  }
  if (l == r) {
    return dp[l][r] = ans[l][r];
  } else {
    return dp[l][r] = max({ans[l][r], solve(l, r - 1), solve(l + 1, r)});
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> ans[i][i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      ans[j][j + i] = ans[j][j + i - 1] ^ ans[j + 1][j + i];
    }
  }
  for (int i = 1; i < n + 1; i++) {
    dp[i][i] = ans[i][i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      dp[j][j + i] = max({dp[j][j + i - 1], dp[j + 1][j + i], ans[i][j + i]});
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[l][r] << '\n';
  }
}
