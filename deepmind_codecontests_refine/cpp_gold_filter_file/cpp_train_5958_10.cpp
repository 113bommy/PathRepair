#include <bits/stdc++.h>
using namespace std;
long long t, n, g, b, x, y;
int main() {
  cin >> t;
  while (t) {
    t--;
    cin >> n >> g >> b;
    if (g >= b)
      cout << n << '\n';
    else {
      x = (n + 1) / 2;
      y = (x - 1) / g * (g + b) + (x - 1) % g + 1;
      cout << max(y, n) << '\n';
    }
  }
  return 0;
}
