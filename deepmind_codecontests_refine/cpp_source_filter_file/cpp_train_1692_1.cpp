#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, x, m = 0;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
    } else if (b > a && b % a != 0) {
      cout << -1 << endl;
    } else if (a > b && a % b != 0) {
      cout << -1 << endl;
    } else {
      if (a > b) {
        x = a;
        while (x != b) {
          if (x % 8 == 0) {
            x = x / 8;
          } else if (x % 4 == 0) {
            x = x / 4;
          } else if (x % 2 == 0) {
            x = x / 2;
          } else {
            m = -1;
            break;
          }
          m++;
        }
        cout << m << endl;
      } else {
        x = b / a;
        while (x != 1) {
          if (x % 8 == 0) {
            x = x / 8;
          } else if (x % 4 == 0) {
            x = x / 4;
          } else if (x % 2 == 0) {
            x = x / 2;
          } else {
            m = -1;
            break;
          }
          m++;
        }
        cout << m << endl;
      }
    }
  }
  return 0;
}
