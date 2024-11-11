#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  string s[101], ss[10];
  s[1] = "one", s[2] = "two", s[3] = "three", s[4] = "four", s[5] = "five",
  s[6] = "six", s[7] = "seven", s[8] = "eight", s[9] = "nine";
  ss[1] = "twenty", ss[2] = "thirty", ss[3] = "forty", ss[4] = "fifty",
  ss[5] = "sixty", ss[6] = "seventy", ss[7] = "eighty", ss[8] = "ninety";
  if (n == 0) cout << "zero", exit(0);
  if (n == 10) cout << "ten", exit(0);
  if (n == 0) cout << "zero", exit(0);
  if (n == 1) cout << "one", exit(0);
  if (n == 2) cout << "two", exit(0);
  if (n == 3) cout << "three", exit(0);
  if (n == 4) cout << "four", exit(0);
  if (n == 5) cout << "five", exit(0);
  if (n == 6) cout << "six", exit(0);
  if (n == 7) cout << "seven", exit(0);
  if (n == 8) cout << "eight", exit(0);
  if (n == 9) cout << "nine", exit(0);
  if (n == 11) cout << "eleven", exit(0);
  if (n == 12) cout << "twelve", exit(0);
  if (n == 13) cout << "thirteen", exit(0);
  if (n == 14) cout << "fourteen", exit(0);
  if (n == 15) cout << "fifteen", exit(0);
  if (n == 16) cout << "sixteen", exit(0);
  if (n == 17) cout << "seventeen", exit(0);
  if (n == 18) cout << "eighteen", exit(0);
  if (n == 19) cout << "nineteen", exit(0);
  if (n == 20) cout << "twenty", exit(0);
  if (n == 30) cout << "thirty", exit(0);
  if (n == 40) cout << "forty", exit(0);
  if (n == 50) cout << "fifty", exit(0);
  if (n == 60) cout << "sixty", exit(0);
  if (n == 70) cout << "seventy", exit(0);
  if (n == 80) cout << "eighty", exit(0);
  if (n == 90) cout << "ninety", exit(0);
  if (n == 100) cout << "one hundred", exit(0);
  int k = n / 10;
  int k1 = n % 10;
  cout << ss[k - 1] << "-" << s[k1];
  return 0;
}
