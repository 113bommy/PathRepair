#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long sum[N];
long long a[N];
void solve() {
  long long n;
  long long k, s = 0;
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    s += a[i];
  }
  if (s <= k) {
    puts("0");
    return;
  }
  if (n == 1) {
    printf("%lld\n", a[1] - k);
    return;
  }
  sort(a + 1, a + 1 + n);
  sum[n + 1] = 0;
  for (long long i = n; i >= 1; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  long long res = s - k;
  for (long long i = n; i >= 2; i--) {
    long long cnt = n - i + 1;
    long long cur = sum[2] + (cnt + 1) * a[1] - k - sum[i];
    cur = max(0LL, cur);
    long long t = cur / (cnt + 1);
    while (t * (cnt + 1) < cur) t++;
    res = min(res, t + cnt);
  }
  printf("%lld\n", res);
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
