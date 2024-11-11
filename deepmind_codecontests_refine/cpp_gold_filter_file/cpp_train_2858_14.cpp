#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  string s;
  int i;
  cin >> s >> k;
  const char *month[12] = {"December", "January",   "February", "March",
                           "April",    "May",       "June",     "July",
                           "August",   "September", "October",  "November"};
  for (i = 0; i < 12; i++) {
    if (month[i] == s) break;
  }
  cout << month[(i + k) % 12];
  return 0;
}
