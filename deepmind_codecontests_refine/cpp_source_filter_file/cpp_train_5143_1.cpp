#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  if (b - a == c - b && c - b == d - c) {
    cout << d + (b - a);
    return 0;
  }
  if (b / a == c / b && c / b == d / c) {
    if (b >= a) {
      cout << d * (d / c);
      return 0;
    }
    if (d * (d / c) == int(d * (d / c)) / 1) {
      cout << d * (d / c);
      return 0;
    }
  }
  cout << "42";
}
