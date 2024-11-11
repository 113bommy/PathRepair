#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    cout << "YES";
    return 0;
  } else {
    if ((a < b && a + c * 1000000000 < b) ||
        (a > b && a + c * 1000000000 > b)) {
      cout << "NO";
      return 0;
    } else {
      if (c == 0) {
        cout << "NO";
        return 0;
      } else if (c < 0) {
        if (b >= 0 && a <= 0) {
          cout << "NO";
          return 0;
        } else {
          if ((b - a) % c == 0) {
            cout << "YES";
            return 0;
          } else {
            cout << "NO";
            return 0;
          }
        }
      } else {
        if (a >= 0 && b <= 0) {
          cout << "NO";
          return 0;
        } else {
          if ((b - a) % c == 0) {
            cout << "YES";
            return 0;
          } else {
            cout << "NO";
            return 0;
          }
        }
      }
    }
  }
}
