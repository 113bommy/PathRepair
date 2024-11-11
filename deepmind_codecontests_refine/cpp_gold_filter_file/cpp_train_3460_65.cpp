#include <bits/stdc++.h>
using namespace std;
int main() {
  short t;
  int a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    if (b < c)
      cout << b << " " << c << " " << c << endl;
    else if (c < b)
      cout << c << " " << b << " " << b << endl;
    else
      cout << b << " " << b << " " << b << endl;
  }
  return 0;
}
