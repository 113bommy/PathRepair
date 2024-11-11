#include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s;
  char ones[100][100] = {
      "zero",     "one",      "two",      "three",   "four",    "five",
      "six",      "seven",    "eight",    "nine",    "ten",     "eleven",
      "twelve",   "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
      "eighteen", "nineteen", "twenty"};
  char tens[100][100] = {" ",     " ",     "twenty",  "thirty", "fourty",
                         "fifty", "sixty", "seventy", "eighty", "ninety"};
  if (s >= 0 && s <= 20)
    cout << ones[s];
  else {
    int t = s / 10;
    cout << tens[t];
    int mod = s % 10;
    if (mod > 0) cout << "-" << ones[mod];
  }
  return 0;
}
