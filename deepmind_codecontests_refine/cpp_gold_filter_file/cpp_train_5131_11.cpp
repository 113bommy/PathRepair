#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c * b) {
      cout << "-1\n";
      continue;
    }
    if (c <= d) {
      cout << a << '\n';
      continue;
    }
    long long K = (c + d - 1) / d, k = (2 * a + 1) / (2 * d * b), ans = 0;
    for (long long i = max(0ll, k - 50); i <= min(K, k + 50); i++) {
      long long x = i * a - i * (i - 1) / 2 * d * b;
      ans = max(ans, x);
    }
    ans = max(ans, K * a - K * (K - 1) / 2 * d * b);
    cout << ans << '\n';
  }
}
