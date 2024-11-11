#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long o = 1;
  while (o--) {
    long long n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2)
      cout << 0 << "\n";
    else if ((x1 == 0 && x2 == n) || (x1 == n && x2 == 0)) {
      cout << min(y1 + y2 + n, 3 * n - y1 - y2) << "\n";
    } else if ((y1 == 0 && y2 == n) || (y2 == 0 && y1 == n)) {
      cout << min(x1 + x2 + n, 3 * n - x1 - x2) << "\n";
    } else if ((x1 == 0 && y2 == n)) {
      cout << n - y1 + x2 << "\n";
    } else if (x1 == 0 && y2 == 0) {
      cout << y1 + x2 << "\n";
    } else if (x1 == n && y2 == n) {
      cout << n - y1 + n - x2 << "\n";
    } else if (x1 == n && y2 == 0) {
      cout << y1 + n - x2 << "\n";
    } else if (y1 == n && x2 == 0) {
      cout << x1 + n - y2 << "\n";
    } else if (y1 == 0 && x2 == 0) {
      cout << x1 + y1 << "\n";
    } else if (y1 == 0 && x2 == n) {
      cout << n - x1 + y2 << "\n";
    } else if (y1 == n && x2 == n) {
      cout << n - x1 + n - y2 << "\n";
    } else if (x1 == x2) {
      cout << abs(y1 - y2) << "\n";
    } else if (y1 == y2)
      cout << abs(x1 - x2) << "\n";
  }
  return 0;
}
