#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 * 2 + 1;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ansx = 1e9 + 7, ansy = 0;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      ansx = min(y, ansx);
      ansy = max(x, ansy);
    }
    cout << abs(ansx - ansy) << '\n';
  }
  return 0;
}
