#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int cnt = 1;
  int tot = t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    long long u;
    if (x > y) {
      u = x + y;
    } else if (y % x != 0) {
      u = (y + (x + (y / x - 1) * x)) / 2;
    } else
      u = x;
    cout << u << endl;
  }
}
