#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  if (x == y && z == 0)
    cout << "0";
  else if (x > y + z)
    cout << "+";
  else if (x + z < y)
    cout << "-";
  else
    cout << "?";
}
