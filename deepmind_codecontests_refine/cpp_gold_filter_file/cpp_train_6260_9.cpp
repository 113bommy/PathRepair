#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], sum[N];
int dp[(1 << 20) + 5][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = a[i] ^ sum[i - 1];
    }
    long long ans = 0;
    dp[0][0]++;
    for (int i = 1; i <= n; i++) {
      ans += dp[sum[i]][i & 1];
      dp[sum[i]][i & 1]++;
    }
    cout << ans << endl;
  }
  return 0;
}
