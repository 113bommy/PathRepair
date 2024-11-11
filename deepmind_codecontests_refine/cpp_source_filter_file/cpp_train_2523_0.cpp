#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    unsigned long long int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a < b / 2) {
      cout << (x + y) * a << endl;
    } else if (x == y) {
      cout << x * b << endl;
    } else if (x < y) {
      cout << x * b + (y - x) * a << endl;
    } else {
      cout << y * b + (x - y) * a << endl;
    }
  }
}
