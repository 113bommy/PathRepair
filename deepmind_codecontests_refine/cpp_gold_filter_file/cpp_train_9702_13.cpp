#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  int x3 = (x1 - y1) < 0 ? (x1 - y1) / (2 * b) - 1 : (x1 - y1) / (2 * b);
  int y3 = (x1 + y1) < 0 ? (x1 + y1) / (2 * a) - 1 : (x1 + y1) / (2 * a);
  int x4 = (x2 - y2) < 0 ? (x2 - y2) / (2 * b) - 1 : (x2 - y2) / (2 * b);
  int y4 = (x2 + y2) < 0 ? (x2 + y2) / (2 * a) - 1 : (x2 + y2) / (2 * a);
  cout << max(abs(x3 - x4), abs(y3 - y4)) << endl;
  return 0;
}
