#include <bits/stdc++.h>
using namespace std;
int rev(char c) {
  int f = 1, i;
  int r = 128;
  int res = 0;
  for ((i) = 0; (i) < (8); ++(i)) {
    if (f & c) res += r;
    f <<= 1;
    r >>= 1;
  }
  return res;
}
int main() {
  string s;
  getline(cin, s);
  int prev = 0;
  int i;
  for ((i) = 0; (i) < (s.length()); ++(i)) {
    int rsi = rev(s[i]);
    int wr = prev - rsi;
    wr = ((wr >= 0) ? (wr) : (256 + wr));
    cout << wr << endl;
    prev = rsi;
  }
  return 0;
}
