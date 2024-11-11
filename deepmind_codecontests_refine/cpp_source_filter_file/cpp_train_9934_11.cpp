#include <bits/stdc++.h>
using namespace std;
int main() {
  int sh, sm, th, tm, ph, pm;
  char h;
  cin >> sh >> h >> sm;
  cin >> th >> h >> tm;
  if (tm > sm) {
    pm = tm - sm;
    ph = sh - th - 1;
    if (ph < 0) {
      ph += 24;
    }
  } else {
    pm = sm - tm;
    ph = sh - th;
    if (ph < 0) {
      ph += 24;
    }
  }
  if (ph < 10) {
    cout << 0 << ph << ':';
  } else {
    cout << ph << ':';
  }
  if (pm < 10) {
    cout << 0 << pm;
  } else {
    cout << pm;
  }
}
