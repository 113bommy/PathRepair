#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long b, p, f, h, c, cost = 0;
    cin >> b >> p >> f >> h >> c;
    b = b / 2;
    if (h > c) {
      if (b >= p) {
        cost += p * h;
        b = b - p;
      } else {
        cost += b * h;
        b = 0;
      }
      if (b != 0) {
        if (b >= f) {
          cost += f * c;
          b = b - f;
        } else {
          cost += b * c;
          b = 0;
        }
      }
    } else if (h < c) {
      if (b >= f) {
        cost += f * c;
        b = b - f;
      } else {
        cost += b * c;
        b = 0;
      }
      if (b != 0) {
        if (b >= p) {
          cost += p * h;
          b = b - p;
        } else {
          cost += b * h;
          b = 0;
        }
      }
    }
    cout << cost << "\n";
  }
  return 0;
}
