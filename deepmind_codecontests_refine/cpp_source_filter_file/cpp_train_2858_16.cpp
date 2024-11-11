#include <bits/stdc++.h>
using namespace std;
int main() {
  char* months[12] = {"January",   "February", "March",    "April",
                      "May",       "June",     "July",     "August",
                      "September", "October",  "November", "December"};
  char str[10];
  int k, i;
  cin >> str >> k;
  for (i = 0; i < 12; i++)
    if (strcmp(str, months[i]) == 0) break;
  i += k;
  if (i > 11) k = i % 12;
  cout << months[k];
  return 0;
}
