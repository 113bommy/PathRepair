#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b > c && a + c > b && b + c > a) {
    cout << "TRIANGLE" << endl;
  } else if (d + b > c && d + c > b && b + c > d) {
    cout << "TRIANGLE" << endl;
  } else if (a + b > d && a + d > b && b + d > a) {
    cout << "TRIANGLE" << endl;
  } else if (a + d > c && a + c > d && d + c > a) {
    cout << "TRIANGLE" << endl;
  } else if (a + b == c || a + c == b || b + c == a) {
    cout << "SEGMENT" << endl;
  } else if (d + b == c || d + c == b || b + c == d) {
    cout << "SEGMENT" << endl;
  } else if (a + b == d || a + d == b || b + d == a) {
    cout << "SEGMENT" << endl;
  } else if (a + d == c || a + c == d || d + c == a) {
    cout << "SEGment" << endl;
  } else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
