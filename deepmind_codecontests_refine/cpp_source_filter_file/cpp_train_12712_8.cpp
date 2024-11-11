#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long maxn = (long long)1e5 + 5;
const long long mod = (long long)1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long sum[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    sum[i] = sum[i - 1] + x;
    for (long long j = 0; j < i; ++j)
      if (sum[i] - sum[j] > 100 * (i - j - 1)) ans = max(ans, i - j - 1);
  }
  cout << ans;
  return 0;
}
