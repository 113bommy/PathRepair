#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int sum = 0, i = 0, a, b, c;
  while (s[i] != '+') {
    sum++;
    i++;
  }
  a = sum;
  sum = 0;
  i++;
  while (s[i] != '=') {
    sum++;
    i++;
  }
  b = sum;
  sum = 0;
  i++;
  while (s[i] != '\0') {
    sum++;
    i++;
  }
  c = sum;
  if (a + b == c) {
    cout << s;
    return 0;
  }
  if (abs(c - a - b) > 2) {
    cout << "Impossible";
    return 0;
  }
  if (c > (a + b)) {
    c -= 1;
    a += 1;
    if (a + b == c) {
      for (int i = 0; i < a; i++) {
        cout << "|";
      }
      cout << "+";
      for (int i = 0; i < b; i++) {
        cout << "|";
      }
      cout << "=";
      for (int i = 0; i < c; i++) {
        cout << "|";
      }
    } else {
      cout << "Impossible";
    }
    return 0;
  } else {
    if (a >= b) {
      c += 1;
      a -= 1;
      if (a + b == c) {
        for (int i = 0; i < a; i++) {
          cout << "|";
        }
        cout << "+";
        for (int i = 0; i < b; i++) {
          cout << "|";
        }
        cout << "=";
        for (int i = 0; i < c; i++) {
          cout << "|";
        }
      } else {
        cout << "Impossible";
      }
    } else if (b > a) {
      c += 1;
      b -= 1;
      if (a + b == c) {
        for (int i = 0; i < a; i++) {
          cout << "|";
        }
        cout << "+";
        for (int i = 0; i < b; i++) {
          cout << "|";
        }
        cout << "=";
        for (int i = 0; i < c; i++) {
          cout << "|";
        }
      } else {
        cout << "Impossible";
      }
    } else {
      cout << "Impossible";
    }
    return 0;
  }
  return 0;
}
