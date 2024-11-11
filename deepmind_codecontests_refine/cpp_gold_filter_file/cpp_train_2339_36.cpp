#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (a == "rock" && b == "scissors" && c == "scissors") {
    cout << "F";
  } else if (a == "scissors" && b == "paper" && c == "paper") {
    cout << "F";
  } else if (a == "paper" && b == "rock" && c == "rock") {
    cout << "F";
  } else if (a == "scissors" && b == "rock" && c == "scissors") {
    cout << "M";
  } else if (a == "paper" && b == "scissors" && c == "paper") {
    cout << "M";
  } else if (a == "rock" && b == "paper" && c == "rock") {
    cout << "M";
  } else if (a == "scissors" && b == "scissors" && c == "rock") {
    cout << "S";
  } else if (a == "paper" && b == "paper" && c == "scissors") {
    cout << "S";
  } else if (a == "rock" && b == "rock" && c == "paper") {
    cout << "S";
  } else {
    cout << "?";
  }
  return 0;
}
