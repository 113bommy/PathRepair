#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, n, m;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x >> n >> m;
    if (x - (m * 10) == 0) {
      cout << "YES" << endl;
    } else {
      for (int j = 0; j < n; j++) {
        x = (x / 2) + 10;
      }
      x = x - (m * 10);
      if (x <= 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
