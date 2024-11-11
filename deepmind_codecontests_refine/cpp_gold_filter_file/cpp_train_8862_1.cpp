#include <bits/stdc++.h>
using namespace std;
int a[6000], dp[6000][6000], ct[6000];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  if (n == 1) {
    cout << n << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    ct[i] = i + 1 - (lower_bound(a + 1, a + n + 1, a[i] - 5) - a);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - ct[i]][j - 1] + ct[i]);
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
