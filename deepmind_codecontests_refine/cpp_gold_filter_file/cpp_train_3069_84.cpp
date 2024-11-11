#include <bits/stdc++.h>
using namespace std;
int main() {
  int white = 0, black = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char a;
      cin >> a;
      if (a == 'Q') white += 9;
      if (a == 'q') black += 9;
      if (a == 'R') white += 5;
      if (a == 'r') black += 5;
      if (a == 'B' || a == 'N') white += 3;
      if (a == 'b' || a == 'n') black += 3;
      if (a == 'p') black += 1;
      if (a == 'P') white += 1;
    }
  }
  if (black > white) {
    cout << "Black" << endl;
    return 0;
  } else if (black < white) {
    cout << "White" << endl;
    return 0;
  } else
    cout << "Draw";
  return 0;
}
