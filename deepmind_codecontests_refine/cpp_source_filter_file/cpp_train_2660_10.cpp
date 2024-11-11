#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b > c && b + c > a && a + c > b ||
      a + b > d && b + d > a && a + d > b ||
      b + c > a && a + c > b && a + b > c ||
      b + c > d && b + d > c && d + c > b ||
      a + c > b && a + b > c && b + c > a ||
      a + c > d && c + d > a && a + d > c ||
      a + d > c && c + d > a && a + c > d ||
      a + d > b && a + b > d && b + d > a) {
    cout << "TRIANGLE";
  } else if (a == b + c || a == b + d || a == c + d || b == a + c ||
             b == a + d || b == c + d || c == a + c || c == a + d ||
             c == c + d || d == b + c || d == b + a || d == c + a) {
    cout << "SEGMENT";
  } else {
    cout << "IMPOSSIBLE";
  }
  return 0;
}
