#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, d, ans = 0;
  cin >> n >> d;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (a[j] - a[i] <= d) ans++;
    }
  }
  cout << ans;
}
