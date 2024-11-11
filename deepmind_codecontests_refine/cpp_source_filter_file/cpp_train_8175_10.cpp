#include <bits/stdc++.h>
using namespace std;
bool notgood(char a, char b) {
  switch (a) {
    case 'a':
    case 'B':
    case 'C':
    case 'c':
    case 'D':
    case 'E':
    case 'e':
    case 'F':
    case 'f':
    case 'G':
    case 'g':
    case 'h':
    case 'i':
    case 'J':
    case 'j':
    case 'K':
    case 'k':
    case 'L':
    case 'l':
    case 'm':
    case 'N':
    case 'n':
    case 'P':
    case 'Q':
    case 'R':
    case 'r':
    case 'S':
    case 's':
    case 't':
    case 'u':
    case 'y':
    case 'Z':
    case 'z':
      return false;
      break;
  }
  if (a == 'b' && b == 'd')
    return true;
  else if (a == 'd' && b == 'b')
    return true;
  else if (a == 'q' && b == 'p')
    return true;
  else if (a == 'p' && b == 'q')
    return true;
  else if (a == 'b' || a == 'd' || a == 'q' || a == 'p') {
    return false;
  } else {
    return true;
  }
}
int main() {
  string a;
  cin >> a;
  for (int i{}; i < a.length() / 2; ++i) {
    if (!notgood(a[i], a[a.length() - 1 - i])) {
      cout << "NIE\n";
      return 0;
    }
  }
  if (a.length() % 2) {
    if (!notgood(a[a.length() / 2], a[a.length() / 2])) {
      cout << "NIE\n";
      return 0;
    }
  }
  cout << "TAK\n";
}
