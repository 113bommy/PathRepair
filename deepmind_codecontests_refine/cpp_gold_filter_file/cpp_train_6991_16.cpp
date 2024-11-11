#include <bits/stdc++.h>
using namespace std;
int x, y, z, s;
int main() {
  cin >> x >> y >> z;
  s = x - y;
  if (s < 0) {
    if (s + z >= 0)
      return cout << '?', 0;
    else
      return cout << "-", 0;
  }
  if (s > 0) {
    if (s - z <= 0)
      return cout << '?', 0;
    else
      return cout << "+", 0;
  }
  if (s == 0) {
    if (z > 0)
      return cout << '?', 0;
    else
      return cout << "0", 0;
  }
}
