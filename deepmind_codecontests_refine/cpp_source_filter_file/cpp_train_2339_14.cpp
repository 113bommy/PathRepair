#include <bits/stdc++.h>
using namespace std;
string f, m, s;
int main() {
  cin >> f >> m >> s;
  if (f == "rock" && m == "scissors" && s == "scissors") {
    cout << "F";
    return 0;
  }
  if (f == "scissors" && m == "paper" && s == "paper") {
    cout << "F";
    return 0;
  }
  if (f == "paper" && m == "rock" && s == "rock") {
    cout << "F";
    return 0;
  }
  if (m == "rock" && f == "scissors" && s == "scissors") {
    cout << "M";
    return 0;
  }
  if (m == "scissors" && f == "paper" && s == "paper") {
    cout << "M";
    return 0;
  }
  if (m == "paper" && f == "rock" && s == "rock") {
    cout << "M";
    return 0;
  }
  if (s == "rock" && f == "scissors" && s == "scissors") {
    cout << "S";
    return 0;
  }
  if (s == "scissors" && f == "paper" && s == "paper") {
    cout << "S";
    return 0;
  }
  if (s == "paper" && f == "rock" && s == "rock") {
    cout << "S";
    return 0;
  }
  cout << "?";
  return 0;
}
