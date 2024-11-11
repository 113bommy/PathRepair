#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int q;
  cin >> q;
  string a;
  cin >> a;
  while (q--) {
    int l, h, i;
    cin >> l >> h;
    vector<char> c;
    for (i = l - 1; i < h; i++) c.push_back(a[i]);
    vector<int> b(10, 0);
    int cp = 0, dp = 1;
    i = 0;
    bool del = 0;
    int old;
    while (i >= 0 && i < c.size() && c.size() != 0) {
      if (isdigit(c[i])) {
        b[(int)(c[i] - 48)]++;
        if (c[i] != 48) {
          c[i]--;
        } else {
          c.erase(c.begin() + i);
          if (dp == 1) i--;
        }
        old = i;
        del = 0;
        i = i + dp;
      } else {
        if (del == 1) {
          c.erase(c.begin() + old);
          if (dp == 1) i--;
        }
        if (c[i] == '>') {
          dp = 1;
          del = 1;
        }
        if (c[i] == '<') {
          dp = -1;
          del = 1;
        }
        old = i;
        i = i + dp;
      }
    }
    for (i = 0; i < 10; i++) cout << b[i] << " ";
    cout << endl;
  }
}
