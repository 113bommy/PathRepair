#include <bits/stdc++.h>
using namespace std;
string s[44] = {
    "Washington", "Adams",     "Jefferson", "Madison",    "Monroe",
    "Adams",      "Jackson",   "Van Buren", "Harrison",   "Tyler",
    "Polk",       "Taylor",    "Fillmore",  "Pierce",     "Buchanan",
    "Lincoln",    "Johnson",   "Grant",     "Hayes",      "Garfield",
    "Arthur",     "Cleveland", "Harrison",  "Cleveland",  "McKinley",
    "Roosevelt",  "Taft",      "Wilson",    "Harding",    "Coolidge",
    "Hoover",     "Roosevelt", "Tuman",     "Eisenhower", "Kennedy",
    "Johnson",    "Nixon",     "Ford",      "Carter",     "Reagan",
    "Bush",       "Clinton",   "Bush",      "Obama"};
int main() {
  int n;
  cin >> n;
  cout << s[n - 1];
}
