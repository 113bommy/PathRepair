#include <bits/stdc++.h>
using namespace std;
int n, t, len, ans;
int a[10002], dp[10002], cnt[302];
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  len = n * min(n, t);
  for (int i = n + 1; i <= len; i++) {
    a[i] = a[i - n];
  }
  ans = 1;
  for (int i = 1; i < 10002; i++) {
    dp[i] = 1;
  }
  for (int i = 2; i <= len; i++) {
    for (int j = 1; j < i; j++) {
      if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }
  if (n >= t)
    cout << ans << endl;
  else {
    int maxcnt = 0;
    for (int i = 1; i < 302; i++) maxcnt = max(maxcnt, cnt[i]);
    cout << ans + maxcnt * (t - n) << endl;
  }
  return 0;
}
