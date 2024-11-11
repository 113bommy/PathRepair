#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    if (a <= b) {
      if (a == b)
        cout << "0\n";
      else if (a % 2 == 0 && b % 2 == 0)
        cout << "2\n";
      else if ((a % 2 == 0 && b % 2 != 0) || b - a == 1 ||
               (a % 2 != 0 && b % 2 == 0))
        cout << "1\n";
      else
        cout << "2\n";
    } else {
      if (a - b == 1)
        cout << "0\n";
      else if (a % 2 != 0 && b % 2 == 0 || (a % 2 == 0 && b % 2 != 0))
        cout << "2\n";
      else if (a % 2 != 0 && b % 2 != 0)
        cout << "1\n";
      else
        cout << "1\n";
    }
  }
  return 0;
}
