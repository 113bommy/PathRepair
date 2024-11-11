#include <bits/stdc++.h>
using namespace std;
string s;
int ask(int x, int y) {
  cout << "? " << x << " " << y << endl;
  string ans;
  cin >> ans;
  return ans[0] == 'y';
}
void sout(int res) { cout << "! " << res << endl; }
int main() {
  int x = 1;
  while (cin >> s) {
    x = 1;
    if (s[0] == 's') {
      if (!ask(0, 1)) {
        sout(1);
        continue;
      }
      while (ask(x, x << 1)) {
        x <<= 1;
      }
      int l = x + 1, r = (x << 1) - 1, res = x << 1;
      while (l <= r) {
        int mid = l + r >> 1;
        if (mid == x) break;
        if (ask(mid, x << 1)) {
          res = mid;
          r = mid - 1;
        } else
          l = mid + 1;
      }
      sout(res);
    } else if (s[0] == 'e') {
      return 0;
    }
  }
  return 0;
}
