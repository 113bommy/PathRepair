#include <bits/stdc++.h>
using namespace std;
int main() {
  string f, m, s;
  cin >> f >> m >> s;
  if (f == "scissor" && m == "paper" && s == "paper")
    cout << "F";
  else if (f == "paper" && m == "rock" && s == "rock")
    cout << "F";
  else if (f == "rock" && m == "scissor" && s == "scissor")
    cout << "F";
  else if (m == "paper" && f == "rock" && s == "rock")
    cout << "M";
  else if (m == "rock" && f == "scissor" && s == "scissor")
    cout << "M";
  else if (m == "scissor" && f == "paper" && s == "paper")
    cout << "M";
  else if (s == "paper" && f == "rock" && m == "rock")
    cout << "S";
  else if (s == "rock" && f == "scissor" && m == "scissor")
    cout << "S";
  else if (s == "scissor" && f == "paper" && m == "paper")
    cout << "S";
  else {
    cout << "?";
  }
}
