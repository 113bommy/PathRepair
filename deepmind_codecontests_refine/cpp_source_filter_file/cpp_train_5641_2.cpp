#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T > 0) {
    int b, p, f, sum = 0;
    cin >> b >> p >> f;
    int h, c;
    cin >> h >> c;
    if (c >= h && b != 1) {
      if (b - 2 * f >= 0) {
        sum += f * c;
        if (b - 2 * f - 2 * p >= 0)
          sum += p * h;
        else
          sum += ((b - 2 * f) / 2) * h;
      } else
        sum += (b / 2) * c;
    } else if (c < h && b != 1) {
      if (b - 2 * p >= 0) {
        sum += p * h;
        if (b - 2 * f - 2 * p >= 0)
          sum += c * f;
        else
          ((b - 2 * p) / 2) * c;
      } else
        sum += (b / 2) * h;
    }
    cout << sum << endl;
    T--;
  }
  return 0;
}
