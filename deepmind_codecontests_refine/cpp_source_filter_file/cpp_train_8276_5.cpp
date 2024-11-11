#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d;
  char c;
  cin >> a >> c >> b;
  cin >> d;
  for (int i = 1; i <= d; i++) {
    b += 1;
    if (b == 60) {
      a++;
      b = 0;
    }
    if (a == 24) {
      a = 0;
    }
  }
  if (a >= 0 && a < 10 && b > 0 && b < 10) {
    cout << '0' << a << c << '0' << b << endl;
  } else if (a == 0 && b == 0) {
    cout << "00" << c << "00" << endl;
  } else if (b > 0 && b < 10) {
    cout << a << c << '0' << b << endl;
  } else if (a > 0 && a < 10) {
    cout << '0' << a << c << b << endl;
  } else {
    cout << a << c << b << endl;
  }
}
