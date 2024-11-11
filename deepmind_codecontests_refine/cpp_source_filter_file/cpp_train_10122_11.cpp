#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a > b) {
      if (a % 2 == 1 && b % 2 == 1)
        cout << 1 << endl;
      else if (a % 2 == 0 && b % 2 == 0)
        cout << 1 << endl;
      else if (a % 2 == 1 && b % 2 == 0)
        cout << 2 << endl;
      else if (a % 2 == 0 && b % 2 == 1)
        cout << 1 << endl;
    } else if (b > a) {
      if (a % 2 == 1 && b % 2 == 1)
        cout << 2 << endl;
      else if (a % 2 == 0 && b % 2 == 0)
        cout << 2 << endl;
      else if (a % 2 == 1 && b % 2 == 0)
        cout << 1 << endl;
      else if (a % 2 == 0 && b % 2 == 1)
        cout << 1 << endl;
    } else if (a == b)
      cout << 0 << endl;
  }
  return 0;
}
