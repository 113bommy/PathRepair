#include <bits/stdc++.h>
using namespace std;
int main() {
  string months[] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
  string s;
  int n, a;
  cin >> s >> n;
  for (int i = 0; i < 12; i++) {
    if (months[i].compare(s) == 0) {
      a = i + n;
      break;
    }
  }
  while (a > 11) {
    a = a - 12;
  }
  cout << months[a];
}
