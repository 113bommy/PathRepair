#include <bits/stdc++.h>
using namespace std;
string till_19[] = {"zero",    "one",     "two",       "three",    "four",
                    "five",    "six",     "seven",     "eight",    "nine",
                    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string after_19[] = {"twenty", "thirty",  "forty",  "fifty",
                     "sixty",  "seventy", "eighty", "ninety"};
int main() {
  int num;
  cin >> num;
  if (num >= 0 && num <= 19)
    cout << till_19[num] << endl;
  else if (num == 20 || num == 30 || num == 40 || num == 50 || num == 60 ||
           num == 70 || num == 80 || num == 90)
    cout << after_19[(num / 10) - 2] << endl;
  else {
    int second_part = num % 10;
    num -= second_part;
    cout << after_19[(num / 10) - 2] + "-" + till_19[second_part - 1] << endl;
  }
  return 0;
}
