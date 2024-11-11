#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int s;
  cin >> s;
  string n = to_string(s);
  if (s == 0) {
    cout << "zero";
    return 0;
  }
  if (s == 10) {
    cout << "ten";
    return 0;
  }
  if (s == 11) {
    cout << "eleven";
    return 0;
  }
  if (s == 12) {
    cout << "twelve";
    return 0;
  }
  if (s == 13) {
    cout << "thirteen";
    return 0;
  }
  if (s == 14) {
    cout << "fourteen";
    return 0;
  }
  if (s == 15) {
    cout << "fifteen";
    return 0;
  }
  if (s == 16) {
    cout << "sixteen";
    return 0;
  }
  if (s == 17) {
    cout << "seventeen";
    return 0;
  }
  if (s == 18) {
    cout << "eighteen";
    return 0;
  }
  if (s == 19) {
    cout << "nineteen";
    return 0;
  }
  if (n.size() > 1) {
    if (n[0] == '2') {
      if (n[1] == '0') {
        cout << "twenty";
        return 0;
      }
      cout << "twenty-";
    }
    if (n[0] == '3') {
      if (n[1] == '0') {
        cout << "thirty";
        return 0;
      }
      cout << "thirty-";
    }
    if (n[0] == '4') {
      if (n[1] == '0') {
        cout << "forty";
        return 0;
      }
      cout << "forty-";
    }
    if (n[0] == '5') {
      if (n[1] == '0') {
        cout << "fifty";
        return 0;
      }
      cout << "fifty-";
    }
    if (n[0] == '6') {
      if (n[1] == '0') {
        cout << "sixty";
        return 0;
      }
      cout << "sixty-";
    }
    if (n[0] == '7') {
      if (n[1] == '0') {
        cout << "seventy";
        return 0;
      }
      cout << "seventy-";
    }
    if (n[0] == '8') {
      if (n[1] == '0') {
        cout << "eighty";
        return 0;
      }
      cout << "eighty-";
    }
    if (n[0] == '9') {
      if (n[1] == '0') {
        cout << "ninety";
        return 0;
      }
      cout << "ninety-";
    }
  }
  if (n[1] == '1' || s == 1) {
    cout << "one";
    return 0;
  }
  if (n[1] == '2' || s == 2) {
    cout << "two";
    return 0;
  }
  if (n[1] == '3' || s == 3) {
    cout << "three";
    return 0;
  }
  if (n[1] == '4' || s == 4) {
    cout << "four";
    return 0;
  }
  if (n[1] == '5' || s == 5) {
    cout << "five";
    return 0;
  }
  if (n[1] == '6' || s == 6) {
    cout << "six";
    return 0;
  }
  if (n[1] == '7' || s == 7) {
    cout << "seven";
    return 0;
  }
  if (n[1] == '8' || s == 8) {
    cout << "eight";
    return 0;
  }
  if (n[1] == '9' || s == 9) {
    cout << "nine";
    return 0;
  }
}
