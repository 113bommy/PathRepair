#include <bits/stdc++.h>
using namespace std;
int main() {
  string nums[]{"zero",    "one",     "two",       "three",    "four",
                "five",    "six",     "seven",     "eight",    "nine",
                "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                "twenty",  "thirty",  "forty",     "fifty",    "sixty",
                "seventy", "eighty",  "ninty"};
  int s;
  cin >> s;
  if (s >= 0 && s <= 20) {
    cout << nums[s] << '\n';
    return 0;
  }
  if (s % 10 == 0) {
    cout << nums[18 + ((s / 10) % 10)] << '\n';
    return 0;
  }
  cout << nums[18 + ((s / 10) % 10)] << "-" << nums[s % 10] << '\n';
  return 0;
}
