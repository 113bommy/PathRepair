#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  int x, y, z;
  cin >> x >> y >> z;
  if (z == 0) {
    if (x == y) {
      cout << 0;
      return 0;
    }
  }
  if (x + z >= y && y + z >= x) {
    cout << "?";
    return 0;
  }
  int max1 = x + z, max2 = x + y;
  if (max1 > max2) {
    cout << '+';
  } else
    cout << '-';
  return 0;
}
