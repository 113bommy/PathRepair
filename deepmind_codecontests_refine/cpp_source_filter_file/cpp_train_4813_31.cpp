#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, a, b, c, aa, bb, cc, ans, temp;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    ans = INT_MAX;
    for (int i = 1; i <= 10000; i++) {
      for (int j = i; j <= 10000; j += i) {
        for (int k = j; k <= 10000; k += j) {
          temp = abs(i - a) + abs(j - b) + abs(k - c);
          if (temp < ans) {
            ans = temp;
            aa = i, bb = j, cc = k;
          }
        }
      }
    }
    cout << ans << '\n';
    cout << aa << ' ' << bb << ' ' << cc << '\n';
  }
  return 0;
}
