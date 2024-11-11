#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    if (abs(x - y) % d == 0) {
      cout << abs(x - y) / d << endl;
      continue;
    }
    int opt = -1;
    if ((y - 1) % d == 0) {
      opt = (y - 1) / d + (x - 1) / d + ((x - 1) % d != 0);
    }
    if ((n - y) % d == 0) {
      if (opt == -1)
        opt = ((n - y) / d) + (n - x) / d + ((n - x) % d != 0);
      else
        opt = min(((n - y) / d + (n - x) / d + (int)((n - x) % d != 0)), opt);
    }
    cout << opt << endl;
  }
  return 0;
}
