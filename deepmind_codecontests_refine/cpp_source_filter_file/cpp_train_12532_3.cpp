#include <bits/stdc++.h>
using namespace std;
int main() {
  string arr[] = {
      "Washington", "Adams",     "Jefferson", "Madison",    "Monroe",
      "Quincy",     "Jackson",   "Van Buren", "Harrison",   "Tyler",
      "Polk",       "Taylor",    "Fillmore",  "Pierce",     "Buchanan",
      "Lincoln",    "Johnson",   "Grant",     "Hayes",      "Garfield",
      "Arthur",     "Cleveland", "Harrison",  "Cleveland",  "McKinley",
      "Roosevelt",  "Taft",      "Wilson",    "Harding",    "Coolidge",
      "Hoover",     "Roosevelt", "Truman",    "Eisenhower", "Kennedy",
      "Johnson",    "Nixon",     "Ford",      "Carter",     "Reagan",
      "Bush",       "Clinton",   "Bush",      "Obama"};
  int n;
  cin >> n;
  cout << arr[n - 1] << endl;
}
