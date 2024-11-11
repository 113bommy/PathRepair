#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if ((x < 3) || (x == 4) || (x == 5)) {
      cout << "NO" << endl;
    } else {
      if ((x % 3 == 0) || (x % 7 == 0)) {
        cout << "YES" << endl;
      } else {
        int liko = x % 3;
        if ((liko == 1) && (x - 7) > 0 && (x - 7) % 3 == 0) {
          cout << "YES" << endl;
        }
        if ((liko == 2) && (x - 14) > 0 && (x - 14) % 3 == 0) {
          cout << "YES" << endl;
        } else
          cout << "NO" << endl;
      }
    }
  }
  return 0;
}
