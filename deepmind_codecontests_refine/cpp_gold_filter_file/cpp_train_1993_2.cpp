#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[5010][5010];
int a[5010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int ik = 1; ik <= k; ++ik) {
    int j = 1;
    for (int i = 1; i <= n; ++i) {
      dp[i][ik] = dp[i - 1][ik];
      while (a[j] + 5 < a[i]) ++j;
      dp[i][ik] = max(dp[i][ik], dp[j - 1][ik - 1] + (i - j + 1));
    }
  }
  cout << dp[n][k];
  return 0;
}
