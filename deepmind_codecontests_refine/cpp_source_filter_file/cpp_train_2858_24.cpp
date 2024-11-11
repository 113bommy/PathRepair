#include <bits/stdc++.h>
using namespace std;
bool notprime(int x) {
  for (int i = 2; i < x; i++) {
    if (x % i == 0) return true;
  }
  return false;
}
int main() {
  string s[12] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};
  string w;
  cin >> w;
  int x, y, z;
  cin >> y;
  for (int i = 0; i < 12; i++) {
    if (s[i] == w) x = i;
  }
  z = x + y;
  if (z < 12)
    cout << s[z] << endl;
  else if (z > 12)
    cout << s[z % 12] << endl;
  return 0;
}
