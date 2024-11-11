#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int x = (a / 2) + 10;
  string s = "mukul";
  string st;
  for (int i = 1; i <= x; i++) {
    st = to_string(i);
    s = s + st;
  }
  cout << s[a];
  return 0;
}
