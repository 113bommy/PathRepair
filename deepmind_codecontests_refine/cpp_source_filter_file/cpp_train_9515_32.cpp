#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int i, n, x, t, a, s;
  cin >> n;
  s = 0;
  t = 0;
  a = 0;
  for (i = 0; i < n; ++i) {
    cin >> x;
    s += x;
    t += 1 - x - x;
    if (t < 0) {
      t = 0;
    }
    if (t > a) {
      a = t;
    }
  }
  if (t == 0) {
    cout << s - 1;
  } else {
    cout << s + a;
  }
}
