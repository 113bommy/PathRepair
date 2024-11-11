#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  string a;
  cin >> a;
  string b;
  cin >> b;
  string c;
  cin >> c;
  if (a == "paper" && b == c && b == "rock")
    cout << "F";
  else if (a == "rock" && b == c && b == "scissors")
    cout << "F";
  else if (a == "scissors" && b == c && b == "paper")
    cout << "F";
  else if (b == "paper" && a == c && c == "rock")
    cout << "M";
  else if (b == "rock" && a == c && c == "scissors")
    cout << "M";
  else if (b == "scissors" && a == c && a == "paper")
    cout << "M";
  else if (c == "paper" && b == a && b == "rock")
    cout << "S";
  else if (c == "rock" && b == a && b == "scissors")
    cout << "S";
  else if (c == "scissors" && b == a && b == "paper")
    cout << "F";
  else
    cout << "?";
}
