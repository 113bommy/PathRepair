#include <bits/stdc++.h>
using namespace std;
long long x3, y3, x4, y4, x5, y5, x6, y6;
bool isin(long long a, long long b) {
  if (a >= x3 && a <= x4 && b >= y3 && b <= y4) return false;
  if (a >= x5 && a <= x6 && b >= y5 && b <= y6) return false;
  return true;
}
int main() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  cin >> x5 >> y5 >> x6 >> y6;
  if (isin(x1, y1) || isin(x1, y2) || isin(x2, y1) || isin(x2, y2)) {
    cout << "YES";
    return 0;
  } else if (x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y2) {
    cout << "NO";
    return 0;
  } else if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2) {
    cout << "NO";
    return 0;
  } else if (x3 <= x1 && x4 >= x2 && x5 <= x1 && x6 >= x2) {
    long long a = min(y4, y6);
    long long b = max(y3, y5);
    if (a >= b && a <= y2 && a >= y1) {
      cout << "NO";
      return 0;
    }
  } else if (y3 <= y1 && y4 >= y2 && y5 <= y1 && y6 >= y2) {
    long long a = min(x4, x6);
    long long b = max(x3, x5);
    if (a >= b && a <= x2 && a >= x1) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
