#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int a, b, x, y, n, min1, a1, b1, n1, min2;
    cin >> a >> b >> x >> y >> n;
    a1 = a;
    b1 = b;
    n1 = n;
    if (a - n >= x) {
      a = a - n;
      b = b;
      min1 = (a * b);
    } else {
      n = n - (a - x);
      a = x;
      if (b - n >= y) {
        b = b - n;
        min1 = (a * b);
      } else {
        b = y;
        min1 = a * b;
      }
    }
    if (b1 - n1 >= y) {
      b1 = b1 - n1;
      a1 = a1;
      min2 = (a1 * b1);
    } else {
      n = n - (b1 - y);
      b1 = y;
      if (a1 - n >= x) {
        a1 = a1 - n;
        min2 = (b1 * a1);
      } else {
        a1 = x;
        min2 = a1 * b1;
      }
    }
    cout << min(min1, min2) << endl;
  }
}
