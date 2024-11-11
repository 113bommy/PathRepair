#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long n, q, a[300005], dp[300005], dp1[300005], dp2[300005], mx;
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    dp[i] = max(dp[i - 1] + a[i], a[i]);
    dp1[i] =
        max(dp[i - 1] + (a[i] * q), max(dp1[i - 1] + (a[i] * q), a[i] * q));
    dp2[i] = max(dp1[i - 1] + a[i], dp2[i - 1] + a[i]);
    mx = max(max(mx, dp[i]), max(dp1[i], dp2[i]));
  }
  cout << mx;
}
