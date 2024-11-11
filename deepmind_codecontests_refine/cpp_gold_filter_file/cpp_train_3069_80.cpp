#include <bits/stdc++.h>
using namespace std;
int main() {
  char arr[8][8];
  int i, j, w = 0, b = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> arr[i][j];
    }
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (arr[i][j] >= 65 && arr[i][j] <= 90) {
        if (arr[i][j] == 'Q') w = w + 9;
        if (arr[i][j] == 'R') w = w + 5;
        if (arr[i][j] == 'B') w = w + 3;
        if (arr[i][j] == 'N') w = w + 3;
        if (arr[i][j] == 'P') w = w + 1;
        if (arr[i][j] == 'K') continue;
      }
      if (arr[i][j] >= 97 && arr[i][j] <= 122) {
        if (arr[i][j] == 'q') b = b + 9;
        if (arr[i][j] == 'r') b = b + 5;
        if (arr[i][j] == 'b') b = b + 3;
        if (arr[i][j] == 'n') b = b + 3;
        if (arr[i][j] == 'p') b = b + 1;
        if (arr[i][j] == 'k') continue;
      }
    }
  }
  if (w > b)
    cout << "White";
  else if (b > w)
    cout << "Black";
  else
    cout << "Draw";
}
