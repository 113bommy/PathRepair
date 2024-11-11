#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    int lc = c - r;
    int rc = c + r;
    lc = max(lc, min(rc, a));
    rc = max(lc, min(rc, b));
    int dist = 0;
    if (lc >= a && rc <= b) dist = rc - lc;
    cout << (b - a) - dist;
  }
  return 0;
}
