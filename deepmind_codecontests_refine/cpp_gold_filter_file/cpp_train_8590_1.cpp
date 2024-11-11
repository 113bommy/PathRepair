#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  cin >> n >> d >> h;
  if (d > 2 * h || (d == 1 && h == 1 && n > 2)) {
    cout << "-1\n";
  } else {
    int i = 1;
    for (; i <= h; i++) {
      cout << i << " " << i + 1 << endl;
    }
    if (d == h) {
      if (d < n - 1) {
        for (i = h + 2; i <= n; i++) {
          cout << h << " " << i << endl;
        }
      }
    } else {
      cout << "1 " << h + 2 << endl;
      for (i = h + 2; i <= d; i++) {
        cout << i << " " << i + 1 << endl;
      }
      for (i = d + 2; i <= n; i++) {
        cout << h << " " << i << endl;
      }
    }
  }
  return 0;
}
