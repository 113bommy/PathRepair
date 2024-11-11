#include <bits/stdc++.h>
using namespace std;
const long long siz = 1e6 + 5;
long long t, n, T, m, x, pos, a[siz], mx, cnt[siz], dp[siz];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> T;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    mx = max(mx, cnt[a[i]]);
  }
  long long ans = 0;
  long long l = n;
  while (--T and l < 1000) {
    for (long long i = 1; i <= n; i++) a[++l] = a[i];
  }
  for (long long i = 1; i <= l; i++) {
    dp[i]++;
    for (long long j = 1; j < i; j++)
      if (a[i] >= a[j]) dp[i] = max(dp[i], 1 + dp[j]);
    ans = max(ans, dp[i]);
  }
  cout << ans + mx * T << endl;
}
