#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int num[101][101];
string str[41] = {
    "",         "Washington", "Adams",     "Jefferson", "Madison",
    "Monroe",   "Adams",      "Jackson",   "Van Buren", "Harrison",
    "Tyler",    "Polk",       "Taylor",    "Fillmore",  "Pierce",
    "Buchanan", "Lincoln",    "Johnson",   "Grant",     "Hayes",
    "Garfield", "Arthur",     "Cleveland", "Harrison",  "Cleveland",
    "McKinley", "Roosevelt",  "Taft",      "Wilson",    "Harding",
    "Coolidge", "Hoover",     "Roosevelt", "Truman",    "Eisenhower",
    "Kennedy",  "Johnson",    "Nixon",     "Ford",      "Carter",
    "Reagan"};
int main() {
  int n;
  cin >> n;
  cout << str[n] << endl;
  return 0;
}
