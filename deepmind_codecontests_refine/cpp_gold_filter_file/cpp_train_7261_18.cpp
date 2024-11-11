#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N], b[N];
int mi(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }
int ma(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }
int main() {
  bool sw = false;
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  a[1] = mi(x1, x2, x3, x4);
  a[2] = mi(y1, y2, y3, y4);
  a[3] = ma(x1, x2, x3, x4);
  a[4] = ma(y1, y2, y3, y4);
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  b[1] = mi(x1, x2, x3, x4);
  b[2] = mi(y1, y2, y3, y4);
  b[3] = ma(x1, x2, x3, x4);
  b[4] = ma(y1, y2, y3, y4);
  for (int i = a[1]; i <= a[3]; i++) {
    for (int j = a[2]; j <= a[4]; j++) {
      if (i == b[1] && j == (b[2] + b[4]) / 2) {
        cout << "YES\n";
        return 0;
      }
      if (i == b[3] && j == (b[2] + b[4]) / 2) {
        cout << "YES\n";
        return 0;
      }
      if (i == (b[1] + b[3]) / 2 && j == b[2]) {
        cout << "YES\n";
        return 0;
      }
      if (i == (b[1] + b[3]) / 2 && j == b[4]) {
        cout << "YES\n";
        return 0;
      }
      if (i == (b[1] + b[3]) / 2 && j == (b[2] + b[4]) / 2) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  x1 = a[1], y1 = a[2], x2 = a[3], y2 = a[2];
  x3 = a[1], y3 = a[4], x4 = a[3], y4 = a[4];
  a[1] = mi(x1 + y1, x2 + y2, x3 + y3, x4 + y4);
  a[2] = mi(x1 - y1, x2 - y2, x3 - y3, x4 - y4);
  a[3] = ma(x1 + y1, x2 + y2, x3 + y3, x4 + y4);
  a[4] = ma(x1 - y1, x2 - y2, x3 - y3, x4 - y4);
  x1 = b[1], y1 = ((b[2] + b[4]) / 2), x2 = b[3], y2 = ((b[2] + b[4]) / 2);
  x3 = ((b[1] + b[3]) / 2), y3 = b[2], x4 = ((b[1] + b[3]) / 2), y4 = b[4];
  b[1] = mi(x1 + y1, x2 + y2, x3 + y3, x4 + y4);
  b[2] = mi(x1 - y1, x2 - y2, x3 - y3, x4 - y4);
  b[3] = ma(x1 + y1, x2 + y2, x3 + y3, x4 + y4);
  b[4] = ma(x1 - y1, x2 - y2, x3 - y3, x4 - y4);
  for (int i = b[1]; i <= b[3]; i++) {
    for (int j = b[2]; j <= b[4]; j++) {
      if (i == a[1] && j == (a[2] + a[4]) / 2) {
        cout << "YES\n";
        return 0;
      }
      if (i == a[3] && j == (a[2] + a[4]) / 2) {
        cout << "YES\n";
        return 0;
      }
      if (i == (a[1] + a[3]) / 2 && j == a[2]) {
        cout << "YES\n";
        return 0;
      }
      if (i == (a[1] + a[3]) / 2 && j == a[4]) {
        cout << "YES\n";
        return 0;
      }
      if (i == (a[1] + a[3]) / 2 && j == (a[2] + a[4]) / 2) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
