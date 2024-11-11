#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  string btr;
  cin >> btr;
  string ctr;
  cin >> ctr;
  if ((str == "rock" && btr == "scissors" && ctr == "scissors") ||
      (str == "paper" && btr == "rock" && ctr == "rock") ||
      (str == "scissors" && btr == "paper" && ctr == "paper")) {
    cout << "F" << endl;
    return 0;
  } else if ((btr == "rock" && str == " scissors" && ctr == "scissors") ||
             (btr == "paper" && ctr == "rock" && str == "rock") ||
             (btr == "scissors" && ctr == "paper" && str == "paper")) {
    cout << "M" << endl;
    return 0;
  } else if ((ctr == "rock" && str == "scissors" && btr == "scissors") ||
             (ctr == "paper" && btr == "rock" && str == "rock") ||
             (ctr == "scissors" && btr == "paper" && str == "paper")) {
    cout << "S" << endl;
    return 0;
  } else {
    cout << "?" << endl;
    return 0;
  }
}
