#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int main() {
  int a, b, c, d, g, w, h, tot, noto, noto2, tot2;
  cin >> a >> b >> c >> d;
  if (a == b) a = b = max(c, d);
  tot = a * c;
  w = tot / a * b;
  h = tot / c * d;
  noto = abs(w - h);
  tot = max(w, h);
  tot2 = b * d;
  w = tot2 / b * a;
  h = tot2 / d * c;
  noto2 = abs(w - h);
  tot2 = max(w, h);
  if (abs(noto2 - tot2) > abs(noto - tot)) {
    g = gcd(noto2, tot2);
    noto2 /= g;
    tot2 /= g;
    cout << noto2 << "/" << tot2;
  } else {
    g = gcd(noto, tot);
    noto /= g;
    tot /= g;
    cout << noto << "/" << tot;
  }
  return 0;
}
