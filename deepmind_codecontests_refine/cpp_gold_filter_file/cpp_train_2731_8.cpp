#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  char arr[9][9];
  cin >> t;
  for (int i = 0; i < t; i += 1) {
    for (int j = 0; j < 9; j += 1) {
      for (int k = 0; k < 9; k += 1) {
        cin >> arr[j][k];
      }
    }
    arr[0][8] = arr[0][0];
    arr[1][5] = arr[1][1];
    arr[2][1] = arr[2][2];
    arr[3][7] = arr[3][0];
    arr[4][4] = arr[4][1];
    arr[5][2] = arr[4][2];
    arr[6][6] = arr[6][0];
    arr[7][3] = arr[7][1];
    arr[8][0] = arr[8][2];
    for (int j = 0; j < 9; j += 1) {
      for (int k = 0; k < 9; k += 1) {
        cout << arr[j][k];
      }
      cout << endl;
    }
  }
}
