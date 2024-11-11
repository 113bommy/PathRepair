#include <bits/stdc++.h>
using namespace std;
int main() {
  string pl1, pl2, pl3;
  int b1, b2, b3;
  map<string, int> play;
  play["rock"] = 1;
  play["paper"] = 2;
  play["scissors"] = 3;
  cin >> pl1 >> pl2 >> pl3;
  b1 = play[pl1];
  b2 = play[pl2];
  b3 = play[pl3];
  if (b1 == 1 && b2 == 3 && b3 == 3 || b1 == 2 && b2 == 1 && b3 == 1 ||
      b1 == 3 && b2 == 2 && b3 == 2)
    cout << "F";
  else if (b2 == 1 && b1 == 3 && b3 == 3 || b2 == 2 && b1 == 1 && b3 == 1 ||
           b2 == 3 && b2 == 2 && b3 == 2)
    cout << "M";
  else if (b3 == 1 && b2 == 3 && b1 == 3 || b3 == 2 && b2 == 1 && b1 == 1 ||
           b3 == 3 && b2 == 2 && b1 == 2)
    cout << "S";
  else
    cout << "?";
  return 0;
}
