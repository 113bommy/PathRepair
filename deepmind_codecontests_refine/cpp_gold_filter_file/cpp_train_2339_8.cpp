#include <bits/stdc++.h>
using namespace std;
int main() {
  string f, m, s;
  cin >> f;
  cin >> m;
  cin >> s;
  if ((f == "rock" && m == "scissors" && s == "scissors") ||
      (f == "paper" && m == "rock" && s == "rock") ||
      (f == "scissors" && m == "paper" && s == "paper")) {
    cout << "F" << endl;
  } else if ((m == "rock" && f == "scissors" && s == "scissors") ||
             (m == "paper" && f == "rock" && s == "rock") ||
             (m == "scissors" && f == "paper" && s == "paper")) {
    cout << "M" << endl;
  } else if ((s == "rock" && f == "scissors" && m == "scissors") ||
             (s == "paper" && f == "rock" && m == "rock") ||
             (s == "scissors" && f == "paper" && m == "paper")) {
    cout << "S" << endl;
  } else {
    cout << "?" << endl;
  }
  return 0;
}
