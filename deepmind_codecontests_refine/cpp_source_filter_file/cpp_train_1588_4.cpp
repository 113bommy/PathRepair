#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    float x, y;
    cin >> x;
    y = 360.0 / (4 * x);
    y = y * ((3.141592653589793238) / 180);
    x = (0.5 / tan(y));
    x = 2 * x;
    printf("%0.6f", x);
  }
}
