#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == x || b == y) {
      cout << abs(x - a) + abs(b - y) << '\n';
      goto v;
    } else
      cout << abs(a - x) + abs(b - y) + 2 << '\n';
  v:;
  }
}
