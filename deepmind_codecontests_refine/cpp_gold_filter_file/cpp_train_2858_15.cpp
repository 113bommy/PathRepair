#include <bits/stdc++.h>
using namespace std;
int func(int p) {
  if (p >= 12) {
    return func(p - 12);
  } else {
    return p;
  }
}
int main() {
  char s[12][12] = {"January",   "February", "March",    "April",
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};
  string st;
  cin >> st;
  int k;
  cin >> k;
  for (int i = 0; i < 12; i++) {
    int v;
    if (s[i] == st) {
      int p = i + k;
      v = func(p);
      if (v > 12) {
        v -= 12;
      }
      cout << s[v] << endl;
    }
  }
  return 0;
}
