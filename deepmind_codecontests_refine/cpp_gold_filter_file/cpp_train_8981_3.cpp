#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long INF = (1LL << 60) - 1;
const long long maxN = 1000001;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a[n][m];
    long long cnt = 0, res = INF, ans = 0;
    for (long long i = 0; i < n; ++i) {
      for (long long j = 0; j < m; ++j) {
        cin >> a[i][j];
        res = min(res, abs(a[i][j]));
        ans += abs(a[i][j]);
        if (a[i][j] <= 0) cnt++;
      }
    }
    if (cnt & 1) {
      cout << ans - 2 * res << "\n";
    } else {
      cout << ans << "\n";
    }
  }
}
