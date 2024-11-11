#include <bits/stdc++.h>
using namespace std;
int main() {
  int rows, columns, i, j, cnt = 0;
  cin >> rows;
  cin >> columns;
  char matrix[rows][columns];
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      cin >> matrix[i][j];
    }
    cout << endl;
  }
  for (i = 0; i < (columns); i++) {
    if (matrix[rows - 1][i] == 'B') cnt++;
  }
  for (i = 0; i < (columns - 1); i++) {
    if (matrix[(rows - 1)][i] == 'B' && matrix[(rows - 1)][i + 1] == 'B') cnt--;
  }
  cout << cnt;
  return 0;
}
