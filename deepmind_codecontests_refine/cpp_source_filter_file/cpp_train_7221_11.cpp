#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[5][5];
  int row, col;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        row = i;
        col = j;
      }
    }
  }
  int rowDiff = row - 3;
  int colDiff = col - 3;
  if (rowDiff < 0) rowDiff = -rowDiff;
  if (colDiff < 0) colDiff = -colDiff;
  int operations = rowDiff + colDiff;
  cout << operations;
}
