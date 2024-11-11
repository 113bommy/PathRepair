#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n <= 9) {
    if (n == 0)
      cout << "zero";
    else if (n == 1)
      cout << "one";
    else if (n == 2)
      cout << "two";
    else if (n == 3)
      cout << "three";
    else if (n == 4)
      cout << "four";
    else if (n == 5)
      cout << "five";
    else if (n == 6)
      cout << "six";
    else if (n == 7)
      cout << "seven";
    else if (n == 8)
      cout << "eight";
    else if (n == 9)
      cout << "nine";
  } else if (n >= 10 && n <= 19) {
    if (n == 10)
      cout << "ten";
    else if (n == 11)
      cout << "eleven";
    else if (n == 12)
      cout << "twelve";
    else if (n == 13)
      cout << "thirteen";
    else if (n == 14)
      cout << "fourteen";
    else if (n == 15)
      cout << "fifteen";
    else if (n == 16)
      cout << "sixteen";
    else if (n == 17)
      cout << "seventeen";
    else if (n == 18)
      cout << "eighteen";
    else if (n == 19)
      cout << "nineteen";
  } else {
    int a = n % 10;
    int b = n / 10;
    if (a == 0) {
      if (b == 2)
        cout << "twenty";
      else if (b == 3)
        cout << "thirty";
      else if (b == 4)
        cout << "forty";
      else if (b == 5)
        cout << "fifty";
      else if (b == 6)
        cout << "sixty";
      else if (b == 7)
        cout << "seventy";
      else if (b == 8)
        cout << "eighty";
      else if (b == 9)
        cout << "ninety";
    } else {
      if (b == 2)
        cout << "twenty";
      else if (b == 3)
        cout << "thrirty";
      else if (b == 4)
        cout << "forty";
      else if (b == 5)
        cout << "fifty";
      else if (b == 6)
        cout << "sixty";
      else if (b == 7)
        cout << "seventy";
      else if (b == 8)
        cout << "eighty";
      else if (b == 9)
        cout << "ninety";
      cout << "-";
      if (a == 1)
        cout << "one";
      else if (a == 2)
        cout << "two";
      else if (a == 3)
        cout << "three";
      else if (a == 4)
        cout << "four";
      else if (a == 5)
        cout << "five";
      else if (a == 6)
        cout << "six";
      else if (a == 7)
        cout << "seven";
      else if (a == 8)
        cout << "eight";
      else if (a == 9)
        cout << "nine";
    }
  }
  return 0;
}
