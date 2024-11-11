#include <bits/stdc++.h>
using namespace std;
struct cube {
  double x1, y1, x2, y2;
};
int main() {
  int n;
  cin >> n;
  cube cubes[100];
  for (int i = 0; i < n; i++) {
    cin >> cubes[i].x1 >> cubes[i].y1 >> cubes[i].x2 >> cubes[i].y2;
    if (cubes[i].x1 > cubes[i].x2) swap(cubes[i].x1, cubes[i].x2);
    if (cubes[i].y1 > cubes[i].y2) swap(cubes[i].y1, cubes[i].y2);
  }
  int ans = 1;
  double m, x, y, mi;
  for (int i = 1; i < n; i++) {
    m = x = y = mi = 0;
    for (int j = n - 1; j > 0; j--) {
      mi = pow((cubes[j].x2 - cubes[j].x1), 3.);
      m += mi;
      x += mi * ((cubes[j].x2 + cubes[j].x1) / 2.);
      y += mi * ((cubes[j].y2 + cubes[j].y1) / 2.);
      if (!(cubes[j - 1].y2 >= y / m && cubes[j - 1].y1 <= y / m &&
            cubes[j - 1].x2 >= x / m && cubes[j - 1].x1 <= x / m)) {
        cout << ans;
        return 0;
      }
    }
    ans++;
  }
  cout << ans;
  return 0;
}
