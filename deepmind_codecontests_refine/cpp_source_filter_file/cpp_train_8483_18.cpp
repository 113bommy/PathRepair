#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, n;
  z = 0;
  cin >> x;
  cin >> y;
  if (x > y) {
    z = (x - y) / 2;
    n = y;
  }
  if (y > x) {
    z = (y - x) / 2;
    n = x;
  }
  cout << n;
  cout << z;
}
