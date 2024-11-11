#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
string s;
int main() {
  cin >> s;
  bool l = false, r = false;
  for (char c : s) {
    if (c == '0') {
      if (l)
        puts("1 1");
      else
        puts("3 1");
      l = !l;
    } else {
      if (r)
        puts("4 3");
      else
        puts("4 1");
      r = !r;
    }
  }
  return 0;
}
