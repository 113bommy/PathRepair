#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch;
  int i, j, k, l, wht = 0, blk = 0;
  for (i = 1; i <= 72; i++) {
    cin >> ch;
    if (ch != '/n') {
      if (ch == 'Q') wht += 9;
      if (ch == 'R') wht += 5;
      if (ch == 'B' || ch == 'N') wht += 3;
      if (ch == 'P') wht += 1;
      if (ch == 'q') blk += 9;
      if (ch == 'r') blk += 5;
      if (ch == 'b' || ch == 'n') blk += 3;
      if (ch == 'p') blk += 1;
    }
  }
  if (wht > blk)
    cout << "White";
  else if (wht < blk)
    cout << "Black";
  else
    cout << "Draw";
  return 0;
}
