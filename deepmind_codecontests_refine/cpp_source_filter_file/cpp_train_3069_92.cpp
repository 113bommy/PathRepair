#include <bits/stdc++.h>
using namespace std;
int main() {
  int w = 0, b = 0;
  string cad;
  while (cin >> cad) {
    for (int i = 0; i < cad.size(); i++) {
      if (cad[i] == 'Q') w += 9;
      if (cad[i] == 'R') w += 5;
      if (cad[i] == 'B') w += 3;
      if (cad[i] == 'K') w += 3;
      if (cad[i] == 'P') w += 1;
      if (cad[i] == 'q') b += 9;
      if (cad[i] == 'r') b += 5;
      if (cad[i] == 'b') b += 3;
      if (cad[i] == 'k') b += 3;
      if (cad[i] == 'p') b += 1;
    }
  }
  if (w == b)
    cout << "Draw" << endl;
  else if (w > b)
    cout << "White" << endl;
  else
    cout << "Black" << endl;
  return 0;
}
