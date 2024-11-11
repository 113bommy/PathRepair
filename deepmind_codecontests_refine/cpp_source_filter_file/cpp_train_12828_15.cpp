#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    cout << min(n, max(1, x + y + 1 - n)) << " " << min(x + y - 1, n) << endl;
    return 0;
  }
}
