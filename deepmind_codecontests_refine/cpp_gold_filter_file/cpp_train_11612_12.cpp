#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, h2;
  int a, b;
  while (cin >> h1 >> h2) {
    cin >> a >> b;
    h1 += 8 * a;
    if (h1 < h2 && a <= b)
      cout << -1 << endl;
    else {
      int ans = 0;
      while (1) {
        if (h1 >= h2) {
          cout << ans << endl;
          break;
        }
        h1 -= 12 * b;
        h1 += 12 * a;
        ans++;
      }
    }
  }
  return 0;
}
