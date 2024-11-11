#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, n, m;
    cin >> x >> n >> m;
    if (x <= 10 * m)
      cout << "YES" << endl;
    else {
      int temp = 0;
      for (int i = 0; i < n; i++) {
        x = x / 2 + 10;
        if (x <= 10 * m) {
          cout << "YES" << endl;
          temp = 1;
          break;
        }
      }
      if (temp == 0) cout << "NO" << endl;
    }
  }
  return 0;
}
