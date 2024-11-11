#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (a == "rock" && b == "scissor" && c == "scissor") {
    cout << "F";
  } else if (a == "scissor" && b == "paper" && c == "paper") {
    cout << "F";
  } else if (a == "paper" && b == "rock" && c == "rock") {
    cout << "F";
  } else if (a == "scissor" && b == "rock" && c == "scissor") {
    cout << "M";
  } else if (a == "paper" && b == "scissor" && c == "paper") {
    cout << "M";
  } else if (a == "rock" && b == "paper" && c == "rock") {
    cout << "M";
  } else if (a == "scissor" && b == "scissor" && c == "rock") {
    cout << "S";
  } else if (a == "paper" && b == "paper" && c == "scissor") {
    cout << "S";
  } else if (a == "rock" && b == "rock" && c == "paper") {
    cout << "S";
  } else {
    cout << "?";
  }
  return 0;
}
