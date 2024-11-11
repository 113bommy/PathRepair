#include <bits/stdc++.h>
using namespace std;
void once(int a) {
  switch (a) {
    case 1:
      cout << "one";
      break;
    case 2:
      cout << "two";
      break;
    case 3:
      cout << "three";
      break;
    case 4:
      cout << "four";
      break;
    case 5:
      cout << "five";
      break;
    case 6:
      cout << "six";
      break;
    case 7:
      cout << "seven";
      break;
    case 8:
      cout << "eight";
      break;
    case 9:
      cout << "nine";
      break;
  }
}
int tens(int a, int b) {
  int flag = 0;
  switch (a) {
    case 1:
      flag = 1;
      switch (b) {
        case 0:
          cout << "ten";
          break;
        case 1:
          cout << "eleven";
          break;
        case 2:
          cout << "twelve";
          break;
        case 3:
          cout << "thirteen";
          break;
        case 4:
          cout << "fourteen";
          break;
        case 5:
          cout << "fifteen";
          break;
        case 6:
          cout << "sixteen";
          break;
        case 7:
          cout << "seventeen";
          break;
        case 8:
          cout << "eighteen";
          break;
        case 9:
          cout << "nineteen";
          break;
      }
      break;
    case 2:
      cout << "twenty";
      break;
    case 3:
      cout << "thirty";
      break;
    case 4:
      cout << "fourty";
      break;
    case 5:
      cout << "fifty";
      break;
    case 6:
      cout << "sixty";
      break;
    case 7:
      cout << "seventy";
      break;
    case 8:
      cout << "eighty";
      break;
    case 9:
      cout << "ninety";
      break;
  }
  return (flag);
}
int main() {
  int nf = 0;
  int n, a[3], i = 0, flag = 0;
  cin >> n;
  int nn = n;
  if (n == 0)
    cout << "zero";
  else {
    while (n != 0) {
      a[i++] = n % 10;
      n = n / 10;
    }
    for (i = i - 1; i >= 0; --i) {
      if (i == 0 && flag == 0) once(a[0]);
      if (i == 1) flag = tens(a[1], a[0]);
      if (!nf && nn % 10 != 0 && nn > 20) {
        cout << "-";
        nf = 1;
      }
    }
  }
}
