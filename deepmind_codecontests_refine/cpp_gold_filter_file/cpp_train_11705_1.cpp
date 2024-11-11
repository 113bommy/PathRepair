#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int main(void) {
  int a, b;
  cin >> a >> b;
  for (int x = -a; x <= a; x++) {
    for (int y = -a; y <= a; y++)
      if (x * x + y * y == a * a) {
        for (int i = 1; i <= max(a * a, b * b); i++) {
          if (i * x * i * x == (b * b - i * i) * y * y && x != 0 && y != 0 &&
              x + i != x && x + i != 0 && y - (b * b - i * i) != 0 &&
              y - (b * b - i * i) != y * y) {
            cout << "YES\n";
            cout << "0 0 " << x << ' ' << y << ' ' << x + i << ' '
                 << y - ceil(sqrt(double(b * b - i * i)));
            return 0;
          }
        }
      }
  }
  cout << "NO";
}
