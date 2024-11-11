#include <bits/stdc++.h>
using namespace std;
long long h, c, t;
double f(long long n) { return abs(t - (h + (h + c) * n) * 1.0 / (2 * n + 1)); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int nTest = 0;
  cin >> nTest;
  while (nTest--) {
    cin >> h >> c >> t;
    if (h + c == 2 * t) {
      cout << 2 << "\n";
      continue;
    }
    long long l = 0, r = t + 1, m;
    while (r - l > 1) {
      m = (l + r) >> 1;
      if (f(m) < f(m - 1))
        l = m;
      else
        r = m;
    }
    cout << l * 2 + 1 << "\n";
  }
  return 0;
}
