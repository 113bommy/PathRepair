#include <bits/stdc++.h>
using namespace std;
int isop(int a, int b, int c, int d, int x, int y) {
  if (a == x + c && ((b == y && b >= d) || (b == d && b >= y)))
    return 1;
  else
    return -1;
}
int main() {
  int a, b, x, y, d, c;
  cin >> a >> b >> x >> y >> d >> c;
  int w = 0;
  if (isop(a, b, c, d, x, y) == 1) {
    cout << "YES";
    return 0;
  }
  if (isop(a, b, c, d, y, x) == 1) {
    cout << "YES";
    return 0;
  }
  if (isop(a, b, d, c, y, x) == 1) {
    cout << "YES";
    return 0;
  }
  if (isop(a, b, d, c, x, y) == 1) {
    cout << "YES";
    return 0;
  }
  if (isop(b, a, c, d, x, y) == 1) {
    cout << "YES";
    return 0;
  }
  if (isop(b, a, c, d, y, x) == 1) {
    cout << "YES";
    return 0;
  }
  if (isop(b, a, d, c, y, x) == 1) {
    cout << "YES";
    return 0;
  }
  if (isop(b, a, d, c, x, y) == 1) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
