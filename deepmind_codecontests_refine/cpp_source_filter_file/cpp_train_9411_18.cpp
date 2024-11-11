#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x, y, z;
  for (int i = 0; i <= 10000; i++) {
    x = i;
    y = b - x;
    z = a - x;
    if (y + z == c && y >= 0 && z >= 0 && x >= 0) {
      cout << x << " " << y << " " << z << endl;
      return 0;
    }
  }
  cout << "Impossible" << endl;
}
