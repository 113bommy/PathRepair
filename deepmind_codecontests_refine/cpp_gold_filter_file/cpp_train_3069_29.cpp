#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int cB = 0, cW = 0;
  for (int i = 0; i < 8; i++) {
    cin >> s;
    for (int j = 0; j < 8; j++) {
      if (s.substr(j, 1) == "Q")
        cW += 9;
      else if (s.substr(j, 1) == "R")
        cW += 5;
      else if (s.substr(j, 1) == "B")
        cW += 3;
      else if (s.substr(j, 1) == "N")
        cW += 3;
      else if (s.substr(j, 1) == "P")
        cW += 1;
      else if (s.substr(j, 1) == "q")
        cB += 9;
      else if (s.substr(j, 1) == "r")
        cB += 5;
      else if (s.substr(j, 1) == "b")
        cB += 3;
      else if (s.substr(j, 1) == "n")
        cB += 3;
      else if (s.substr(j, 1) == "p")
        cB += 1;
    }
  }
  if (cW > cB)
    cout << "White" << endl;
  else if (cB > cW)
    cout << "Black" << endl;
  else
    cout << "Draw" << endl;
}
