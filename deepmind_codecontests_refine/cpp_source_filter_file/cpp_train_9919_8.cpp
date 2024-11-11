#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    n = n - 2;
    if (n < 2) {
      cout << "1";
    } else {
      int f = 1;
      f = f + n / x;
      if (n % x == 0) {
        cout << f;
      } else {
        cout << f + 1;
      }
    }
    cout << endl;
  }
  return 0;
}
