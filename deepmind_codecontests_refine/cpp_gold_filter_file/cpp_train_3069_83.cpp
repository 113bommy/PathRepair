#include <bits/stdc++.h>
using namespace std;
int main() {
  char arr[8][8];
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (int(arr[i][j]) >= 65 && int(arr[i][j]) <= 90) {
        if (arr[i][j] == 'Q')
          sum1 += 9;
        else if (arr[i][j] == 'R')
          sum1 += 5;
        else if (arr[i][j] == 'B')
          sum1 += 3;
        else if (arr[i][j] == 'N')
          sum1 += 3;
        else if (arr[i][j] == 'P')
          sum1 += 1;
        else if (arr[i][j] == 'K')
          sum1 += 0;
      } else if (int(arr[i][j]) >= 97 && int(arr[i][j]) <= 122) {
        if (arr[i][j] == 'q')
          sum2 += 9;
        else if (arr[i][j] == 'r')
          sum2 += 5;
        else if (arr[i][j] == 'b')
          sum2 += 3;
        else if (arr[i][j] == 'n')
          sum2 += 3;
        else if (arr[i][j] == 'p')
          sum2 += 1;
        else if (arr[i][j] == 'k')
          sum2 += 0;
      }
    }
  }
  if (sum1 > sum2)
    cout << "White" << endl;
  else if (sum1 < sum2)
    cout << "Black" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
