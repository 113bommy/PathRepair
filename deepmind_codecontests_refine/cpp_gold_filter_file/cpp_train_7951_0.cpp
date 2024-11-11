#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n;
  int dem = 0;
  cin >> n;
  if (n >= 1e4 + 1) {
    cout << "nothing";
  } else {
    for (c = 1; c <= n; c++) {
      for (b = 1; b <= c; b++) {
        a = sqrt((c * c) - (b * b));
        if (a > 0 && a <= b && ((a * a) + (b * b) == (c * c))) {
          dem++;
        }
      }
    }
    cout << dem;
  }
  return 0;
}
