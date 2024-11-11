#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 5010;
const int mod = 1000000007;
const double eps = 1e-8;
const double Pi = 2 * acos(0.0);
int n, dp[M], b[M];
long long a[M];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (a[i] % 2 == 0) {
      b[i]++;
      a[i] /= 2;
    }
  }
  int ans = n;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    dp[i] = i;
    for (int j = i - 1; j >= 0; j--)
      if (a[j] % a[i] == 0 && (b[j] + i - j == b[i] || b[i] <= i - j - 1))
        dp[i] = min(dp[j] + i - j - 1, dp[i]);
    ans = min(ans, n - i - 1 + dp[i]);
  }
  cout << ans << endl;
  return 0;
}
