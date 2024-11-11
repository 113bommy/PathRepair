#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  if (n <= 19) {
    x = n;
    if (x == 0)
      cout << "zero";
    else if (x == 1)
      cout << "one";
    else if (x == 2)
      cout << "two";
    else if (x == 3)
      cout << "three";
    else if (x == 4)
      cout << "four";
    else if (x == 5)
      cout << "five";
    else if (x == 6)
      cout << "six";
    else if (x == 7)
      cout << "seven";
    else if (x == 8)
      cout << "eight";
    else if (x == 9)
      cout << "nine";
    else if (x == 10)
      cout << "ten";
    else if (x == 11)
      cout << "eleven";
    else if (x == 12)
      cout << "twelve";
    else if (x == 13)
      cout << "thirteen";
    else if (x == 14)
      cout << "fourteen";
    else if (x == 15)
      cout << "fifteen";
    else if (x == 16)
      cout << "sixteen";
    else if (x == 17)
      cout << "seventeen";
    else if (x == 18)
      cout << "eighteen";
    else if (x == 19)
      cout << "nineteen";
  } else {
    x = n / 10;
    if (x == 2)
      cout << "twenty";
    else if (x == 3)
      cout << "thirty";
    else if (x == 4)
      cout << "forty";
    else if (x == 5)
      cout << "fifty";
    else if (x == 6)
      cout << "sixty";
    else if (x == 7)
      cout << "seventy";
    else if (x == 8)
      cout << "eighty";
    else if (x == 9)
      cout << "ninety";
    if (n % 10 != 0) {
      x = n % 10;
      cout << "-";
      if (x == 1)
        cout << "one";
      else if (x == 2)
        cout << "two";
      else if (x == 3)
        cout << "three";
      else if (x == 4)
        cout << "four";
      else if (x == 5)
        cout << "five";
      else if (x == 6)
        cout << "six";
      else if (x == 7)
        cout << "seven";
      else if (x == 8)
        cout << "eight";
      else if (x == 9)
        cout << "nine";
    }
  }
  return 0;
}
