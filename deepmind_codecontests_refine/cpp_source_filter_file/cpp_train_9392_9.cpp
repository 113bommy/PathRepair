#include <bits/stdc++.h>
using namespace std;
bool fun(long long int a, long long int b) { return a > b; }
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, r, x, y;
    cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    if (c < a) {
      x = r - (a - c);
      if (x < 0) x = 0;
      if (b - a - x > 0)
        cout << b - a - x << "\n";
      else
        cout << "0\n";
    } else if (c > b) {
      x = r - (c - b);
      if (x < 0) x = 0;
      if (b - a - x > 0)
        cout << b - a - x << "\n";
      else
        cout << "0\n";
    } else if (c != a && c != b) {
      if (c - a > r)
        x = r;
      else
        x = c - a;
      if (b - c > r)
        y = r;
      else
        y - b - c;
      if (b - a - (x + y) > 0)
        cout << b - a - (x + y) << "\n";
      else
        cout << "0\n";
    } else {
      if (b - a - r > 0)
        cout << b - a - r << "\n";
      else
        cout << "0\n";
    }
  }
  return 0;
}
