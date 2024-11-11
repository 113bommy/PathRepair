#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int hh, mm;
  cin >> hh >> mm;
  int count = 0;
  int lastmm, lasthh;
  while (1) {
    lastmm = mm % 10;
    lasthh = hh % 10;
    if (lastmm == 7 || lasthh == 7) {
      cout << count;
      break;
    } else {
      mm -= x;
      count++;
      if (mm < 0) {
        hh--;
        if (hh < 00) {
          hh += 24;
        }
        mm = mm + 60;
      }
    }
  }
  return 0;
}
