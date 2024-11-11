#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  while (cin >> x >> y >> z >> t1 >> t2 >> t3) {
    int diff = abs(x - y);
    int stair = diff * t1;
    int elevator = (abs(x - z) + diff) * t2 + (3 * t3);
    if (elevator > stair)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
