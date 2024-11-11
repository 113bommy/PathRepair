#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int b, p, f, h, c, c1 = 0, i, k, sum = 0;
    cin >> b >> p >> f;
    cin >> h >> c;
    k = b / 2;
    i = 1;
    if (h <= c) {
      while (k != 0 && i <= f) {
        c1++;
        i++;
        k--;
      }
      sum += (c * c1);
      c1 = 0;
      i = 1;
      while (k != 0 && i <= p) {
        c1++;
        i++;
        k--;
      }
      sum += (c1 * h);
    } else {
      while (k != 0 && i <= p) {
        c1++;
        i++;
        k--;
      }
      sum += (h * c1);
      c1 = 0;
      i = 1;
      while (k != 0 && i != f) {
        c1++;
        ;
        i++;
        k--;
      }
      sum += (c * c1);
    }
    cout << sum << endl;
  }
  return 0;
}
