#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, k;
long long dp[N][N], a[N], pre[N];
void init() {
  for (int i = 0; i < n; i++) {
    fill(dp[i], dp[i] + N, -1);
    pre[i] = a[i] + (i > 0 ? pre[i - 1] : 0);
  }
}
long long get(int from, int to) {
  return pre[to] - (from > 0 ? pre[from - 1] : 0);
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  init();
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      for (int r = 1; r <= k; ++r) dp[i][r] = dp[i - 1][r];
    }
    for (int r = 1; r <= k; r++) {
      int j = i - m + 1;
      if (r == 1) {
        if (j >= 0) {
          dp[i][r] = max(dp[i][r], get(j, i));
        }
        continue;
      }
      if (j > 0 && dp[j - 1][r - 1] != -1) {
        dp[i][r] = max(dp[i][r], dp[j - 1][r - 1] + get(j, i));
      }
    }
  }
  cout << dp[n - 1][k] << endl;
  return 0;
}
