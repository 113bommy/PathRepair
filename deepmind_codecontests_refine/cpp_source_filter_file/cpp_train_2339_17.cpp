#include <bits/stdc++.h>
using namespace std;
int main() {
  string f, m, s;
  cin >> f >> m >> s;
  string answer = "?";
  if (f == m && s != m) {
    if (s == "paper" && f == "rock") {
      answer = "S";
    } else if (s == "scissor" && f == "paper") {
      answer = "S";
    } else if (s == "rock" && f == "scissor") {
      answer = "S";
    }
  } else if (s == m && f != m) {
    if (s == "paper" && f == "scissor") {
      answer = "F";
    } else if (s == "scissor" && f == "rock") {
      answer = "F";
    } else if (s == "rock" && f == "paper") {
      answer = "F";
    }
  } else if (f == s && s != m) {
    if (s == "paper" && m == "scissor") {
      answer = "M";
    } else if (s == "scissor" && m == "rock") {
      answer = "M";
    } else if (s == "rock" && m == "paper") {
      answer = "M";
    }
  }
  cout << answer << endl;
}
