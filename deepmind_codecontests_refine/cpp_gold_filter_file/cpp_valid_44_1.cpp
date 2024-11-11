#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    if (c == d)
      if (d == 0)
        cout << "0" << endl;
      else
        cout << "1" << endl;
    else if (abs(c - d) % 2 == 1)
      cout << "-1" << endl;
    else
      cout << "2" << endl;
  }
  return 0;
}
