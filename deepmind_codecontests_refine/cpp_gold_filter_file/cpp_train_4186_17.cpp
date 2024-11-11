#include <bits/stdc++.h>
using namespace std;
long long t, a[1010], n, l, ans;
signed main() {
  ios::sync_with_stdio(false);
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    long long p = 0, ans;
    cin >> n;
    memset(a, 0, sizeof(a));
    char s[n + 1];
    cin >> s;
    for (long long j = 0; j < n; j++) {
      if (s[j] == '1') {
        p++;
        a[p] = j;
      }
    }
    if (!p)
      cout << n << endl;
    else if (p == 1)
      cout << 2 * (max(a[1], n - 1 - a[1]) + 1) << endl;
    else {
      ans = n + p;
      for (long long j = 1; j <= p; j++) {
        ans = max(ans, 2 * (max(a[j], n - 1 - a[j]) + 1));
      }
      ans = min(2 * n, ans);
      cout << ans << endl;
    }
  }
  return 0;
}
