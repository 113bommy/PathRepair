#include <bits/stdc++.h>
using namespace std;
vector<int> arr2;
int main() {
  long long n;
  cin >> n;
  int x = n % 10;
  int y = n / 10;
  if (n >= 0 && n <= 10) {
    if (n == 1)
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
    else if (n == 0)
      cout << "zero" << endl;
  } else {
    if (y > 0 && y <= 9) {
      if (y == 1) {
        if (x == 0) cout << "ten" << endl;
        if (x == 1)
          cout << "eleven" << endl;
        else if (x == 2)
          cout << "twelve" << endl;
        else if (x == 3)
          cout << "thirteen" << endl;
        else if (x == 4)
          cout << "fourteen" << endl;
        else if (x == 5)
          cout << "fifteen" << endl;
        else if (x == 6)
          cout << "sixteen" << endl;
        else if (x == 7)
          cout << "seventeen" << endl;
        else if (x == 8)
          cout << "eighteen" << endl;
        else if (x == 9)
          cout << "nineteen" << endl;
      } else if (y == 2) {
        if (x == 0)
          cout << "twenty" << endl;
        else if (x == 1)
          cout << "twenty-one" << endl;
        else if (x == 2)
          cout << "twenty-two" << endl;
        else if (x == 3)
          cout << "twenty-three" << endl;
        else if (x == 4)
          cout << "twenty-four" << endl;
        else if (x == 5)
          cout << "twenty-five" << endl;
        else if (x == 6)
          cout << "twenty-six" << endl;
        else if (x == 7)
          cout << "twenty-seven" << endl;
        else if (x == 8)
          cout << "twenty-eight" << endl;
        else if (x == 9)
          cout << "twenty-nine" << endl;
      } else if (y == 3) {
        if (x == 0)
          cout << "thirty" << endl;
        else if (x == 1)
          cout << "thirty-one" << endl;
        else if (x == 2)
          cout << "thirty-two" << endl;
        else if (x == 3)
          cout << "thirty-three" << endl;
        else if (x == 4)
          cout << "thirty-four" << endl;
        else if (x == 5)
          cout << "thirty-five" << endl;
        else if (x == 6)
          cout << "thirty-six" << endl;
        else if (x == 7)
          cout << "thirty-seven" << endl;
        else if (x == 8)
          cout << "thirty-eight" << endl;
        else if (x == 9)
          cout << "thirty-nine" << endl;
      } else if (y == 4) {
        if (x == 0)
          cout << "forty" << endl;
        else if (x == 1)
          cout << "forty-one" << endl;
        else if (x == 2)
          cout << "forty-two" << endl;
        else if (x == 3)
          cout << "forty-three" << endl;
        else if (x == 4)
          cout << "forty-four" << endl;
        else if (x == 5)
          cout << "forty-five" << endl;
        else if (x == 6)
          cout << "forty-six" << endl;
        else if (x == 7)
          cout << "forty-seven" << endl;
        else if (x == 8)
          cout << "forty-eight" << endl;
        else if (x == 9)
          cout << "forty-nine" << endl;
      } else if (y == 5) {
        if (x == 0)
          cout << "fifty" << endl;
        else if (x == 1)
          cout << "fifty-one" << endl;
        else if (x == 2)
          cout << "fifty-two" << endl;
        else if (x == 3)
          cout << "fifty-three" << endl;
        else if (x == 4)
          cout << "fifty-four" << endl;
        else if (x == 5)
          cout << "fifty-five" << endl;
        else if (x == 6)
          cout << "fifty-six" << endl;
        else if (x == 7)
          cout << "fifty-seven" << endl;
        else if (x == 8)
          cout << "fifty-eight" << endl;
        else if (x == 9)
          cout << "fifty-nine" << endl;
      } else if (y == 6) {
        if (x == 0)
          cout << "sixty" << endl;
        else if (x == 1)
          cout << "sixty-one" << endl;
        else if (x == 2)
          cout << "sixty-two" << endl;
        else if (x == 3)
          cout << "sixty-three" << endl;
        else if (x == 4)
          cout << "sixty-four" << endl;
        else if (x == 5)
          cout << "sixty-five" << endl;
        else if (x == 6)
          cout << "sixty-six" << endl;
        else if (x == 7)
          cout << "sixty-seven" << endl;
        else if (x == 8)
          cout << "sixty-eight" << endl;
        else if (x == 9)
          cout << "sixty-nine" << endl;
      } else if (y == 7) {
        if (x == 0)
          cout << "seventy" << endl;
        else if (x == 1)
          cout << "seventy-one" << endl;
        else if (x == 2)
          cout << "seventy-two" << endl;
        else if (x == 3)
          cout << "seventy-three" << endl;
        else if (x == 4)
          cout << "seventy-four" << endl;
        else if (x == 5)
          cout << "seventy-five" << endl;
        else if (x == 6)
          cout << "seventy-six" << endl;
        else if (x == 7)
          cout << "seventy-seven" << endl;
        else if (x == 8)
          cout << "seventy-eight" << endl;
        else if (x == 9)
          cout << "seventy-nine" << endl;
      } else if (y == 8) {
        if (x == 0)
          cout << "eighty" << endl;
        else if (x == 1)
          cout << "eighty-one" << endl;
        else if (x == 2)
          cout << "eighty-two" << endl;
        else if (x == 3)
          cout << "eighty-three" << endl;
        else if (x == 4)
          cout << "eighty-four" << endl;
        else if (x == 5)
          cout << "eighty-five" << endl;
        else if (x == 6)
          cout << "eighty-six" << endl;
        else if (x == 7)
          cout << "eighty-seven" << endl;
        else if (x == 8)
          cout << "eighty-eight" << endl;
        else if (x == 9)
          cout << "eighty-nine" << endl;
      } else if (y == 9) {
        if (x == 0)
          cout << "ninety" << endl;
        else if (x == 1)
          cout << "ninety-one" << endl;
        else if (x == 2)
          cout << "ninety-two" << endl;
        else if (x == 3)
          cout << "ninety-three" << endl;
        else if (x == 4)
          cout << "ninety-four" << endl;
        else if (x == 5)
          cout << "ninety-five" << endl;
        else if (x == 6)
          cout << "ninety-six" << endl;
        else if (x == 7)
          cout << "ninety-seven" << endl;
        else if (x == 8)
          cout << "ninety-eight" << endl;
        else if (x == 9)
          cout << "ninety-nine" << endl;
      }
    }
  }
  return 0;
}
