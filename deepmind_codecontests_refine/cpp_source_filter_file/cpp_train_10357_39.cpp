#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    if (n <= 19) {
      if (n == 0)
        cout << "zero" << endl;
      else if (n == 1)
        cout << "one" << endl;
      else if (n == 2)
        cout << "two" << endl;
      else if (n == 3)
        cout << "three" << endl;
      else if (n == 4)
        cout << "four" << endl;
      else if (n == 5)
        cout << "five" << endl;
      else if (n == 6)
        cout << "six" << endl;
      else if (n == 7)
        cout << "seven" << endl;
      else if (n == 8)
        cout << "eight" << endl;
      else if (n == 9)
        cout << "nine" << endl;
      else if (n == 10)
        cout << "ten" << endl;
      else if (n == 11)
        cout << "eleven" << endl;
      else if (n == 12)
        cout << "twelve" << endl;
      else if (n == 13)
        cout << "thirteen" << endl;
      else if (n == 14)
        cout << "fourteen" << endl;
      else if (n == 15)
        cout << "fifteen" << endl;
      else if (n == 16)
        cout << "sixteen" << endl;
      else if (n == 17)
        cout << "seventeen" << endl;
      else if (n == 18)
        cout << "eighteen" << endl;
      else
        cout << "nineteen" << endl;
    } else {
      if (n % 10 == 0) {
        if (n / 10 == 2)
          cout << "twenty" << endl;
        else if (n / 10 == 3)
          cout << "thirty" << endl;
        else if (n / 10 == 4)
          cout << "forty" << endl;
        else if (n / 10 == 5)
          cout << "fifty" << endl;
        else if (n / 10 == 6)
          cout << "sixty" << endl;
        else if (n / 10 == 7)
          cout << "seventy" << endl;
        else if (n / 10 == 8)
          cout << "eighty" << endl;
        else
          cout << "ninety" << endl;
      } else {
        if (n / 10 == 2) {
          cout << "twenty-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        } else if (n / 10 == 3) {
          cout << "thirty-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        } else if (n / 10 == 4) {
          cout << "forty-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        } else if (n / 10 == 5) {
          cout << "fifty-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        } else if (n / 10 == 6) {
          cout << "sixty-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        } else if (n / 10 == 7) {
          cout << "seventeen-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        } else if (n / 10 == 8) {
          cout << "eighty-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        } else {
          cout << "nineteen-";
          if (n % 10 == 1)
            cout << "one" << endl;
          else if (n % 10 == 2)
            cout << "two" << endl;
          else if (n % 10 == 3)
            cout << "three" << endl;
          else if (n % 10 == 4)
            cout << "four" << endl;
          else if (n % 10 == 5)
            cout << "five" << endl;
          else if (n % 10 == 6)
            cout << "six" << endl;
          else if (n % 10 == 7)
            cout << "seven" << endl;
          else if (n % 10 == 8)
            cout << "eight" << endl;
          else if (n % 10 == 9)
            cout << "nine" << endl;
        }
      }
    }
  }
  return 0;
}
