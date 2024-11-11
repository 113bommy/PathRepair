#include <bits/stdc++.h>
using namespace std;
int i, j, m, n, s, t, x, z, y;
int main() {
  cin >> n;
  while (n--) {
    cin >> x >> y >> z;
    if (y + z >= x - 1 || y - z > 1 || y - z < -1) {
      cout << -1 << endl;
      continue;
    }
    if (y > z) {
      cout << x - 1;
      for (i = 1; i <= y; i++) {
        cout << " " << x - (2 * i - 2);
        if (i != y)
          cout << " " << x - (2 * i + 1);
        else
          cout << " " << x - (2 * i);
      }
      for (i = x - (2 * y + 1); i >= 1; i--) cout << " " << i;
      cout << endl;
    }
    if (y < z) {
      cout << 2;
      for (i = 1; i <= y; i++) {
        cout << " " << 2 * i - 1;
        cout << " " << 2 * i + 2;
      }
      cout << " " << 2 * y + 2 - 1;
      for (i = 2 * y + 2 + 1; i <= x; i++) cout << " " << i;
    }
    if (y == z) {
      cout << 1;
      for (i = 1; i <= y; i++) {
        cout << " " << 2 * i + 1;
        cout << " " << 2 * i;
      }
      for (i = 2 * y + 2; i <= x; i++) cout << " " << i;
    }
    cout << endl;
  }
}
