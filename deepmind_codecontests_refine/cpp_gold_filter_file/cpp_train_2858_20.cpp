#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[12] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};
  string str;
  cin >> str;
  int temp, k, j;
  for (j = 0; j < 12; j++) {
    if (s[j] == str) {
      temp = j + 1;
      break;
    }
  }
  k = 12 - temp;
  int num;
  cin >> num;
  int divi, rem;
  divi = num / 12;
  rem = num % 12;
  if (rem == 0)
    cout << s[temp - 1];
  else if (rem <= k)
    cout << s[temp - 1 + rem];
  else {
    rem = rem - k;
    cout << s[rem - 1];
  }
  return 0;
}
