#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  map<int, string> a;
  a[1] = "one";
  a[2] = "two";
  a[3] = "three";
  a[4] = "four";
  a[5] = "five";
  a[6] = "six";
  a[7] = "seven";
  a[8] = "eight";
  a[9] = "nine";
  a[0] = "zero";
  a[10] = "ten";
  a[11] = "eleven";
  a[12] = "twelve";
  a[13] = "thirteen";
  a[14] = "fourteen";
  a[15] = "fifteen";
  a[16] = "sixteen";
  a[17] = "seventeen";
  a[18] = "eighteen";
  a[19] = "nineteen";
  a[20] = "twenty";
  a[30] = "thirty";
  a[40] = "forty";
  a[50] = "fifty";
  a[60] = "sixty";
  a[70] = "seventy";
  a[80] = "eighty";
  a[90] = "ninety";
  if (n <= 20)
    cout << a[n];
  else {
    if (n % 10)
      cout << a[n / 10 * 10] << "-" << a[n % 10];
    else
      cout << a[n];
  }
  return 0;
}
