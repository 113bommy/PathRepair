#include <bits/stdc++.h>
using namespace std;
using ii = pair<long long, long long>;
long long mod = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long hr;
  for (long long i = 0; i < 64; i++) {
    if ((1LL << i) >= k) {
      hr = i;
      break;
    }
  }
  long long done = (1 << hr);
  if (n <= done) {
    for (long long i = 0; i <= hr; i++) {
      if ((1 << i) >= n) {
        cout << i << "\n";
        ;
        return;
      }
    }
  } else {
    long long ans = hr;
    ans += ceil((n - done) / (1.0 * k));
    cout << ans << "\n";
    ;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long _t;
  cin >> _t;
  while (_t--) solve();
  return 0;
}
