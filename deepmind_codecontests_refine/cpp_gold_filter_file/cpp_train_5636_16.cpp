#include <bits/stdc++.h>
using namespace std;
bool s[1000001];
int a[100000], a1[100000], d[1000001];
int main() {
  int q, w, e, r, t = 0, c, v;
  long long f[10], ans = 0;
  s[1] = 0;
  for (w = 2; w < 1000001; w++) s[w] = 1;
  for (w = 2; w < 1000001; w++)
    if (s[w]) {
      a[t] = w;
      if (w < 1100) {
        a1[t] = w * w;
        for (e = a1[t]; e < 1000001; e += w) s[e] = 0;
      }
      t++;
    }
  for (w = 0; w < 10; w++) f[w] = 0;
  cin >> q;
  for (w = 1; w <= 1000000; w++) {
    if (w < 10)
      d[w] = w;
    else
      d[w] = d[w / 10 + (w % 10)];
    if (w <= q) f[d[w]]++;
  }
  for (w = 1; w < 10; w++)
    for (e = 1; e < 10; e++) ans += f[w] * f[e] * f[d[w * e]];
  for (w = 1; w <= q; w++) {
    c = 1;
    r = w;
    for (e = 0; (a1[e] <= r) && (!s[r]); e++) {
      v = 1;
      while (r % a[e] == 0) {
        v++;
        r /= a[e];
      }
      c *= v;
    }
    if (r > 1) c <<= 1;
    ans -= c;
  }
  cout << ans;
  return 0;
}
