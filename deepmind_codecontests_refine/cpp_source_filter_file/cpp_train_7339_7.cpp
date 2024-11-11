#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, i, j, k, l, n, m, arr[100001],
      MinW = 9999999999999, MinB = 999999999999, Max = 0, _count = 0, sum = 0,
      black = 0, white = 0;
  char str[100][100];
  for (int i = (int)0; i < int(8); i++) {
    cin >> str[i];
  }
  for (int i = (int)0; i < int(8); i++) {
    for (int j = (int)0; j < int(8); j++) {
      if (str[j][i] == 'W') {
        a = 0;
        b = 0;
        for (k = j - 1; k >= 0; k--) {
          if (str[k][i] != '.') {
            b = 1;
            break;
          }
          a++;
        }
        if (b == 0 && a < MinW) MinW = a;
      } else if (str[j][i] == 'B') {
        a = 0;
        b = 0;
        for (k = j + 1; k < 8; k++) {
          if (str[k][i] != '.') {
            b = 1;
            break;
          }
          a++;
        }
        if (b == 0 && a < MinB) MinB = a;
      }
    }
  }
  if (MinB > MinW)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
