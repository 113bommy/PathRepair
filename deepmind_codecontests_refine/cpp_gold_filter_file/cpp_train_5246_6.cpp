#include <bits/stdc++.h>
using namespace std;
int main() {
  int s = -1, t = -1;
  int rc = 0, lc = 0;
  int n;
  string st;
  cin >> n >> st;
  for (int i = 0; i < n; i++) {
    if (st[i] == 'R') {
      rc++;
      if (s == -1) {
        s = i + 1;
      }
    }
    if (st[i] == 'L') {
      lc++;
      if (t == -1) {
        t = i + 1;
      }
    }
  }
  if (s == -1) {
    cout << t + lc - 1 << " " << t - 1;
  } else if (t == -1) {
    cout << s << " " << s + rc;
  } else {
    cout << s << " " << t;
  }
}
