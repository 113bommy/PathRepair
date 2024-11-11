#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, x, c, d, sum = 0, p;
    cin >> a >> b >> x;
    c = min(a, b);
    d = max(a, b);
    if (a == 0 || b == 0) {
      sum = 0;
    } else if (x == 0) {
      if (2 * c <= d) {
        sum = c;
      } else {
        sum = (a + b) / 3;
      }
    } else if (c > x) {
      c = c - x;
      d = d - x;
      p = c * 2;
      if (p <= d) {
        sum = x + c;
      } else {
        sum = x + (c + d) / 3;
      }
    } else if (c <= x) {
      sum = c;
    }
    cout << sum << endl;
  }
}
