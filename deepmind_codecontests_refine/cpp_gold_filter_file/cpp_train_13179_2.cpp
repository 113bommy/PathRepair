#include <bits/stdc++.h>
using namespace std;
struct noone {
  int row, column;
};
int main() {
  int n, i, j;
  scanf("%d", &n);
  vector<noone> numbers;
  vector<int> checker(100001, 0);
  vector<vector<int> > column(n + 1, checker);
  vector<vector<int> > matrix(n + 1);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      int k;
      scanf("%d", &k);
      matrix[i].push_back(k);
      column[j][k] = 1;
      if (k != 1) {
        noone tmp;
        tmp.row = i;
        tmp.column = j;
        numbers.push_back(tmp);
      }
    }
  }
  bool chk = 1;
  for (i = 0; i < numbers.size(); i++) {
    int currow = numbers[i].row, curcolumn = numbers[i].column;
    int target = matrix[currow][curcolumn];
    chk = 0;
    for (j = 0; j < matrix[currow].size(); j++) {
      if (j == curcolumn) {
        continue;
      }
      if (target >= matrix[currow][j]) {
        if (column[curcolumn][target - matrix[currow][j]]) {
          chk = 1;
          break;
        }
      }
    }
    if (!chk) {
      break;
    }
  }
  if (chk) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
}
