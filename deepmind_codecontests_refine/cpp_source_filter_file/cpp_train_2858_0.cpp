#include <bits/stdc++.h>
using namespace std;
int main() {
  string x[] = {"January",   "February", "March",    "April",
                "May",       "June",     "July",     "August",
                "September", "October",  "November", "December"};
  string s;
  cin >> s;
  int l, n;
  cin >> n;
  for (int i = 0; i < 12; i++) {
    if (s == x[i]) {
      l = i + 1;
    }
  }
  cout << x[(l + n) % 12 - 1] << endl;
}
