#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, y, a, b, c;
  cin >> t;
  for (int d = 1; d <= t; d++) {
    cin >> n >> y >> a >> b;
    c = a + b;
    if ((y - n) % c == 0) {
      cout << (y - n) / c << "\n";
    } else
      cout << -1 << "\n";
  }
}
