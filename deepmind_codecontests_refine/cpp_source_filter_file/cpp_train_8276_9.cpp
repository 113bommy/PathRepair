#include <bits/stdc++.h>
using namespace std;
int main() {
  int hh, mm, a, h, m, n;
  char c;
  cin >> hh >> c >> mm >> a;
  if (a > 60) {
    h = a / 60;
    m = a % 60;
    hh += h;
    mm += m;
    if (mm > 60) {
      n = mm / 60;
      hh += n;
      mm %= 60;
    }
    if (hh > 23) {
      hh %= 24;
    }
  } else {
    mm += a;
    if (mm > 60) {
      n = mm / 60;
      hh += n;
      mm %= 60;
    }
    if (hh > 23) {
      hh %= 24;
    }
  }
  if (hh < 10 && mm < 10)
    cout << 0 << hh << c << 0 << mm << endl;
  else if (hh < 10 && mm >= 10)
    cout << 0 << hh << c << mm << endl;
  else if (hh >= 10 && mm < 10)
    cout << hh << c << 0 << mm << endl;
  else
    cout << hh << "" << c << "" << mm << endl;
  return 0;
}
