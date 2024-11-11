#include <bits/stdc++.h>
using namespace std;
int k, i, j;
bool ok = true;
int main() {
  cin >> k;
  cout << "+";
  for (i = 1; i <= 24; i++) cout << "-";
  cout << "+\n";
  for (i = 1; i <= 4; i++) {
    cout << "|";
    if (i == 3) {
      if (k >= 3)
        cout << "0.";
      else
        cout << "#.";
      for (j = 2; j <= 11; j++) cout << "..";
    } else {
      for (j = 1; j <= 11; j++) {
        if (i == 1) {
          if (k == 1 && ok) {
            cout << "0.";
            ok = false;
          } else if (k >= 3 * j - 1)
            cout << "0.";
          else
            cout << "#.";
        } else if (i == 2) {
          if (k == 2 && ok) {
            cout << "0.";
            ok = false;
          } else if (k >= 3 * j)
            cout << "0.";
          else
            cout << "#.";
        } else {
          if (k >= 3 * j + 1)
            cout << "0.";
          else
            cout << "#.";
        }
      }
    }
    if (i == 1)
      cout << "|D|";
    else if (i == 2 || i == 4)
      cout << "|.|";
    else
      cout << "..|";
    if (i == 1 || i == 4) cout << ")";
    cout << "\n";
  }
  cout << "+";
  for (i = 1; i <= 24; i++) cout << "-";
  cout << "+";
  return 0;
}
