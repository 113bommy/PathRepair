#include <bits/stdc++.h>
using namespace std;
string num[111] = {
    "zero",     "one",      "two",      "three",   "four",    "five",
    "six",      "seven",    "eight",    "nine",    "ten",     "eleven",
    "twelve",   "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
    "eighteen", "nineteen", "twenty",
};
string ty[11] = {"",      "",      "twenty",  "thirty", "forty",
                 "fifty", "sixty", "seventy", "eighty", "ninety"};
int main() {
  int n;
  while (cin >> n) {
    if (n <= 20) {
      cout << num[n] << endl;
    } else if (n % 10 == 0) {
      cout << ty[n / 10] << endl;
    } else {
      string str = "";
      cout << ty[n / 10] + '-' + num[n % 10] << endl;
    }
  }
  return 0;
}
