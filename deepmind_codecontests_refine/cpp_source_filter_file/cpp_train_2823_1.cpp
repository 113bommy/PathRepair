#include <bits/stdc++.h>
using namespace std;
int nton(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  switch (c) {
    case 'T':
      return 10;
      break;
    case 'J':
      return 11;
      break;
    case 'Q':
      return 12;
      break;
    case 'K':
      return 13;
      break;
    case 'A':
      return 14;
      break;
  }
  return -1;
}
int main() {
  char k;
  string p1, p2;
  cin >> k >> p1 >> p2;
  if (p1[1] == k) {
    if (p2[1] == k) {
      if (nton(p1[0]) > nton(p2[0])) {
        cout << "YES";
      } else {
        cout << "NO";
      }
    } else {
      cout << "YES";
    }
  } else if (p1[1] == p2[1]) {
    if (nton(p1[0]) > nton(p1[1])) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }
}
