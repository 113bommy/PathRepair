#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  long long a[n + 1], b[m + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long j = 1; j <= m; j++) cin >> b[j];
  long long pf[n + 1];
  pf[0] = 0;
  for (long long i = 1; i <= n; i++) pf[i] = pf[i - 1] + a[i];
  for (long long i = 1; i <= m; i++) {
    long long l = 1, r = n;
    while (l < r - 1) {
      long long cur = (l + r) / 2;
      if (pf[cur] > b[i])
        r = cur;
      else
        l = cur;
    }
    if (a[l] < b[i]) swap(l, r);
    cout << l << " " << b[i] - pf[l - 1] << "\n";
  }
}
