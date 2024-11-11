#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, x, y, z;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      if ((b - a) % 2 == 1) {
        cout << 1;
      } else {
        if (((b - a) / 2) % 2 == 1) {
          cout << 2;
        } else {
          cout << 2;
        }
      }
      cout << endl;
    } else if (a > b) {
      if ((a - b) % 2 == 0) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    } else {
      cout << 0 << endl;
    }
  }
}
