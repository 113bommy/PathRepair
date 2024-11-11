#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  string one, two, three;
  cin >> one >> two >> three;
  if ((one == two && two == three) ||
      (one != two && two != three && one != three)) {
    cout << "?";
  } else if (two == three) {
    if ((one == "paper" && two == "rock") ||
        (one == "scissors" && two == "paper") ||
        (one == "rock" && two == "scissors")) {
      cout << "F";
    } else if ((one == "paper" && two == "scissors") ||
               (one == "rock" && two == "paper") ||
               (one == "scissors" && two == "rock")) {
      cout << "?";
    }
  } else if (one == two) {
    if ((three == "paper" && two == "rock") ||
        (three == "scissors" && two == "paper") ||
        (three == "rock" && two == "scissors")) {
      cout << "S";
    } else if ((three == "paper" && two == "scissors") ||
               (three == "rock" && two == "paper") ||
               (three == "scissors" && two == "rock")) {
      cout << "?";
    }
  } else if (one == three) {
    if ((two == "paper" && one == "rock") ||
        (two == "scissors" && one == "paper") ||
        (two == "rock" && one == "scissors")) {
      cout << "M";
    } else if ((two == "paper" && one == "scissors") ||
               (two == "rock" && one == "paper") ||
               (two == "scissors" && one == "rock")) {
      cout << "?";
    }
  }
  return 0;
}
