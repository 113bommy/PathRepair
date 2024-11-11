#include <bits/stdc++.h>
using namespace std;
int row, col;
bool isOnEdge(int i, int j) { return !(i > 1 && i < row && j > 1 && j < col); }
int main() {
  int flag = 0, i, j, num;
  cin >> row >> col;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      cin >> num;
      if (num == 0) continue;
      if (flag == 0) {
        if (isOnEdge(i + 1, j + 1)) flag = 1;
      }
    }
  }
  (flag == 1) ? (cout << "2" << endl) : (cout << "4" << endl);
  return 0;
}
