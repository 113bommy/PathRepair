#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793238462643;
bool f(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  long long dx1, dy1, dx2, dy2, p;
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  if (x3 > x4) {
    swap(x3, x4);
    swap(y3, y4);
  }
  dx1 = x2 - x1;
  dy1 = y2 - y1;
  dx2 = x4 - x3;
  dy2 = y4 - y3;
  p = dx1 * dy2 - dx2 * dy1;
  if (p == 0) {
    long long s;
    s = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
    if (s != 0) return 0;
    if (x2 < x3 || x4 < x1) return 0;
  } else {
    long long s1, s2, s3, s4;
    s1 = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
    s2 = (x1 - x4) * (y2 - y4) - (x2 - x4) * (y1 - y4);
    s3 = (x3 - x1) * (y4 - y1) - (x4 - x1) * (y3 - y1);
    s4 = (x3 - x2) * (y4 - y2) - (x4 - x2) * (y3 - y2);
    if ((s1 == 0 || s2 == 0) && (s3 == 0 || s4 == 0)) return 1;
    if (((s1 >= 0 && s2 <= 0) || (s1 <= 0 && s2 >= 0)) &&
        ((s3 >= 0 && s4 <= 0) || (s3 <= 0 && s4 >= 0)))
      return 1;
    else
      return 0;
  }
  if (y1 < y2) swap(y1, y2);
  if (y3 < y4) swap(y3, y4);
  if (y3 < y2 || y1 < y4) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  int x1, x2, x3, x4, x5, x6, x7, x8, y1, y2, y3, y4, y5, y6, y7, y8;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 >>
      x7 >> y7 >> x8 >> y8;
  if (f(x1, y1, x2, y2, x5, y5, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x1, y1, x2, y2, x5, y5, x8, y8) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x1, y1, x2, y2, x8, y8, x7, y7) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x1, y1, x2, y2, x7, y7, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x1, y1, x4, y4, x5, y5, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x1, y1, x4, y4, x5, y5, x8, y8) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x1, y1, x4, y4, x8, y8, x7, y7) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x1, y1, x4, y4, x7, y7, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x4, y4, x5, y5, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x4, y4, x5, y5, x8, y8) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x4, y4, x8, y8, x7, y7) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x4, y4, x7, y7, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x2, y2, x5, y5, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x2, y2, x5, y5, x8, y8) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x2, y2, x8, y8, x7, y7) == 1) {
    cout << "YES";
    return 0;
  }
  if (f(x3, y3, x2, y2, x7, y7, x6, y6) == 1) {
    cout << "YES";
    return 0;
  }
  int xmi = min(x1, min(x2, min(x3, x4))), xma = max(x1, max(x2, max(x3, x4)));
  int ymi = min(y1, min(y2, min(y3, y4))), yma = max(y1, max(y2, max(y3, y4)));
  if (x5 <= xma && x6 <= xma && x7 <= xma && x8 <= xma && x5 >= xmi &&
      x6 >= xmi && x7 >= xmi && x8 >= xmi) {
    if (y5 <= yma && y6 <= yma && y7 <= yma && y8 <= yma && y5 >= ymi &&
        y6 >= ymi && y7 >= ymi && y8 >= ymi) {
      cout << "YES";
      return 0;
    }
  }
  long long s1 = abs(x5 * y6 + x6 * y7 + x7 * y8 + x8 * y5 - x8 * y7 - x7 * y6 -
                     x6 * y5 - x5 * y8);
  long long s2 = abs(x1 * y5 + x5 * y8 + x8 * y1 - x8 * y5 - x5 * y1 - x1 * y8);
  s2 += abs(x1 * y5 + x5 * y6 + x6 * y1 - x6 * y5 - x5 * y1 - x1 * y6);
  s2 += abs(x1 * y6 + x6 * y7 + x7 * y1 - x7 * y6 - x6 * y1 - x1 * y7);
  s2 += abs(x1 * y7 + x7 * y8 + x8 * y1 - x8 * y7 - x7 * y1 - x1 * y8);
  if (s1 == s2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
