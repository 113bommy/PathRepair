#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000 + 10;
int n, k, a[MAX_N], dp[2][MAX_N];
bool check(int x) {
  for (int i = 1; i < n; i++) {
    dp[0][i] = dp[1][i] = i;
    for (int j = i - 1; ~j; j--)
      if (abs(a[i] - a[j]) <= (i - j) * x)
        dp[0][i] = min(dp[0][i], dp[0][j] + i - j - 1);
    dp[1][i] = min(dp[1][i - 1] + 1, dp[0][i]);
  }
  return dp[1][n - 1] <= k;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int L = -1, R = 2e9 + 10;
  while (L + 1 < R) {
    int mid = (1LL * L + R) >> 1;
    check(mid) ? R = mid : L = mid;
  }
  cout << R << endl;
  return 0;
}
