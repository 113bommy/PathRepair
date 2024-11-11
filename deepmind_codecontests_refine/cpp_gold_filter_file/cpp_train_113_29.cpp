#include <bits/stdc++.h>
using namespace std;
const int bitmax = 29;
int question(int c, int d) {
  cout << "? " << c << " " << d << endl;
  cout.flush();
  int res;
  cin >> res;
  return res;
}
int a, b;
int main() {
  int rel = question(a, b);
  for (int bit = bitmax; bit >= 0; bit--) {
    int B = 1 << bit;
    if (rel == 1) {
      if (question(a | B, b | B) == 1) {
        if (question(a | B, b) == -1) {
          a |= B;
          b |= B;
        }
      } else {
        a |= B;
        rel = question(a, b);
      }
    } else if (rel == -1) {
      if (question(a | B, b | B) == -1) {
        if (question(a | B, b) == -1) {
          a |= B;
          b |= B;
        }
      } else {
        b |= B;
        rel = question(a, b);
      }
    } else {
      if (question(a, b | B) == 1) {
        a |= B;
        b |= B;
      }
    }
  }
  cout << "! " << a << " " << b << endl;
  cout.flush();
}
