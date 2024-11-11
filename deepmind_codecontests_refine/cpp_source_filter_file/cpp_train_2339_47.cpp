#include <bits/stdc++.h>
using namespace std;
int main() {
  string f, m, s;
  cin >> f >> m >> s;
  if (f == "scissors" && m == "paper" && s == "paper")
    cout << "F";
  else if (f == "paper" && m == "rock" && s == "rock")
    cout << "F";
  else if (f == "rock" && m == "scissors" && s == "scissor")
    cout << "F";
  else if (m == "paper" && f == "rock" && s == "rock")
    cout << "M";
  else if (m == "rock" && f == "scissors" && s == "scissors")
    cout << "M";
  else if (m == "scissors" && f == "paper" && s == "paper")
    cout << "M";
  else if (s == "paper" && f == "rock" && m == "rock")
    cout << "S";
  else if (s == "rock" && f == "scissors" && m == "scissors")
    cout << "S";
  else if (s == "scissors" && f == "paper" && m == "paper")
    cout << "S";
  else {
    cout << "?";
  }
}
