#include <bits/stdc++.h>
using namespace std;
int main() {
  string one;
  string two;
  string three;
  cin >> one >> two >> three;
  if (one.compare(two) == 0 && one.compare(three) == 0) {
    cout << "?";
  } else if (one == "paper" && two == "rock" && three == "rock") {
    cout << "F";
  } else if (one == "scissors" && two == "paper" && three == "paper") {
    cout << "F";
  } else if (one == "rock" && two == "scissors" && three == "scissors") {
    cout << "F";
  } else if (two == "paper" && one == "rock" && three == "rock") {
    cout << "S";
  } else if (two == "scissors" && one == "paper" && three == "paper") {
    cout << "S";
  } else if (two == "rock" && one == "scissors" && three == "scissors") {
    cout << "S";
  } else if (three == "paper" && two == "rock" && one == "rock") {
    cout << "M";
  } else if (three == "scissors" && two == "paper" && one == "paper") {
    cout << "M";
  } else if (three == "rock" && two == "scissors" && one == "scissors") {
    cout << "M";
  } else {
    cout << "?";
  }
}
