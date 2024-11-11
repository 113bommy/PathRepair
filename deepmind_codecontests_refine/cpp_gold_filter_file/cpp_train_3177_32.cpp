#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  while (cin >> a >> b >> c >> d >> e >> f) {
    a -= d;
    b -= e;
    c -= f;
    a = a > 0 ? a / 2 : a;
    b = b > 0 ? b / 2 : b;
    c = c > 0 ? c / 2 : c;
    if (a + b + c >= 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
