#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, k, M;
  cin >> n >> k >> M;
  long long dup = M;
  long long ans = 0ll;
  long long a[k];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + k);
  long long sum = accumulate(a, a + k, 0ll);
  for (long long i = 0; i <= n; i++) {
    M = dup;
    M -= i * (sum);
    if (M < 0) break;
    long long cur = i * (k + 1);
    for (long long j = 0; j < k; j++) {
      long long tot = min(M / a[j], n - i);
      M -= tot * a[j];
      cur += tot;
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;
}
