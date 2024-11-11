#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;
long long a[N], b[N];
long long n, ans;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  b[0] = 0;
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
    b[i] = b[i - 1] + a[i];
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = i; j < n + 1; j++) {
      long long t = j - i + 1, s = b[j] - b[i - 1];
      if (s > 100 * t) {
        ans = max(ans, t);
      }
    }
  }
  cout << ans;
}
