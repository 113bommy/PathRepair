#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, w, e, r, r1, t, c, v, y = 10000000;
  bool a[1000000];
  cin >> q >> w;
  if (w == 1) {
    if (q == 1)
      cout << "0\nT";
    else
      cout << "IMPOSSIBLE";
    return 0;
  }
  for (e = w; e > 0; e--) {
    r = r1 = 0;
    for (c = e, v = w; (c) && (v);)
      if (c > v) {
        r += c / v;
        r1 += c / v - 1;
        c %= v;
      } else {
        r += v / c;
        r1 += v / c - 1;
        v %= c;
      }
    if ((c + v == 1) && ((r == q) && (r1 < y))) {
      t = e;
      y = r1;
    }
  }
  if (y == 10000000) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  e = 0;
  for (c = t, v = w; (c) && (v);)
    if (c > v) {
      c -= v;
      a[e] = 0;
      e++;
    } else {
      v -= c;
      a[e] = 1;
      e++;
    }
  a[q - 1] = 0;
  if (a[q - 2] == a[q - 1])
    for (e = 0; e < q - 1; e++) a[e] = 1 - a[e];
  cout << y - 1 << "\n";
  for (e = q - 1; e >= 0; e--)
    if (a[e])
      printf("B");
    else
      printf("T");
  return 0;
}
