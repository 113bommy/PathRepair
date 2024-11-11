#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
long long l[N], r[N], a[N], dp[N];
int n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> a[i];
  for (int i = n; i >= 1; i--) {
    long long need = a[i];
    if (i + 1 <= n && r[i] == l[i + 1]) need += dp[i + 1];
    if (k * (r[i] - l[i] + 1) < need) {
      puts("-1");
      return 0;
    }
    dp[i] = max(0ll, need - k * (r[i] - l[i]));
  }
  long long ans = 0, remain = k;
  for (int i = 1; i <= n; i++) {
    if (remain < dp[i]) {
      ans += remain;
      remain = k;
    }
    ans += a[i];
    remain = ((remain - a[i]) % k + k) % k;
  }
  cout << ans << endl;
  return 0;
}
