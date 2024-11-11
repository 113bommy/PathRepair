#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, y, a, b, c;
  cin >> t;
  for (int a = 1; a <= t; a++) {
    cin >> n >> y >> a >> b;
    c = a + b;
    if ((y - n) % c == 0) {
      cout << (y - n) / c << "\n";
    } else
      cout << -1 << "\n";
  }
}
