#include <bits/stdc++.h>
const int maxn = 2e5 + 1;
int a[maxn], s[maxn], dp[maxn];
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] += a[i] + s[i - 1];
  }
  dp[n] = s[n] - s[n - k];
  for (int i = n - 1; i >= k; --i) {
    dp[i] = min(dp[i + 1], s[i] - s[i - k]);
  }
  long long ans = 0;
  for (int i = k; i <= n; ++i) {
    if (s[i + k - 1] - s[i - 1] == dp[k]) {
      ans = i;
      break;
    }
  }
  cout << ans;
  return 0;
}
