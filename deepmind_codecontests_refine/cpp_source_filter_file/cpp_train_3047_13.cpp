#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int dp[n + 1][2];
  dp[0][0] = a[0] * r1 + r3;
  dp[0][1] = min((a[0] + 1) * r1, r2);
  for (int i = 1; i < n; i++) {
    dp[i][0] = min(dp[i - 1][0] + d + a[i] * r1 + r3,
                   dp[i - 1][1] + d * 3 + 2 * r1 + min(r1 * (a[i] + 1), r2));
    dp[i][1] = min(dp[i - 1][0] + d + min(r2, (a[i] + 1) * r2),
                   dp[i - 1][1] + d * 3 + r1 + min(r1 * (a[i] + 1), r2));
  }
  long long ans =
      min(dp[n - 1][0], dp[n - 2][1] + 2 * d + r1 + a[n - 1] * r1 + r3);
  cout << ans << "\n";
}
