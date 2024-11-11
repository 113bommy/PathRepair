#include <bits/stdc++.h>
using namespace std;
int main() {
  char arr[8][8] = {0};
  for (int j = 0; j < 8; j++) {
    cin >> arr[j][0] >> arr[j][1] >> arr[j][2] >> arr[j][3] >> arr[j][4] >>
        arr[j][5] >> arr[j][6] >> arr[j][7];
  }
  int winW = 8;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (arr[j][i] == 'B') {
        break;
      }
      if (arr[j][i] == 'W') {
        if (j < winW) {
          winW = j;
        }
      }
    }
  }
  int winB = 8;
  for (int i = 0; i < 8; i++) {
    for (int j = 8; j <= 0; j++) {
      if (arr[j][i] == 'W') {
        break;
      }
      if (arr[j][i] == 'B') {
        if ((7 - j) < winB) {
          winB = 7 - j;
        }
      }
    }
  }
  if (winW == winB) {
    cout << "A" << endl;
  } else if (winW > winB) {
    cout << "B" << endl;
  } else {
    cout << "A" << endl;
  }
  return 0;
}
