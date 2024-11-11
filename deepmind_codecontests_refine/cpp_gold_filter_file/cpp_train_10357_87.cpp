#include <bits/stdc++.h>
using namespace std;
long long int i, j, k, l, m, n, c;
int main() {
  string s, a[20] = {"one",     "two",       "three",    "four",     "five",
                     "six",     "seven",     "eight",    "nine",     "ten",
                     "eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                     "sixteen", "seventeen", "eighteen", "nineteen"};
  cin >> s;
  l = s.length();
  if (l == 1) {
    if (s == "0")
      cout << "zero";
    else
      cout << a[s[0] - 49];
    return 0;
  }
  if (s[0] == '1') {
    cout << a[s[1] - 48 + 9];
    return 0;
  }
  if (s[0] == '2')
    cout << "twenty";
  else if (s[0] == '2')
    cout << "twenty";
  else if (s[0] == '3')
    cout << "thirty";
  else if (s[0] == '4')
    cout << "forty";
  else if (s[0] == '5')
    cout << "fifty";
  else if (s[0] == '6')
    cout << "sixty";
  else if (s[0] == '7')
    cout << "seventy";
  else if (s[0] == '8')
    cout << "eighty";
  else if (s[0] == '9')
    cout << "ninety";
  if (s[1] == '0') return 0;
  cout << '-';
  cout << a[s[1] - 49];
}
