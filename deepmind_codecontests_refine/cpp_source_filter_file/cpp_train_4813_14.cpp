#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  ;
  long long i, j, k, ii, jj, kk;
  while (t--) {
    long long a;
    cin >> a;
    ;
    long long b;
    cin >> b;
    ;
    long long c;
    cin >> c;
    ;
    long long ans = inf;
    for (i = 1; i <= 10000; i++) {
      for (j = i; j <= 10000; j += i) {
        for (k = j; k <= 10000; k += j) {
          if (ans > abs(i - a) + abs(j - b) + abs(k - c)) {
            ans = min(ans, abs(i - a) + abs(j - b) + abs(k - c));
            ii = i;
            jj = j;
            kk = k;
          }
        }
      }
    }
    cout << ans << "\n";
    cout << ii << " " << jj << " " << kk << "\n";
  }
  return 0;
}
