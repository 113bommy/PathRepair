#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, n, min = 10000, x, y;
  cin >> n;
  d = sqrt(n);
  if (n == 0) {
    cout << "0"
         << " "
         << "0" << endl;
  } else {
    for (int i = 1; i <= d; i++) {
      if (n % i == 0) {
        b = n / i;
        c = b - i;
        if (b >= i) {
          if (c <= min) {
            min = c;
            x = i;
            y = b;
          }
        } else {
          break;
        }
      }
    }
    cout << x << " " << y << endl;
  }
}
