#include <bits/stdc++.h>
using namespace std;
int main() {
  int foor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int total;
  cin >> total;
  char hosp[total];
  fill_n(hosp, total, 0);
  cin >> hosp;
  for (int k = 0; k < total; k++) {
    if (hosp[k] == 'L') {
      for (int d = 0; d < 10; d++) {
        if (foor[d] != 1) {
          foor[d] = 1;
          d = 10;
        }
      }
    }
    if ((hosp[k] != 'L') && (hosp[k] != 'R')) {
      foor[(hosp[k] - '0')] = 0;
    }
    if (hosp[k] == 'R') {
      for (int p = 10; p > 0; p--) {
        if (foor[p] != 1) {
          foor[p] = 1;
          p = 0;
        }
      }
    }
  }
  for (int j = 0; j < 10; j++) {
    cout << foor[j];
  }
  return 0;
}
