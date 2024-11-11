#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    if (a == b)
      cout << "0"
           << "\n";
    else if (a > b) {
      if ((a - b) % 2 == 0)
        cout << "1"
             << "\n";
      if ((a - b) % 2 != 0)
        cout << "2"
             << "\n";
    } else {
      if ((b - a) % 2 == 0)
        cout << "2"
             << "\n";
      else
        cout << "1"
             << "\n";
    }
  }
  return 0;
}
