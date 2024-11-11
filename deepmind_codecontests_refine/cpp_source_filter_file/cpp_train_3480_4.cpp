#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b, v;
  while (cin >> k >> a >> b >> v) {
    int box = 0;
    while (b > 0 && a > 0) {
      if (b + 1 >= k) {
        b -= k - 1;
        box++;
        a -= (v * k);
      } else {
        box++;
        a -= (v * b + 1);
        b = 0;
      }
    }
    while (a > 0) {
      a -= v;
      box++;
    }
    cout << box << endl;
  }
  return 0;
}
