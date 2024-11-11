#include <bits/stdc++.h>
using namespace std;
char sec[10][10] = {"twenty", "thirty",  "forty",  "fity",
                    "sixty",  "seventy", "eighty", "ninety"};
char fir[10][10] = {"one", "two",   "three", "four", "five",
                    "six", "seven", "eight", "nine"};
char mid[10][10] = {"eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                    "sixteen", "seventeen", "eighteen", "nineteen"};
int n;
int main() {
  scanf("%d", &n);
  if (n / 10 > 1) {
    if (n % 10 == 0)
      printf("%s", sec[n / 10 - 2]);
    else
      printf("%s-%s", sec[n / 10 - 2], fir[n % 10 - 1]);
  } else if (n / 10 == 1) {
    if (n % 10 == 0)
      puts("ten");
    else
      printf("%s", mid[n % 10 - 1]);
  } else if (n / 10 == 0) {
    if (n % 10 == 0)
      puts("zero");
    else
      printf("%s", fir[n % 10 - 1]);
  }
}
