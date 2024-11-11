#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string a[12] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};
  int n, b;
  cin >> n;
  for (int i = 0; i < 12; i++) {
    if (a[i] == s) {
      b = i;
    }
  }
  cout << a[(b + n) % 12] << endl;
  return 0;
}
