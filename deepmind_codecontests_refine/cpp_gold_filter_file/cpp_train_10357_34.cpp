#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, rem, k, f = 0, c = 0;
  cin >> n;
  vector<string> s;
  if (n == 0) {
    cout << "zero";
    return 0;
  }
  while (n != 0) {
    rem = n % 10;
    n = n / 10;
    c++;
    if (rem == 0) {
      rem = n % 10;
      if (rem == 1) {
        cout << "ten";
      } else if (rem == 2) {
        cout << "twenty";
      } else if (rem == 3) {
        cout << "thirty";
      } else if (rem == 4) {
        cout << "forty";
      } else if (rem == 5) {
        cout << "fifty";
      } else if (rem == 6) {
        cout << "sixty";
      } else if (rem == 7) {
        cout << "seventy";
      } else if (rem == 8) {
        cout << "eighty";
      } else if (rem == 9) {
        cout << "ninety";
      }
      return 0;
    } else if (f == 0) {
      f = 1;
      if (rem == 1) {
        s.push_back("one");
      } else if (rem == 2) {
        s.push_back("two");
      } else if (rem == 3) {
        s.push_back("three");
      } else if (rem == 4) {
        s.push_back("four");
      } else if (rem == 5) {
        s.push_back("five");
      } else if (rem == 6) {
        s.push_back("six");
      } else if (rem == 7) {
        s.push_back("seven");
      } else if (rem == 8) {
        s.push_back("eight");
      } else if (rem == 9) {
        s.push_back("nine");
      }
    } else if (f == 1) {
      if (rem == 1) {
        if (s[0] == "one") {
          cout << "eleven";
          return 0;
        } else if (s[0] == "two") {
          cout << "twelve";
          return 0;
        } else if (s[0] == "three") {
          cout << "thirteen";
          return 0;
        } else if (s[0] == "four") {
          cout << "fourteen";
          return 0;
        } else if (s[0] == "five") {
          cout << "fifteen";
          return 0;
        } else if (s[0] == "six") {
          cout << "sixteen";
          return 0;
        } else if (s[0] == "seven") {
          cout << "seventeen";
          return 0;
        } else if (s[0] == "eight") {
          cout << "eighteen";
          return 0;
        } else if (s[0] == "nine") {
          cout << "nineteen";
          return 0;
        }
      } else if (rem == 2) {
        s.push_back("twenty");
      } else if (rem == 3) {
        s.push_back("thirty");
      } else if (rem == 4) {
        s.push_back("forty");
      } else if (rem == 5) {
        s.push_back("fifty");
      } else if (rem == 6) {
        s.push_back("sixty");
      } else if (rem == 7) {
        s.push_back("seventy");
      } else if (rem == 8) {
        s.push_back("eighty");
      } else if (rem == 9) {
        s.push_back("ninety");
      }
    }
  }
  if (c == 1) {
    cout << s[0];
  } else {
    cout << s[1] << "-" << s[0];
  }
  return 0;
}
