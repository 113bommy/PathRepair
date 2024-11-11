#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      cout << -1 << '\n';
      continue;
    }
    long long bs = 0;
    long long l = 0, r = c / d;
    while (l < r) {
      long long m = (l + r) / 2;
      long long dr = a + a * m - m * (m + 1) * b * d / 2;
      long long dp = a + a * (m + 1) - (m + 1) * (m + 2) * b * d / 2;
      long long dt = dp - dr;
      bs = max(bs, dr);
      if (dt >= 0) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    bs = max(bs, a + a * l - l * (l + 1) * b * d / 2);
    cout << bs << '\n';
  }
}
