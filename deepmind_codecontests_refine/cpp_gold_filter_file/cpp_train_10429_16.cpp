#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 3;
int dp[MAX];
void precalc(int n) {
  for (int i = 1; i <= n; ++i) {
    dp[i] = i;
  }
  for (int i = 2; i <= n; ++i) {
    if (dp[i] == i) {
      --dp[i];
      for (int j = i * 2; j <= n; j += i) {
        dp[j] = dp[j] / i * (i - 1);
      }
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << 3 << endl;
    return;
  }
  precalc(n);
  sort(dp, dp + n + 1);
  long long res = 0;
  for (int i = 1; i <= k + 2; ++i) {
    res += dp[i];
  }
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}
