#include <bits/stdc++.h>
using namespace std;
long long int typedef li;
li xlol, ylol;
li nzd(li a, li b) {
  if (a == 0) return b;
  if (b == 0) return a;
  while (true) {
    if (a % b == 0) return b;
    if (b % a == 0) return a;
    if (a > b)
      a %= b;
    else
      b %= a;
  }
}
void resi(li a, li b) {
  if (b == 0) {
    xlol = 1;
    return;
  }
  resi(b, a % b);
  li t = xlol;
  xlol = ylol;
  ylol = t - (a / b) * ylol;
}
int main() {
  bool reverse = false, minusa = false, minusb = false;
  li a, b, c, t, d;
  cin >> a >> b >> c;
  if (a < 0) {
    a *= -1;
    minusa = true;
  }
  if (b < 0) {
    b *= -1;
    minusb = true;
  }
  if (b > a) {
    t = a;
    a = b;
    b = t;
    reverse = true;
  }
  if (b == 0) {
    if (c % a != 0) {
      cout << -1;
      return 0;
    }
    if (reverse)
      cout << 69 << " " << -c / a;
    else
      cout << -c / a << " " << 69;
    return 0;
  }
  d = nzd(a, b);
  if (c % d != 0) {
    cout << -1;
    return 0;
  }
  c /= d;
  a /= d;
  b /= d;
  resi(a, b);
  if (!reverse) {
    if (minusa) xlol *= -1;
    if (minusb) ylol *= -1;
    cout << -xlol * c << " " << -ylol * c;
  } else {
    if (minusa) ylol *= -1;
    if (minusb) xlol *= -1;
    cout << -ylol * c << " " << -xlol * c;
  }
}
