#include <bits/stdc++.h>
using namespace std;
int a[100000], s[100000];
void qs(int q, int w) {
  int e = q, r = w, t = s[q + (rand() % (w - q + 1))], y;
  do {
    while (s[e] < t) e++;
    while (s[r] > t) r--;
    if (e <= r) {
      y = s[e];
      s[e] = s[r];
      s[r] = y;
      e++;
      r--;
    }
  } while (e <= r);
  if (q < r) qs(q, r);
  if (e < w) qs(e, w);
}
int main() {
  int q, w, r;
  long long e, t, y = 0, c;
  cin >> q >> t;
  for (w = 0; w < q; w++) {
    cin >> a[w];
    s[w] = a[w];
    y += a[w];
  }
  if (y < t)
    cout << -1;
  else {
    if (y == t) return 0;
    qs(0, q - 1);
    r = 0;
    for (w = 0; w < q; w++) {
      c = s[w] - r;
      e = t / (q - w);
      if (c <= e) {
        r += c;
        t -= (q - w) * e;
      } else {
        r += e;
        t -= e * (q - w);
        break;
      }
    }
    for (w = 0; w < q; w++)
      if (a[w] < r)
        a[w] = 0;
      else
        a[w] -= r;
    for (w = 0; t; t--) {
      while (a[w] == 0) w = (w + 1) % q;
      a[w]--;
      w = (w + 1) % q;
    }
    e = w;
    for (; a[e] == 0; e = (e + 1) % q)
      ;
    do {
      cout << e + 1 << " ";
      e = (e + 1) % q;
      for (; (a[e] == 0) && (e != w); e = (e + 1) % q)
        ;
    } while (e != w);
  }
  return 0;
}
