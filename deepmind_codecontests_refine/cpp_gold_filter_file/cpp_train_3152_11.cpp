#include <bits/stdc++.h>
using namespace std;
unsigned long long int inf(~inf);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, x, y, n;
  long long int a, b, sol(0);
  cin >> t;
  while (t--) {
    cin >> a >> b >> x >> y >> n;
    if ((x == 0 && a - n <= 0) || (y == 0 && b - n <= 0)) sol = 0;
    if ((a - n <= x ? x : a - n) < (b - n <= y ? y : b - n)) {
      if (a - n < x) {
        n -= a - x;
        a = x;
      } else {
        a -= n;
        n = 0;
      }
      if (x > 0) {
        if (b - n < y) {
          n -= b - y;
          b = y;
        } else {
          b -= n;
          n = 0;
        }
      }
    } else {
      if (b - n < y) {
        n -= b - y;
        b = y;
      } else {
        b -= n;
        n = 0;
      }
      if (x > 0) {
        if (a - n < x) {
          n -= a - x;
          a = x;
        } else {
          a -= n;
          n = 0;
        }
      }
    }
    sol = a * b;
    cout << sol << '\n';
  }
  return 0;
}
