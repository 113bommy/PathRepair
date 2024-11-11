#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n, m, i, j, s;
  char b[100][20] = {"zero",    "one",     "two",       "three",    "four",
                     "five",    "six",     "seven",     "eight",    "nine",
                     "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  char c[11][20] = {"twenty", "thirty",  "fourty", "fifty",
                    "sixty",  "seventy", "eighty", "ninety"};
  scanf("%d", &s);
  n = s % 10;
  m = s / 10;
  if (s < 20) {
    printf("%s", b[s]);
  } else {
    if (s % 10 != 0)
      printf("%s-%s", c[s / 10 - 2], b[s % 10]);
    else
      printf("%s", c[s / 10 - 2]);
  }
}
