#include <bits/stdc++.h>
using namespace std;
int n;
string a() {
  if (n % 10 == 1)
    return "-one";
  else if (n % 10 == 2)
    return "-two";
  else if (n % 10 == 3)
    return "-three";
  else if (n % 10 == 4)
    return "-four";
  else if (n % 10 == 5)
    return "-five";
  else if (n % 10 == 6)
    return "-six";
  else if (n % 10 == 7)
    return "-seven";
  else if (n % 10 == 8)
    return "-eight";
  else if (n % 10 == 9)
    return "-nine";
  else if (n % 10 == 0)
    return "";
}
int main() {
  cin >> n;
  if (n / 10 == 0) {
    if (n % 10 == 1)
      cout << "one";
    else if (n % 10 == 2)
      cout << "two";
    else if (n % 10 == 3)
      cout << "three";
    else if (n % 10 == 4)
      cout << "four";
    else if (n % 10 == 5)
      cout << "five";
    else if (n % 10 == 6)
      cout << "six";
    else if (n % 10 == 7)
      cout << "seven";
    else if (n % 10 == 8)
      cout << "eight";
    else if (n % 10 == 9)
      cout << "nine";
    else if (n % 10 == 0)
      cout << "zero";
  } else if (n / 10 == 1) {
    if (n % 10 == 1)
      cout << "eleven";
    else if (n % 10 == 2)
      cout << "twelve";
    else if (n % 10 == 3)
      cout << "thirteen";
    else if (n % 10 == 4)
      cout << "fourteen";
    else if (n % 10 == 5)
      cout << "fifteen";
    else if (n % 10 == 6)
      cout << "sixteen";
    else if (n % 10 == 7)
      cout << "seventeen";
    else if (n % 10 == 8)
      cout << "eighteen";
    else if (n % 10 == 9)
      cout << "nineteen";
    else if (n % 10 == 0)
      cout << "ten";
  } else if (n / 10 == 2)
    cout << "twenty" << a();
  else if (n / 10 == 3)
    cout << "thirty" << a();
  else if (n / 10 == 4)
    cout << "forty" << a();
  else if (n / 10 == 5)
    cout << "fifty" << a();
  else if (n / 10 == 6)
    cout << "sixty" << a();
  else if (n / 10 == 7)
    cout << "seventy" << a();
  else if (n / 10 == 8)
    cout << "eighty" << a();
  else if (n / 10 == 9)
    cout << "ninety" << a();
  return 0;
}
