#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  long long n;
  cin >> n;
  n = n % 4;
  int a = (int)s[0];
  int b = (int)s[2];
  if (a == b) {
    cout << "undefined";
    return 0;
  }
  if (a == 118 && b == 94) {
    cout << "undefined";
    return 0;
  } else if (b == 118 && a == 94) {
    cout << "undefined";
    return 0;
  }
  if (a == 60 & b == 62) {
    cout << "undefined";
    return 0;
  } else if (b == 60 && a == 62) {
    cout << "undefined";
    return 0;
  } else if (a == 118 && b == 60) {
    if (n > 1)
      cout << "ccw";
    else
      cout << "cw";
  } else if (a == 60 && b == 118) {
    if (n > 1)
      cout << "cw";
    else
      cout << "ccw";
  } else if (a == 118 && b == 62) {
    if (n > 1)
      cout << "cw";
    else
      cout << "ccw";
  } else if (a == 62 && b == 118) {
    if (n > 1)
      cout << "ccw";
    else
      cout << "cw";
  } else if (a == 94 && b == 60) {
    if (n > 1)
      cout << "cw";
    else
      cout << "ccw";
  } else if (a == 60 && b == 94) {
    if (n > 1)
      cout << "ccw";
    else
      cout << "cw";
  } else if (a == 94 && b == 62) {
    if (n > 1)
      cout << "ccw";
    else
      cout << "cw";
  } else if (a == 62 && b == 94) {
    if (n > 1)
      cout << "cw";
    else
      cout << "ccw";
  }
}
