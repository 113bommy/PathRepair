#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s2[] = {"one", "two",   "three", "four", "five",
                    "six", "seven", "eight", "nine"};
  cin >> s;
  if (s.length() == 1) {
    if (s == "0")
      cout << "zero" << '\n';
    else if (s == "1")
      cout << "one" << '\n';
    else if (s == "2")
      cout << "two" << '\n';
    else if (s == "3")
      cout << "three" << '\n';
    else if (s == "4")
      cout << "four" << '\n';
    else if (s == "5")
      cout << "five" << '\n';
    else if (s == "6")
      cout << "six" << '\n';
    else if (s == "7")
      cout << "seven" << '\n';
    else if (s == "8")
      cout << "eight" << '\n';
    else if (s == "9")
      cout << "nine" << '\n';
  } else if (s.length() == 2) {
    if (s[0] == '1') {
      if (s[1] == '0') cout << "ten" << '\n';
      for (int i = 11; i <= 19; i++) {
        if (s[1] == '1') {
          cout << "eleven" << '\n';
          break;
        } else if (s[1] == '2') {
          cout << "twelve" << '\n';
          break;
        } else if (s[1] == '3') {
          cout << "thirteen" << '\n';
          break;
        } else if (s[1] == '4') {
          cout << "fourteen" << '\n';
          break;
        } else if (s[1] == '5') {
          cout << "fifteen" << '\n';
          break;
        } else if (s[1] == '6') {
          cout << "sixteen" << '\n';
          break;
        } else if (s[1] == '7') {
          cout << "seventeen" << '\n';
          break;
        } else if (s[1] == '8') {
          cout << "eighteen" << '\n';
          break;
        } else if (s[1] == '9') {
          cout << "nineteen" << '\n';
          break;
        }
      }
    } else if (s[0] == '2') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "twenty" << '\n';
      } else if (temp == 1) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "twenty-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "twenty-" << s2[temp - 1];
      }
    } else if (s[0] == '3') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "thirty" << '\n';
      } else if (temp == 1) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "thirty-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "thirty-" << s2[temp - 1];
      }
    } else if (s[0] == '4') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "forty" << '\n';
      } else if (temp == 1) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "forty-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "forty-" << s2[temp - 1];
      }
    } else if (s[0] == '5') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "fifty" << '\n';
      } else if (temp == 1) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "fifty-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "fifty-" << s2[temp - 1];
      }
    } else if (s[0] == '6') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "sixty" << '\n';
      } else if (temp == 1) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "sixty-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "sixty-" << s2[temp - 1];
      }
    } else if (s[0] == '7') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "seventy" << '\n';
      } else if (temp == 1) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "seventy-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "seventy-" << s2[temp - 1];
      }
    } else if (s[0] == '8') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "eighty" << '\n';
      } else if (temp == 1) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "eighty-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "eighty-" << s2[temp - 1];
      }
    } else if (s[0] == '9') {
      int temp = s[1] - '0';
      if (temp == 0) {
        cout << "ninety" << '\n';
      } else if (temp == 1) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 2) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 3) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 4) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 5) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 6) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 7) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 8) {
        cout << "ninety-" << s2[temp - 1];
      } else if (temp == 9) {
        cout << "ninety-" << s2[temp - 1];
      }
    }
  }
  return 0;
}
