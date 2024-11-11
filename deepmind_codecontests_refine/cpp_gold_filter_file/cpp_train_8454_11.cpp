#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    long long x = 0, c = 0, y = 0, ans, g;
    int n;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> g;
      if (g > 0) {
        x = x + g;
      } else if (g < 0) {
        y = y + g;
      } else if (g == 0) {
        x++;
        c++;
      }
    }
    ans = x + y;
    if (ans != 0) {
      cout << c << endl;
    } else {
      cout << c + abs(x + y) + 1 << endl;
    }
  }
  return 0;
}
