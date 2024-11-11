#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j, n;
  char ch;
  int num;
  cin >> n;
  int fl[10];
  for (i = 0; i <= 9; i++) fl[i] = 2;
  for (i = 1; i <= n; i++) {
    cin >> ch >> num;
    if (ch == '|') {
      for (j = 0; j <= 9; j++) {
        int z = num & (1 << j);
        if (z > 0) fl[j] = 1;
      }
    } else if (ch == '&') {
      for (j = 0; j <= 9; j++) {
        int z = num & (1 << j);
        if (z == 0) fl[j] = 0;
      }
    } else {
      for (j = 0; j <= 9; j++) {
        int z = num & (1 << j);
        if (z > 0) {
          if (fl[j] == 2)
            fl[j] = 3;
          else if (fl[j] == 3)
            fl[j] = 2;
          else {
            fl[j] = 1 - fl[j];
          }
        }
      }
    }
  }
  int num1 = 0, num2 = 0, num3 = 0;
  for (j = 0; j <= 9; j++) {
    if (fl[j] == 2) {
      num2 |= (1 << j);
    } else if (fl[j] == 3) {
      num2 |= (1 << j);
      num3 |= (1 << j);
    } else {
      if (fl[j] == 1) num2 |= (1 << j);
      num1 |= (1 << j);
    }
  }
  cout << 3 << ('\n');
  cout << "| " << num1 << ('\n');
  cout << "& " << num2 << ('\n');
  cout << "^ " << num3 << ('\n');
  return 0;
}
