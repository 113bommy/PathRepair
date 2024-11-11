#include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s;
  const char* x[] = {"zero",    "one",     "two",       "three",    "four",
                     "five",    "six",     "seven",     "eight",    "nine",
                     "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                     "twenty",  "thirty",  "forty",     "fifty",    "sixty",
                     "seventy", "eighty",  "ninety"};
  vector<string> a(x, x + sizeof(x) / sizeof(x[0]));
  if (s <= 20)
    cout << x[s] << "\n";
  else {
    string p, q;
    int i = s % 10;
    if (i == 0) {
      int j = s / 10;
      cout << x[20 + (j - 2)];
    } else {
      q = x[i];
      s -= i;
      int j = s / 10;
      p = x[20 + (j - 2)];
      cout << p << "-" << q << endl;
    }
  }
  return 0;
}
