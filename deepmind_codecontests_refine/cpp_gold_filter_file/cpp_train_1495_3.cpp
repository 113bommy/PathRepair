#include <bits/stdc++.h>
using namespace std;
unsigned long long l(unsigned long long q) {
  unsigned long long w, e, r = 0;
  for (w = 1; (w < q) || ((w <= q) && (q == 1)); w *= 10) {
    for (e = 1; (e < 10) && (w * (e + 1) <= q); e++) {
      if (w < 11)
        r++;
      else
        r += w / 10;
    }
    if (e == 10) continue;
    if ((w * e <= q) && (q < w * (e + 1))) {
      if (q % 10 < e)
        r += (q - e * w) / 10;
      else
        r += (q - e * w) / 10 + 1;
    }
  }
  return r;
}
int main() {
  unsigned long long q, w, e, r, t;
  cin >> q >> w;
  cout << l(w) - l(q - 1);
  return 0;
}
