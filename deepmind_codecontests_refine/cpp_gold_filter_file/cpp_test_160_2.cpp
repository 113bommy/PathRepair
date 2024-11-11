#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int row, column, r_row, r_column, f_row, f_column;
    int dr = 1, dc = 1;
    cin >> row >> column >> r_row >> r_column >> f_row >> f_column;
    int count;
    count = 0;
    while (f_row != r_row && f_column != r_column) {
      if (r_row + dr > row || r_row + dr < 1) {
        dr *= (-1);
      }
      if (r_column + dc > column || r_column + dc < 1) {
        dc *= (-1);
      }
      r_column += dc;
      r_row += dr;
      count++;
    }
    cout << count << endl;
  }
}
