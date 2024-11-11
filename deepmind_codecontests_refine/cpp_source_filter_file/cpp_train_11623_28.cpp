#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a = 2 * a;
  b = 2 * b;
  int k = 1;
  for (int i = c; i <= 2 * c; i++) {
    if (d <= c && 2 * d >= c) {
      k = 0;
      c = i;
      break;
    }
  }
  if (k == 0) {
    if (2 * d >= b || 2 * d >= a) {
      cout << "-1";
    } else {
      cout << a << "\n" << b << "\n" << c;
    }
  } else
    cout << "-1";
}
