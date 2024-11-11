#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, s3;
  cin >> s1;
  cin >> s2;
  cin >> s3;
  if (s1 != s2 && s2 != s3 && s3 != s1)
    cout << "?\n";
  else if (s1 == s2 && s2 == s3 && s3 == s1)
    cout << "?\n";
  else if (s1 == s2) {
    if (s1 == "rock") {
      if (s3 == "paper")
        cout << "S\n";
      else
        cout << "?\n";
    } else if (s1 == "paper") {
      if (s3 == "scissors")
        cout << "S\n";
      else
        cout << "?\n";
    } else if (s1 == "scissors") {
      if (s3 == "rock")
        cout << "S\n";
      else
        cout << "?\n";
    }
  } else if (s1 == s3) {
    if (s1 == "rock") {
      if (s2 == "paper")
        cout << "M\n";
      else
        cout << "?\n";
    } else if (s1 == "paper") {
      if (s2 == "scissors")
        cout << "M\n";
      else
        cout << "?\n";
    } else if (s1 == "scissors") {
      if (s2 == "rock")
        cout << "M\n";
      else
        cout << "?\n";
    }
  } else if (s2 == s3) {
    if (s2 == "rock") {
      if (s1 == "paper")
        cout << "F\n";
      else
        cout << "?\n";
    } else if (s2 == "paper") {
      if (s1 == "scissors")
        cout << "F\n";
      else
        cout << "?\n";
    } else if (s2 == "scissors") {
      if (s1 == "rock")
        cout << "F\n";
      else
        cout << "?\n";
    }
  }
  return 0;
}
