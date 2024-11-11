#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int C = 1;
  cin >> s;
  if (s[0] == '0') {
    C *= 2;
  } else if (s[0] == '1') {
    C *= 7;
  } else if (s[0] == '2') {
    C *= 2;
  } else if (s[0] == '3') {
    C *= 3;
  } else if (s[0] == '4') {
    C *= 3;
  } else if (s[0] == '5') {
    C *= 4;
  } else if (s[0] == '6') {
    C *= 2;
  } else if (s[0] == '7') {
    C *= 5;
  } else if (s[0] == '8') {
    C *= 1;
  } else if (s[0] == '9') {
    C *= 2;
  }
  if (s[1] == '0') {
    C *= 2;
  } else if (s[1] == '1') {
    C *= 7;
  } else if (s[1] == '2') {
    C *= 2;
  } else if (s[1] == '3') {
    C *= 3;
  } else if (s[1] == '4') {
    C *= 3;
  } else if (s[1] == '5') {
    C *= 4;
  } else if (s[1] == '6') {
    C *= 2;
  } else if (s[1] == '7') {
    C *= 5;
  } else if (s[1] == '8') {
    C *= 1;
  } else if (s[1] == '9') {
    C *= 2;
  }
  cout << C;
  return 0;
}
