#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e3 + 5;
int a[N], dp[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    while (j > 0 && (a[i] - a[j]) <= 5) {
      j--;
    }
    for (int l = 1; l <= k; l++) {
      dp[i][l] = max(dp[i - 1][l], dp[j][l - 1] + i - j);
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans;
}
