#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "><+-.,[]";
  string b[8]{"1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
  string in, res;
  int pos, d = 1, sol = 0;
  cin >> in;
  for (int i = 0; i < in.length(); i++) {
    pos = s.find(in[i]);
    res += b[pos];
  }
  for (int i = res.length() - 1; i >= 0; i--) {
    sol += ((res[i] - '0') * d);
    sol = sol % 1000003;
    d *= 2;
    d = d % 1000003;
  }
  cout << sol;
  return 0;
}
