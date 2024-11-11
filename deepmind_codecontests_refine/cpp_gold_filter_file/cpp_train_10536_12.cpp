#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    sort(begin(s), end(s));
    int l = 0, r = 0, u = 0, d = 0;
    for (auto& c : s) {
      if (c == 'L') ++l;
      if (c == 'R') ++r;
      if (c == 'U') ++u;
      if (c == 'D') ++d;
    }
    int dx = r - l;
    int dy = u - d;
    if (dx < 0) l -= -dx;
    if (dx > 0) r -= dx;
    if (dy < 0) d -= -dy;
    if (dy > 0) u -= dy;
    if (u == 0 or d == 0) {
      if (l == 0 or r == 0) {
        cout << 0 << endl;
      } else {
        cout << 2 << endl;
        cout << "LR" << endl;
      }
    } else if (l == 0 or r == 0) {
      if (u == 0 or d == 0) {
        cout << 0 << endl;
      } else {
        cout << 2 << endl;
        cout << "UD" << endl;
      }
    } else {
      string out;
      for (int i = (0); i < (l); ++i) out.push_back('L');
      for (int i = (0); i < (u); ++i) out.push_back('U');
      for (int i = (0); i < (r); ++i) out.push_back('R');
      for (int i = (0); i < (d); ++i) out.push_back('D');
      cout << (int)(out).size() << endl;
      cout << out << endl;
    }
  }
}
