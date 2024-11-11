#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int p = (a - x - 1) * b;
    int q = a * y;
    int r = x * b;
    int s = a * (b - y - 1);
    int max1 = max(p, q);
    int max2 = max(r, s);
    int m = max(max1, max2);
    cout << m << "\n";
  }
  return 0;
}
