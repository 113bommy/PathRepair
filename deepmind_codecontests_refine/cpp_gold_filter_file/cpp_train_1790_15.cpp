#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, r = 0;
    cin >> m;
    if (m < 4) {
      r = 4 - m;
    } else {
      if (m % 2 == 0) {
        r = 0;
      } else {
        r = 1;
      }
    }
    cout << r << endl;
  }
  return 0;
}
