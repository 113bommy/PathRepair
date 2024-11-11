#include <bits/stdc++.h>
using namespace std;
int dirx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int diry[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int main() {
  int a, b, k, x1, y1, x2, y2;
  cin >> b >> a;
  for (x1 = 1; x1 <= 1000; x1++) {
    y1 = a * a - x1 * x1;
    k = sqrt(y1);
    if (k * k != y1) continue;
    y1 = k;
    for (x2 = x1 + 1; x2 <= 5000; x2++) {
      y2 = a * a + b * b - x2 * x2;
      k = sqrt(y2);
      if (k * k != y2) continue;
      y2 = k;
      if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == b * b && y2 != 0 &&
          y1 != 0 && y1 != y2) {
        cout << "YES\n";
        cout << "0 0\n";
        cout << x1 << " " << y1 << endl;
        cout << x2 << " " << y2 << endl;
        return 0;
      }
    }
  }
  swap(a, b);
  for (x1 = 1; x1 <= 1000; x1++) {
    y1 = a * a - x1 * x1;
    k = sqrt(y1);
    if (k * k != y1) continue;
    y1 = k;
    for (x2 = x1 + 1; x2 <= 5000; x2++) {
      y2 = a * a + b * b - x2 * x2;
      k = sqrt(y2);
      if (k * k != y2) continue;
      y2 = k;
      if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == b * b && y2 != 0 &&
          y1 != 0 && y1 != y2) {
        cout << "YES\n";
        cout << "0 0\n";
        cout << x1 << " " << y1 << endl;
        cout << x2 << " " << y2 << endl;
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
