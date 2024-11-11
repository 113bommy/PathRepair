#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, n, m;
  cin >> t;
  while (t > 0) {
    cin >> x >> n >> m;
    while (x > 20 && n > 0) {
      x = (x / 2) + 10;
      n--;
    }
    if (x <= (10 * m)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    t--;
  }
}
