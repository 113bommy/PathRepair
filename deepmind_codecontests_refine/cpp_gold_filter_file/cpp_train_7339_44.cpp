#include <bits/stdc++.h>
using namespace std;
string x[8];
int canup(int i, int j) {
  i--;
  while (i >= 0) {
    if (x[i][j] != '.') return 0;
    i--;
  }
  return 1;
}
int candown(int i, int j) {
  i++;
  while (i < 8) {
    if (x[i][j] != '.') return 0;
    i++;
  }
  return 1;
}
int mna = 1 << 30, mnb = 1 << 30;
int main() {
  for (int i = 0; i < 8; i++) cin >> x[i];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (x[i][j] == 'W') {
        if (canup(i, j) == 1) mna = min(mna, i - 0);
      } else if (x[i][j] == 'B') {
        if (candown(i, j) == 1) mnb = min(mnb, 7 - i);
      }
    }
  }
  if (mna <= mnb)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
