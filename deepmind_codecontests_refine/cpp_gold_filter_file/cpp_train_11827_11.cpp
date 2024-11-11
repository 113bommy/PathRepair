#include <bits/stdc++.h>
using namespace std;
long long int sum1, sum[10000005], a[10000005], n, s;
long long int solve(long long int k) {
  long long int i;
  sum1 = 0;
  memset(sum, 0, sizeof(sum));
  for (i = 1; i <= n; i++) sum[i] = a[i] + i * k;
  sort(sum + 1, sum + n + 1);
  for (i = 1; i <= k; i++) sum1 = sum1 + sum[i];
  if (sum1 <= s)
    return 1;
  else
    return 0;
}
int main() {
  while (scanf("%lld%lld", &n, &s) != EOF) {
    long long int i;
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; i++) cin >> a[i];
    long long int num = 0, ans = 0, l = 0, r = n, mid;
    while (r - l >= 0) {
      mid = (l + r) / 2;
      if (solve(mid)) {
        num = mid;
        ans = sum1;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << num << " " << ans << endl;
  }
}
