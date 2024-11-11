#include <bits/stdc++.h>
using namespace std;
int main() {
  short t;
  int a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    if (b < c)
      cout << c << " " << c << " " << b << endl;
    else if (c < b)
      cout << b << " " << b << " " << c << endl;
    else
      cout << b << " " << b << " " << b << endl;
  }
  return 0;
}
