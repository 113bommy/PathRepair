#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 0, y = 0, z = 0;
    if (n % 3 == 0)
      x = x / 3;
    else if (n % 3 == 1) {
      x = (n - 7) / 3;
      z = 1;
    } else {
      x = (n - 5) / 3;
      y = 1;
    }
    if (x < 0 || y < 0 || z < 0)
      cout << -1 << endl;
    else
      cout << x << " " << y << " " << z << endl;
  }
}
