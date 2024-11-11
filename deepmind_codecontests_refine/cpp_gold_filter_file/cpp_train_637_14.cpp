#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  ;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  ;
  long long b[m];
  for (long long i = 0; i < m; i++) cin >> b[i];
  ;
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  for (long long i = 0; i <= n - 1; i++) {
    if (a[i] % 2 == 0)
      a1++;
    else
      a2++;
  }
  for (long long i = 0; i <= m - 1; i++) {
    if (b[i] % 2 == 0)
      b1++;
    else
      b2++;
  }
  long long ans = min(a1, b2) + min(a2, b1);
  cout << ans << "\n";
  return 0;
}
