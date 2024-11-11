#include <bits/stdc++.h>
using namespace std;
string s1[4];
int main() {
  string w;
  int c = 0, x = 0, max1 = 0;
  for (int i = 1; i <= 3; i++) {
    cin >> s1[i];
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = i + 1; j <= 3; j++) {
      if (s1[i] == s1[j]) {
        c++;
        if (max1 < c) {
          max1 = c;
          w = s1[i];
        }
      }
    }
    c = 0;
  }
  if (max1 == 2 || max1 == 0) {
    cout << "?";
    return 0;
  } else {
    for (int i = 1; i <= 3; i++) {
      if (s1[i] != w) {
        x = i;
        break;
      }
    }
    if (x == 1 && ((w == "scissoes" && s1[x] == "rock") ||
                   ((w == "paper" && s1[x] == "scissors")) ||
                   ((w == "rock" && s1[x] == "paper")))) {
      cout << "F";
      return 0;
    }
    if (x == 2 && ((w == "scissors" && s1[x] == "rock") ||
                   ((w == "paper" && s1[x] == "scissors")) ||
                   ((w == "rock" && s1[x] == "paper")))) {
      cout << "M";
      return 0;
    }
    if (x == 3 && ((w == "scissors" && s1[x] == "rock") ||
                   ((w == "paper" && s1[x] == "scissors")) ||
                   ((w == "rock" && s1[x] == "paper")))) {
      cout << "S";
      return 0;
    }
  }
  cout << "?";
}
