#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (x > 3) {
      cout << "YES" << endl;
    } else if (x == y) {
      cout << "YES" << endl;
    } else if ((x == 2 || x == 3) && y <= 3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
