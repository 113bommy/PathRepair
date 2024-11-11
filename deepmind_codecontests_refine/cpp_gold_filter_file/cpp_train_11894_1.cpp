#include <bits/stdc++.h>
using namespace std;
int x, m, k, y, z;
int main() {
  scanf("%d", &x);
  for (int a = 1; a <= x; a++) {
    scanf("%d", &y);
    if (y == 1 || y == 2 || y == 3)
      cout << "-1\n";
    else if (y == 4)
      cout << "2 4 1 3\n";
    else if (y % 2 == 0) {
      for (int b = 1; b <= y; b += 2) {
        cout << b << " ";
      }
      cout << y - 4 << " ";
      for (int b = y; b >= 2; b -= 2) {
        if (b != y - 4) cout << b << " ";
      }
      cout << "\n";
    } else {
      for (int b = 1; b <= y; b += 2) {
        cout << b << " ";
      }
      cout << y - 3 << " ";
      for (int b = y - 1; b >= 2; b -= 2) {
        if (b != y - 3) cout << b << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
