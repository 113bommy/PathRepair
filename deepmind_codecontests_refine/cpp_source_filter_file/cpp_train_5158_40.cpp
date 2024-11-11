#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z = 0;
  cin >> x >> y;
  for (int i = 1; i <= x; i++) {
    if (i > 5) {
      if (y >= (5 - (i % 5))) {
        z++;
        z += ((y - (5 - (i % 5))) / 5);
      }
    } else if (i < 5) {
      if (y >= (5 - (i % 5))) {
        z++;
        z += ((y - (5 - (i % 5))) / 5);
      }
    } else {
      if (y > 5) {
        z++;
        z += ((y - 5) / 5);
      }
    }
  }
  cout << z;
  return 0;
}
