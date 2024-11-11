#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, h, c[2];
    cin >> n >> c[0] >> c[1] >> h;
    string s;
    cin >> s;
    if (c[0] == c[1]) {
      cout << n * h << "\n";
    } else if (min(c[0], c[1]) + h >= max(c[0], c[1])) {
      int ans = 0;
      for (char e : s) ans += e == '0' ? c[0] : c[1];
      cout << ans << "\n";
    } else {
      int ans = n * min(c[0], c[1]);
      char ch = c[0] < c[1] ? '1' : '0';
      for (char e : s)
        if (e == ch) ans += h;
      cout << ans << "\n";
    }
  }
  return 0;
}
