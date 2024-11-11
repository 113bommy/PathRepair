#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  int t;
  cin >> t;
  int mixx, theres;
  for (int i = 0; i < t; i++) {
    cin >> x >> y >> z;
    mixx = x;
    theres = 0;
    if (x == y && y == z) {
      cout << "YES" << endl;
      cout << x << " " << x << " " << x << endl;
      continue;
    }
    if (y > x) {
      if (y != z) {
        cout << "NO" << endl;
        continue;
      } else {
        cout << "YES" << endl;
        cout << x << " " << x << " " << y;
        continue;
      }
    }
    if (y == x) {
      if (z > x) {
        cout << "NO" << endl;
        continue;
      } else {
        cout << "YES" << endl;
        cout << x << " " << z << " " << z << endl;
        continue;
      }
    }
    if (y < x) {
      if (x != z) {
        cout << "NO" << endl;
        continue;
      } else {
        cout << "YES" << endl;
        cout << y << " " << x << " " << y << endl;
        continue;
      }
    }
  }
}
