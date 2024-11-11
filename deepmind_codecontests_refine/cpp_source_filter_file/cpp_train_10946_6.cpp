#include <bits/stdc++.h>
using namespace std;
template <class T>
inline istream& operator>>(istream& str, vector<T>& a) {
  for (auto& i : a) str >> i;
  return str;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 7 * min({a / 3, b / 2, c / 2});
  int mx = 0;
  a -= ans / 7 * 3, b -= ans / 7 * 2, c -= ans / 7 * 2;
  for (int i = 0; i < 7; ++i) {
    int now = 0, f = a, r = b, ch = c;
    for (int j = 0; j < 7; ++j) {
      int d = (i + j);
      if (d == 1 or d == 2 or d == 5) {
        if (f == 0) break;
        f--;
      } else if (d == 0 or d == 3) {
        if (r == 0) break;
        r--;
      } else {
        if (ch == 0) break;
        ch--;
      }
      now++;
    }
    mx = max(mx, now);
  }
  ans += mx;
  cout << ans << "\n";
  return 0;
}
