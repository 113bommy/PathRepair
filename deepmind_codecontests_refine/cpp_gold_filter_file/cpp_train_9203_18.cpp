#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  int x, y, z;
  while (cin >> n) {
    x = -1;
    for (int i = 1; i <= 4; i++) {
      cin >> a >> b >> c >> d;
      if (a + c <= n) x = i, y = a, z = n - a;
      if (a + d <= n) x = i, y = a, z = n - a;
      if (b + c <= n) x = i, y = b, z = n - b;
      if (b + d <= n) x = i, y = b, z = n - b;
    }
    if (x != -1)
      cout << x << ' ' << y << ' ' << z << endl;
    else
      cout << x << endl;
  }
  return 0;
}
