#include <bits/stdc++.h>
using namespace std;
int main() {
  long int x, y, z, l, b;
  cin >> x >> y >> z;
  if (x % z == 0)
    l = x / z;
  else
    l = x / z + 1;
  if (y % z == 0)
    b = y / z;
  else
    b = y / z + 1;
  cout << l * b;
  return 0;
}
