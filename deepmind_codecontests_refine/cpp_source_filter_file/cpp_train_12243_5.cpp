#include <bits/stdc++.h>
using namespace std;
int main() {
  int hh, mm, i, result, neededmm;
  char dotto;
  cin >> hh >> dotto >> mm;
  result = 0;
  bool flag = false;
  do {
    if (hh % 10 < 6) {
      neededmm = (hh / 10 + (hh % 10) * 10);
      if (neededmm == mm) {
        cout << result;
        flag = true;
      } else if (neededmm > mm) {
        cout << result + neededmm - mm;
        flag = true;
      } else {
        do {
          hh++;
          if (hh < 23) {
            if (mm != 0) {
              result += 60 - mm;
              mm = 0;
            } else {
              result += 60;
            }
          }
          if (hh % 10 < 6) {
            neededmm = (hh / 10 + (hh % 10) * 10);
            if (hh >= 23) {
              cout << 60 - mm;
              flag = true;
              break;
            } else {
              result += neededmm;
              cout << result;
              flag = true;
            }
          }
        } while (hh % 10 > 5);
      }
    } else {
      if (mm != 0) {
        hh++;
        result += 60 - mm;
        mm = 0;
      } else {
        hh++;
        result += 60;
      }
    }
  } while (flag == false);
}
