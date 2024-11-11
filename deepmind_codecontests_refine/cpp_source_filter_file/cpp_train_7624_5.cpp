#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    int d;
    int max = 1000000;
    if (a < 2 * b) {
      d = 4 * b * b;
      if (d < max) {
        max = d;
      }
    } else {
      d = a * a;
      if (d < max) {
        max = d;
      }
    }
    if (2 * a > b) {
      d = 4 * a * a;
      if (d < max) {
        max = d;
      }
    } else {
      d = b * b;
      if (d < max) {
        max = d;
      }
    }
    cout << max;
  }
  return 0;
}
