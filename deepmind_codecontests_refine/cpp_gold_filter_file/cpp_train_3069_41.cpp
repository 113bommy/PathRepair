#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[9][9];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> a[i][j];
    }
  }
  int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
  int sum11 = 0, sum22 = 0, sum33 = 0, sum44 = 0, sum55 = 0;
  int to1;
  int to2;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i][j] == 'q') {
        sum11++;
      }
      if (a[i][j] == 'r') {
        sum22++;
      }
      if (a[i][j] == 'b') {
        sum33++;
      }
      if (a[i][j] == 'n') {
        sum44++;
      }
      if (a[i][j] == 'p') {
        sum55++;
      }
      if (a[i][j] == 'Q') {
        sum1++;
      }
      if (a[i][j] == 'R') {
        sum2++;
      }
      if (a[i][j] == 'B') {
        sum3++;
      }
      if (a[i][j] == 'N') {
        sum4++;
      }
      if (a[i][j] == 'P') {
        sum5++;
      }
    }
  }
  to1 = sum1 * 9 + sum2 * 5 + sum3 * 3 + sum4 * 3 + sum5;
  to2 = sum11 * 9 + sum22 * 5 + sum33 * 3 + sum44 * 3 + sum55;
  if (to1 == to2)
    cout << "Draw" << endl;
  else if (to1 > to2)
    cout << "White" << endl;
  else
    cout << "Black" << endl;
  return 0;
}
