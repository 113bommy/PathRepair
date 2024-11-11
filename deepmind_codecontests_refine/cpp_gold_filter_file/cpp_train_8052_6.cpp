#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, z;
  cin >> n >> z;
  while (n--) {
    cin >> x >> y;
    if (x == z || x == 7 - z || y == z || y == 7 - z) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
