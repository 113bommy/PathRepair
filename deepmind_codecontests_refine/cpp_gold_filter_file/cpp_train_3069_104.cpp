#include <bits/stdc++.h>
using namespace std;
int main() {
  int colo = 0, coup = 0, coarr = 0;
  char chs[8][8], arr[32];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> chs[i][j];
      if (chs[i][j] != '.') {
        arr[coarr] = chs[i][j];
        coarr++;
      }
    }
  }
  for (int i = 0; i < coarr; i++) {
    if ((int)arr[i] >= 65 && (int)arr[i] <= 90) {
      if (arr[i] == 'Q') {
        coup += 9;
      } else if (arr[i] == 'R') {
        coup += 5;
      } else if (arr[i] == 'B') {
        coup += 3;
      } else if (arr[i] == 'N') {
        coup += 3;
      } else if (arr[i] == 'P') {
        coup += 1;
      }
    } else if ((int)arr[i] >= 97 && (int)arr[i] <= 122) {
      if (arr[i] == 'q') {
        colo += 9;
      } else if (arr[i] == 'r') {
        colo += 5;
      } else if (arr[i] == 'b') {
        colo += 3;
      } else if (arr[i] == 'n') {
        colo += 3;
      } else if (arr[i] == 'p') {
        colo += 1;
      }
    }
  }
  if (colo > coup) {
    cout << "Black";
  } else if (coup > colo) {
    cout << "White";
  } else {
    cout << "Draw";
  }
  return 0;
}
