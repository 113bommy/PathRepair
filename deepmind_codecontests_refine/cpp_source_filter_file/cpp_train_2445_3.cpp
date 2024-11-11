#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long a, b, q;
  cin >> a >> b >> q;
  auto sm = [&](long long n, long long f) {
    return n * (2 * f + (n - 1) * b) / 2;
  };
  while (q--) {
    long long l, t, m;
    cin >> l >> t >> m;
    long long rl = l, rr = 1e14;
    long long r = -1;
    long long first = a + (l - 1) * b;
    while (rl <= rr) {
      long long mid = (rl + rr) / 2;
      long long tot = mid - l + 1;
      long long lst = a + (mid - 1) * b;
      if (sm(tot, first) <= m * t and lst <= t) {
        rl = mid + 1;
        r = mid;
      } else
        rr = mid - 1;
    }
    cout << r << "\n";
  }
}
