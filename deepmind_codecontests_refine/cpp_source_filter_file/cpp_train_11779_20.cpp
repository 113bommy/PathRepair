#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, a, b, c;
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  a = a - x;
  if (a < 0) {
    cout << "NO";
  } else {
    b = b + a - y;
    if (b < 0)
      cout << "NO";
    else {
      c = c + b + a - z;
      if (c < 0)
        cout << "NO";
      else {
        cout << "YES";
      }
    }
  }
  return 0;
}
