#include <bits/stdc++.h>
using namespace std;
int main() {
  long m;
  int hh, mm;
  int y = 0;
  cin >> m >> hh >> mm;
  while ((hh / 10) != 7 && (hh % 10) != 7 && (mm / 10) != 7 && (mm % 10) != 7) {
    mm -= m;
    if (mm < 0) {
      mm = 60 + mm;
      ++hh;
      if (hh < 0) {
        hh = 24 - hh;
      }
    }
    ++y;
  }
  cout << y;
}
