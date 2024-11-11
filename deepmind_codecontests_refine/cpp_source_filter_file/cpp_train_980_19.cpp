#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  int p1 = 0;
  int p2 = 0;
  for (int i = 0; i < a.size(); i += 2) {
    string player1 = a.substr(i, 2);
    string player2 = b.substr(i, 2);
    if (player1 == "[]") {
      if (player2 == "8<")
        p2++;
      else if (player2 == "()")
        p1++;
    } else if (player1 == "8<") {
      if (player2 == "[]")
        p1++;
      else if (player2 == "()")
        p2++;
    } else if (player1 == "()") {
      if (player2 == "8<")
        p1++;
      else if (player2 == "[]")
        p2++;
    }
  }
  if (p1 > p2) {
    cout << "TEAM 1 WINS";
  } else if (p2 > p1)
    cout << "TEAM 2 WINS";
  else
    "TIE";
}
