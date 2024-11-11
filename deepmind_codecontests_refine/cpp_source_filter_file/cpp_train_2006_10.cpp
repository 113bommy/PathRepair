#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, x2;
    cin >> x1 >> x2;
    if (x1 < x2)
      cout << x2 - x1 << endl;
    else if ((x1 % 2 == 0 && x2 % 2 == 0) || (x1 % 2 == 1 && x2 == 1))
      cout << "0" << endl;
    else
      cout << "1" << endl;
  }
}
