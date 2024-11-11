#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, x, y, n, ans, ans2, p, q, r, s, mi, mi2, r2, p2, q2;
    int c = 0;
    cin >> a >> b >> x >> y >> n;
    long long t1 = a - x;
    long long t2 = b - y;
    if (n >= t1) {
      p = x;
      r2 = n - t1;
    } else {
      p = a - n;
      r2 = 0;
    }
    if (r2 >= t2) {
      q = y;
    } else {
      q = b - r2;
    }
    ans = p * q;
    if (n >= t2) {
      p2 = y;
      r = n - t2;
    } else {
      p2 = b - n;
      r = 0;
    }
    if (r >= t1) {
      q2 = x;
    } else {
      q2 = b - r;
    }
    ans2 = p2 * q2;
    cout << min(ans, ans2);
    cout << "\n";
  }
  return 0;
}
