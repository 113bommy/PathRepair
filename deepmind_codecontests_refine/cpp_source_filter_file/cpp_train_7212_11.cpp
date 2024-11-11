#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 50;
int n, k, c[N];
long long *sm[N], ans;
long long dp[18][N];
void work(int d, int l, int r) {
  if (l == r) {
    for (int i = 0; i <= k; i++)
      if (k - i <= c[l]) ans = max(ans, dp[d - 1][i] + sm[l][k - i]);
    return;
  }
  int mid = (l + r) >> 1;
  for (int i = 0; i <= k; i++) dp[d][i] = dp[d - 1][i];
  for (int i = l; i <= mid; i++)
    for (int j = k; j >= c[i]; j--)
      dp[d][j] = max(dp[d][j], dp[d][j - c[i]] + sm[i][c[i]]);
  work(d + 1, mid + 1, r);
  for (int i = 0; i <= k; i++) dp[d][i] = dp[d - 1][i];
  for (int i = mid + 1; i <= r; i++)
    for (int j = k; j >= c[i]; j--)
      dp[d][j] = max(dp[d - 1][j], dp[d][j - c[i]] + sm[i][c[i]]);
  work(d + 1, l, mid);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sm[i] = new long long[c[i] + 1]();
    for (int j = 1; j <= c[i]; j++)
      scanf("%lld", &sm[i][j]), sm[i][j] += sm[i][j - 1];
  }
  work(1, 1, n);
  cout << ans;
  return 0;
}
