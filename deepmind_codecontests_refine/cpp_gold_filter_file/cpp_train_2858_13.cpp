#include <bits/stdc++.h>
using namespace std;
int main() {
  string a[12] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};
  string s;
  int m;
  int count = 0;
  cin >> s;
  cin >> m;
  if (s[0] == 'J') {
    if (s[1] == 'u') {
      if (s[2] == 'n') {
        count = 5;
      } else
        count = 6;
    } else
      count = 0;
  } else if (s[0] == 'F')
    count = 1;
  else if (s[0] == 'M' && s[1] == 'a') {
    if (s[2] == 'r')
      count = 2;
    else
      count = 4;
  } else if (s[0] == 'A') {
    if (s[1] == 'p')
      count = 3;
    else
      count = 7;
  } else if (s[0] == 'S')
    count = 8;
  else if (s[0] == 'O')
    count = 9;
  else if (s[0] == 'N')
    count = 10;
  else if (s[0] == 'D')
    count = 11;
  int num, n;
  if (m < 12) {
    num = count + m;
    if (num >= 12) {
      n = num - 12;
      cout << a[n] << endl;
    } else
      cout << a[num] << endl;
  } else {
    int x;
    num = (m % 12) + count;
    if (num >= 12) {
      x = num - 12;
      cout << a[x] << endl;
    } else
      cout << a[num] << endl;
  }
}
