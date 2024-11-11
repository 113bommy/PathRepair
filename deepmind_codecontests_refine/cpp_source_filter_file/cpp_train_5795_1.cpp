#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long a[N], dp[N], n, ans = 0;
long long l[N];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  l[n] = a[n] + 1;
  long long now = a[n];
  for (int i = n - 1; i >= 1; i--) {
    now--;
    now = max(a[i] + 1, now);
    l[i] = now;
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i - 1], a[i] + 1);
    dp[i] = max(dp[i], l[i]);
  }
  for (int i = 1; i <= n; i++) ans += dp[i] - a[i];
  cout << ans - n << endl;
  return 0;
}
