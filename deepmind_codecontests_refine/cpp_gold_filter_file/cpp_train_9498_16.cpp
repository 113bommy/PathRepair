#include <bits/stdc++.h>
using namespace std;
int get_rev_num(int n) {
  int res = 0;
  int j = 7;
  for (int i = 0; i < 8; i++, j--) {
    if (n & (1 << i)) {
      res += pow(2, j);
    }
  }
  return res;
}
int main() {
  string s;
  getline(cin, s);
  int prev = 0;
  for (int i = 0; i < s.size(); i++) {
    int ascii = (int)(s[i]);
    int rev = get_rev_num(ascii);
    int sub = prev - rev;
    int rem = sub % 256;
    cout << (rem >= 0 ? rem : rem + 256) << "\n";
    prev = rev;
  }
}
