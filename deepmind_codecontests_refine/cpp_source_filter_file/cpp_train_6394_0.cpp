#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, w, e, r, t, y = 0, c = 0, v = 0, u, i, o, i1;
  cin >> q >> w >> e >> r >> t;
  while ((q < t) && (w >= r)) {
    w -= r;
    t--;
    y++;
  }
  if (q >= t)
    cout << y;
  else {
    u = w;
    do {
      if (w >= r)
        w -= r;
      else {
        w += e - r;
        c++;
      }
      v++;
    } while (w != u);
    i = 0;
    o = 2147483648;
    while (o) {
      i1 = i + o;
      if (q - c * i1 <= t - v * i1) i = i1;
      o /= 2;
    }
    y += v * i;
    q -= c * i;
    t -= v * i;
    while (q < t) {
      if (w >= r)
        w -= r;
      else {
        w += e - r;
        q--;
      }
      t--;
      y++;
    }
    cout << y;
  }
  return 0;
}
