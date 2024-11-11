#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int max1 = max((3 * a / 10), (a - (a / 250) * c));
  int max2 = max((3 * b / 10), (b - (b / 250) * d));
  if (max1 > max2) {
    cout << "Misha";
  } else if (max1 < max2) {
    cout << "Vasya";
  } else {
    cout << "tie";
  }
  return 0;
}
