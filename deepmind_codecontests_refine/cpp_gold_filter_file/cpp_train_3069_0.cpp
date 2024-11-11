#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int w = 0, b = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char a;
      cin >> a;
      if (a == '.') continue;
      if (int(a) < 97) {
        if (a == 'K') continue;
        if (a == 'Q') w += 9;
        if (a == 'R') w += 5;
        if (a == 'B' or a == 'N') w += 3;
        if (a == 'P') w++;
      } else {
        if (a == 'k') continue;
        if (a == 'q') b += 9;
        if (a == 'r') b += 5;
        if (a == 'b' or a == 'n') b += 3;
        if (a == 'p') b++;
      }
    }
  }
  if (w > b)
    cout << "White" << endl;
  else if (w == b)
    cout << "Draw" << endl;
  else
    cout << "Black" << endl;
  return 0;
}
