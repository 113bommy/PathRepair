#include <bits/stdc++.h>
using namespace std;
const int mn = 1e5 + 10;
int b, p, f, t;
int h, c;
int main() {
  cin >> t;
  int ans = 0;
  while (t--) {
    ans = 0;
    cin >> b >> p >> f;
    cin >> h >> c;
    if (h > c) {
      if (b / 2 >= p) {
        ans += p * h;
        b -= 2 * p;
        if (b >= 2) {
          ans += min(b / 2, f) * c;
        }
      } else
        ans = b / 2 * h;
    } else {
      if (b / 2 >= f) {
        ans += f * c;
        b -= 2 * f;
        if (b >= 2) {
          ans += min(b / 2, p) * h;
        }
      } else
        ans = b / 2 * c;
    }
    cout << ans << '\n';
  }
}
