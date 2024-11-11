#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 4) {
      cout << -1 << endl;
      continue;
    }
    if (n % 3 == 0) {
      cout << n / 3 << " " << 0 << " " << 0 << endl;
      continue;
    } else if (n % 3 == 1) {
      int count7 = 0;
      while (n % 3 != 0) {
        n = n - 7;
        count7++;
      }
      cout << n / 2 << " " << 0 << " " << count7 << endl;
    } else {
      int count5 = 0;
      while (n % 3 != 0) {
        n = n - 5;
        count5++;
      }
      cout << n / 3 << " " << count5 << " " << 0 << endl;
    }
  }
  return 0;
}
