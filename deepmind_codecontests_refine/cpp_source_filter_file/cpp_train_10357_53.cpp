#include <bits/stdc++.h>
using namespace std;
string ans(int s);
string ans2(int s);
int main() {
  std::ios::sync_with_stdio(false);
  int s;
  cin >> s;
  string k = "";
  k = k + ans(s);
  cout << k << endl;
  return 0;
}
string ans(int s) {
  if (s < 10) {
    if (s == 0) {
      return "zero";
    } else if (s == 1) {
      return "one";
    } else if (s == 2) {
      return "two";
    } else if (s == 3) {
      return "three";
    } else if (s == 4) {
      return "four";
    } else if (s == 5) {
      return "five";
    } else if (s == 6) {
      return "six";
    } else if (s == 7) {
      return "seven";
    } else if (s == 8) {
      return "eight";
    } else if (s == 9) {
      return "nine";
    }
  } else {
    if (s == 10) {
      return "ten";
    } else if (s == 11) {
      return "eleven";
    } else if (s == 12) {
      return "twelve";
    } else if (s == 13) {
      return "thirteen";
    } else if (s == 14) {
      return "fourteen";
    } else if (s == 15) {
      return "fifteen";
    } else if (s == 16) {
      return "sixteen";
    } else if (s == 17) {
      return "seventeen";
    } else if (s == 19) {
      return "ninteen";
    } else if (s == 18) {
      return "eighteen";
    } else if (s == 20) {
      return "twenty";
    } else if (s == 30) {
      return "thirty";
    } else if (s == 40) {
      return "forty";
    } else if (s == 50) {
      return "fifty";
    } else if (s == 60) {
      return "sixty";
    } else if (s == 70) {
      return "seventy";
    } else if (s == 80) {
      return "eighty";
    } else if (s == 90) {
      return "ninety";
    } else {
      return ans2(s);
    }
  }
  return "none";
}
string ans2(int s) {
  int dig = s % 10;
  int dig2 = s % 100 - dig;
  string ju = "";
  ju = ans(dig2) + "-" + ans(dig);
  return ju;
}
