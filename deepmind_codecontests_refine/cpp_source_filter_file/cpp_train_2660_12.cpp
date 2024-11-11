#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b > c && a + c > b && c + b > a) {
    cout << "TRIANGLE";
    return 0;
  }
  if (a + b > d && a + d > b && d + b > a) {
    cout << "TRIANGLE";
    return 0;
  }
  if (a + d > c && a + d > b && c + d > a) {
    cout << "TRIANGLE";
    return 0;
  }
  if (d + b > c && d + c > b && c + b > d) {
    cout << "TRIANGLE";
    return 0;
  }
  if (a + b >= c && a + c >= b && c + b >= a) {
    cout << "SEGMENT";
    return 0;
  }
  if (a + b >= d && a + d >= b && d + b >= a) {
    cout << "SEGMENT";
    return 0;
  }
  if (a + d >= c && a + d >= b && c + d >= a) {
    cout << "SEGMENT";
    return 0;
  }
  if (d + b >= c && d + c >= b && c + b >= d) {
    cout << "SEGMENT";
    return 0;
  }
  cout << "IMPOSSIBLE";
  return 0;
}
