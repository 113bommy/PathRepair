#include <bits/stdc++.h>
using namespace std;
int check(char a) {
  switch (a) {
    case '1':
      return 7;
      break;
    case '2':
      return 2;
      break;
    case '3':
      return 3;
      break;
    case '4':
      return 3;
      break;
    case '5':
      return 4;
      break;
    case '6':
      return 2;
      break;
    case '7':
      return 5;
      break;
    case '8':
      return 1;
      break;
    case '9':
      return 2;
      break;
    case '0':
      return 2;
      break;
  }
}
int main() {
  int x, y;
  string a;
  cin >> a;
  x = check(a[0]);
  y = check(a[1]);
  cout << x * y;
}
