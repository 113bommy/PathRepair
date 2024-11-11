#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[] = {"rock", "paper", "scissors"};
  string a, b, c;
  getline(cin, a);
  getline(cin, b);
  getline(cin, c);
  if ((a == s[0] && b == s[1] && c == s[2]) ||
      (a == s[0] && b == s[2] && c == s[1]) ||
      (a == s[1] && b == s[0] && c == s[2]) ||
      (a == s[1] && b == s[2] && c == s[0]) ||
      (a == s[2] && b == s[1] && c == s[0]) ||
      (a == s[2] && b == s[0] && c == s[1]))
    cout << "?" << endl;
  else if (a == s[0] && b == s[0] || a == s[0] && c == s[0] ||
           b == s[0] && c == s[0]) {
    if (c != s[0]) {
      if (c == s[1])
        cout << "S" << endl;
      else
        cout << "?" << endl;
    } else if (b != s[0]) {
      if (b == s[1])
        cout << "M" << endl;
      else
        cout << "?" << endl;
    } else {
      if (a == s[1])
        cout << "F" << endl;
      else
        cout << "?" << endl;
    }
  } else if (a == s[2] && b == s[2] || a == s[2] && c == s[2] ||
             b == s[2] && c == s[2]) {
    if (c != s[2]) {
      if (c == s[0])
        cout << "S" << endl;
      else
        cout << "?" << endl;
    } else if (b != s[2]) {
      if (b == s[0])
        cout << "M" << endl;
      else
        cout << "?" << endl;
    } else {
      if (a == s[0])
        cout << "F" << endl;
      else
        cout << "?" << endl;
    }
  } else if (a == s[1] && b == s[1] || a == s[1] && c == s[1] ||
             b == s[1] && c == s[1]) {
    if (c != s[1]) {
      if (c == s[2])
        cout << "S" << endl;
      else
        cout << "?" << endl;
    } else if (b != s[1]) {
      if (b == s[2])
        cout << "M" << endl;
      else
        cout << "?" << endl;
    } else {
      if (a == s[2])
        cout << "F" << endl;
      else
        cout << "?" << endl;
    }
  } else
    cout << "?" << endl;
}
