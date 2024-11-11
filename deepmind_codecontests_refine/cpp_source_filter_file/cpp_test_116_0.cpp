#include <bits/stdc++.h>
using namespace std;
const long long int N = (long long int)(5e5 + 5);
const long long int inf = 2e18;
const long long int M1 = (long long int)(1e9 + 7);
const long long int M2 = (long long int)(998244353);
long long int n, m, a, b, c, d;
long long int w, h;
long long int x, y;
long long int t;
long long int dp[N][2];
void solve() {
  cin >> n;
  for (long long int i = 0; i <= n + 1; i++) {
    dp[i][0] = dp[i][1] = 0;
  }
  vector<long long int> arr;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    x = arr[i];
    if (x == 0) {
      ans += 1 + dp[0][0] + dp[2][1];
      dp[2][1] = (2 * dp[2][1]) % M2;
      dp[0][0] = (2 * dp[0][0] + 1) % M2;
    } else if (x == 1) {
      ans += dp[0][0] + dp[1][0] + dp[1][1] + dp[3][1] + 1;
      dp[3][1] = (2 * dp[3][1]) % M2;
      dp[1][1] = (2 * dp[1][1] + 1) % M2;
      dp[1][0] = (dp[1][0] + dp[0][0]) % M2;
    } else {
      ans += dp[x - 2][0] + dp[x - 1][0] + dp[x][0] + dp[x][1] + dp[x + 1][1];
      dp[x + 1][1] = (2 * dp[x + 1][1]) % M2;
      dp[x][0] = (2 * dp[x][0] + dp[x - 1][0]) % M2;
      dp[x][1] = (dp[x - 2][0] + 2 * dp[x][1]) % M2;
    }
    ans = ans % M2;
  }
  cout << ans % M2 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
