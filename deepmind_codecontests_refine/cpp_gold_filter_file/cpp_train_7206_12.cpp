#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    x = max(x, a - (x + 1));
    y = max(y, b - (y + 1));
    cout << max(x * b, y * a) << "\n";
  }
  return 0;
}
