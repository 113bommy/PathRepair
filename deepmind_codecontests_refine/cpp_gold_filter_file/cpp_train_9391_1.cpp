#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, r;
    cin >> a >> b >> c >> r;
    long long x = c - r;
    long long y = c + r;
    if (a > b) swap(a, b);
    long long te = abs(a - b);
    long long ans = 0;
    if (c >= a && c <= b) {
      ans = ans + min(r, c - a);
      ans = ans + min(r, b - c);
    } else if (c >= a)
      ans = ans + max(0LL, r - c + b);
    else
      ans = ans + max(0LL, r - a + c);
    cout << max(0LL, te - ans) << "\n";
  }
}
