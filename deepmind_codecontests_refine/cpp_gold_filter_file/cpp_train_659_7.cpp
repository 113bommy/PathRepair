#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, k = 0;
  cin >> x >> y >> z;
  if (x == z) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i * y <= z; i++) {
    if (i * y > x) {
      cout << (i * y) - x << " ";
      k++;
    }
  }
  if (k == 0) cout << -1;
  return 0;
}
