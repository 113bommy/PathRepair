#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b, max, min, c = 0;
    cin >> a >> b;
    if (a >= b) {
      max = a;
      min = b;
    } else {
      min = a;
      max = b;
    }
    while (min != max && max >= 0 && min > 0) {
      c += max / min;
      max = max % min;
      if (min > max) {
        int t = min;
        min = max;
        max = t;
      }
    }
    if (min == max && min != 0) c++;
    cout << c << endl;
  }
}
