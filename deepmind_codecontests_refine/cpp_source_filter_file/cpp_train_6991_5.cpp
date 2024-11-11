#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, z;
  cin >> x >> y >> z;
  if (x > y + z)
    cout << '+' << endl;
  else if (y > x + z)
    cout << '-' << endl;
  else if (z != 0 && (x == y + z || y == x + z))
    cout << '?' << endl;
  else if (x == y) {
    if (z == 0)
      cout << '0' << endl;
    else
      cout << '?' << endl;
  }
  return 0;
}
