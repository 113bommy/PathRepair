#include <bits/stdc++.h>
using namespace std;
int num(char a, bool m = false) {
  if (m == false) cout << '-';
  switch (a) {
    case '0':
      cout << "zero";
      return 0;
    case '1':
      cout << "one";
      return 0;
    case '2':
      cout << "two";
      return 0;
    case '3':
      cout << "three";
      return 0;
    case '4':
      cout << "four";
      return 0;
    case '5':
      cout << "five";
      return 0;
    case '6':
      cout << "six";
      return 0;
    case '7':
      cout << "seven";
      return 0;
    case '8':
      cout << "eight";
      return 0;
    case '9':
      cout << "nine";
      return 0;
  }
}
int main() {
  string a;
  cin >> a;
  if (a.size() == 2) switch (a[0]) {
      case '1':
        switch (a[1]) {
          case '0':
            cout << "ten";
            return 0;
          case '1':
            cout << "eleven";
            return 0;
          case '2':
            cout << "twelve";
            return 0;
          case '3':
            cout << "thirteen";
            return 0;
          case '4':
            cout << "fourteen";
            return 0;
          case '5':
            cout << "fifteen";
            return 0;
          case '6':
            cout << "sixteen";
            return 0;
          case '7':
            cout << "seventeen";
            return 0;
          case '8':
            cout << "eighteen";
            return 0;
          case '9':
            cout << "nineteen";
            return 0;
        }
        break;
      case '2':
        cout << "twenty";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
        break;
      case '3':
        cout << "thirty";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
        break;
      case '4':
        cout << "forty";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
        break;
      case '5':
        cout << "fifty";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
        break;
      case '6':
        cout << "sixty";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
        break;
      case '7':
        cout << "seventy";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
        break;
      case '8':
        cout << "eighty";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
        break;
      case '9':
        cout << "ninety";
        if (a[1] == '0')
          return 0;
        else
          num(a[1]);
    }
  else
    num(a[0], true);
}
