#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> v;
  int mx = -1, sz;
  string s;
  while (getline(cin, s)) {
    v.push_back(s);
    sz = s.length();
    mx = max(mx, sz);
  }
  bool state = true;
  cout << string(mx + 2, '*') << '\n';
  for (auto f : v) {
    cout << '*';
    sz = f.length();
    if (!sz) {
      cout << string(mx, ' ') << '*' << '\n';
      continue;
    }
    if (sz != mx) {
      int l, r;
      if ((mx - sz) & 1) {
        if (state) {
          l = ((mx - sz) / 2);
          r = mx - l - sz;
          state = false;
        } else {
          l = ((mx - sz) / 2) + 1;
          r = mx - l - sz;
          state = true;
        }
      } else {
        l = (mx - sz);
        r = l;
      }
      cout << string(l, ' ') << f << string(r, ' ') << '*' << '\n';
    } else
      cout << f << '*' << '\n';
  }
  cout << string(mx + 2, '*') << '\n';
  return 0;
}
