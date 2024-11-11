#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, l = 0, r = 0, ans = 1;
  string a, b, c;
  cin >> a >> b >> c;
  if (a == "rock" && b == "scissors" && c == "scissors") {
    cout << "F";
    return 0;
  }
  if (a == "scissors" && b == "paper" && c == "paper") {
    cout << "F";
    return 0;
  }
  if (a == "paper" && b == "rock" && c == "rock") {
    cout << "F";
    return 0;
  }
  if (b == "rock" && a == "scissors" && c == "scissors") {
    cout << "M";
    return 0;
  }
  if (b == "scissors" && a == "paper" && c == "paper") {
    cout << "M";
    return 0;
  }
  if (b == "paper" && a == "rock" && c == "rock") {
    cout << "M";
    return 0;
  }
  if (c == "rock" && a == "scissors" && b == "scissors") {
    cout << "S";
    return 0;
  }
  if (c == "scissors" && b == "paper" && a == "paper") {
    cout << "S";
    return 0;
  }
  if (c == "paper" && b == "rock" && a == "rock") {
    cout << "S";
    return 0;
  }
  cout << "?";
  return 0;
}
