#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x0, x1, x2, y0, y1, y2;
    cin >> x0 >> x1 >> x2;
    cin >> y0 >> y1 >> y2;
    int q, sum = 0;
    q = min(x1, y0);
    x1 -= q;
    y0 -= q;
    q = min(x0, y2);
    x0 -= q;
    y2 -= q;
    q = min(x2, y1);
    x2 -= q;
    y1 -= q;
    sum += q * 2;
    sum += 2 * min(x1, y2);
    cout << sum << endl;
  }
  return 0;
}
