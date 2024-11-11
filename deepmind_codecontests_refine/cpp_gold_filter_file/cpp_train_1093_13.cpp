#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
void solve() {
  long long n, i, l, ans = 0, k;
  cin >> n >> k;
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    cin >> l;
    a.push_back(l);
  }
  if (k >= n) {
    cout << a[n - 1];
    return;
  }
  for (i = 0; i < (n - k); i++) {
    ans = max(ans, a[i] + a[2 * (n - k) - 1 - i]);
  }
  ans = max(ans, a[n - 1]);
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
