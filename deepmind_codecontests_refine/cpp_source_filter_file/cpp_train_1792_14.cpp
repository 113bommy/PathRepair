#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = 0;
  int r = s.size() - 1;
  while (true) {
    if (s[l] != s[r]) {
      puts("0");
      return 0;
    }
    int ll = l;
    int rr = r;
    while (ll < (int)s.size() && s[ll] == s[l]) ll++;
    while (rr > -1 && s[rr] == s[r]) r--;
    if (l + 1 == ll && r - 1 == rr) {
      puts("0");
      return 0;
    }
    if (ll > rr) {
      printf("%d\n", ll - rr + 2);
      return 0;
    } else {
      l = ll;
      r = rr;
    }
  }
  return 0;
}
