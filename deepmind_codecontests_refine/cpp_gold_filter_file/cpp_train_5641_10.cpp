#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int b, p, f, h, c;
  for (int i = 0; i < t; i++) {
    int count = 0;
    cin >> b >> p >> f >> h >> c;
    b /= 2;
    if (h >= c) {
      while (p > 0 && b > 0) {
        count += h;
        p--;
        b--;
      }
      while (f > 0 && b > 0) {
        count += c;
        f--;
        b--;
      }
    }
    if (h < c) {
      while (f > 0 && b > 0) {
        count += c;
        f--;
        b--;
      }
      while (p > 0 && b > 0) {
        count += h;
        p--;
        b--;
      }
    }
    cout << count << endl;
  }
  return 0;
}
