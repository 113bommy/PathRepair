#include <bits/stdc++.h>
using namespace std;
const int SZ = 1e5 + 10;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;
int main() {
  long long a, b, c;
  cin >> a;
  if (a == 2) {
    cout << "1" << endl;
  } else {
    c = (a * 2) / 3;
    if (a % 3) {
      c += 1;
    }
    cout << c << endl;
  }
}
