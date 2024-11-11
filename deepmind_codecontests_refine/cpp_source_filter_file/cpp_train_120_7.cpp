#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    int sum = 0;
    cin >> a >> b >> c;
    if (c > 1) {
      int d = c / 2;
      int y = b - d;
      if (y <= 0) {
        sum += 3 * b;
        b = 0;
      } else if (y > 0) {
        sum += 3 * d;
        b -= d;
      }
    }
    if (b > 1) {
      int e = b / 2;
      int t = a - e;
      if (t <= 0) {
        sum += 3 * t;
        a -= t;
      } else if (t > 0) {
        sum += 3 * e;
        a -= e;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
