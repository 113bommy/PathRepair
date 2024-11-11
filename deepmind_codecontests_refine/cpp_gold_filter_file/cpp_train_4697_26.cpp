#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, a1, b1, c1;
  cin >> a >> b >> c;
  a1 = (a + c - b);
  b1 = (a + b - c);
  c1 = (b + c - a);
  if (a1 > 0 && b1 > 0 && c1 > 0) {
    cout << 0;
    return 0;
  } else if (a1 < b1 && a1 < c1) {
    cout << abs(a1) + 1;
    return 0;
  }
  if (c1 < b1 && c1 < a1) {
    cout << abs(c1) + 1;
    return 0;
  }
  if (b1 < a1 && b1 < c1) {
    cout << abs(b1) + 1;
    return 0;
  }
}
