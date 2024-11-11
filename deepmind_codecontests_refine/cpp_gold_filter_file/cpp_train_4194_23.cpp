#include <bits/stdc++.h>
using namespace std;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);
long long f(long long x, long long a, long long b, long long c, long long d) {
  long long ans = (x - 1) / d + 1;
  return ans * a - (ans * (x - 1) - ans * (ans - 1) / 2 * d) * b;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  for (long long iq = 0; iq < q; iq++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b * c < a) {
      cout << "-1\n";
      continue;
    }
    long long l = 0, r = c / d + 1;
    while (r - l > 9) {
      long long m1 = (2 * l + r) / 3;
      long long m2 = (l + 2 * r) / 3;
      if (f(m1 * d + 1, a, b, c, d) < f(m2 * d + 1, a, b, c, d))
        l = m1;
      else
        r = m2;
    }
    long long ans = 0;
    for (long long i = l; i <= r; i++) ans = max(ans, f(i * d + 1, a, b, c, d));
    cout << ans << "\n";
  }
  return 0;
}
