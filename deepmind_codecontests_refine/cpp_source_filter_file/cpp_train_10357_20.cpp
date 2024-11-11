#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = n % 10;
  if (k == 1)
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
  else if (n == 0)
    cout << "zero";
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
  else {
    n = n / 10;
    if (n == 1) cout << "ten";
    if (n == 2) cout << "twenty";
    if (n == 3) cout << "thirty";
    if (n == 4) cout << "forty";
    if (n == 5) cout << "fifty";
    if (n == 6) cout << "sixty";
    if (n == 7) cout << "seventy";
    if (n == 8) cout << "eighty";
    if (n == 9) cout << "ninety";
    if (k == 1) cout << "-one";
    if (k == 2) cout << "-two";
    if (k == 3) cout << "-three";
    if (k == 4) cout << "-four";
    if (k == 5) cout << "-five";
    if (k == 6) cout << "-six";
    if (k == 7) cout << "-seven";
    if (k == 8) cout << "-eight";
    if (k == 9) cout << "-nine";
  }
  return 0;
}
