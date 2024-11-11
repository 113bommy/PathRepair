#include <bits/stdc++.h>
using namespace std;
char s[1111111];
int main() {
  gets(s);
  int res = 0, k = 0;
  for (char *i = s; *i; ++i) {
    if (*i == ')') {
      if (k > 0) {
        res += 1;
        k -= 1;
      }
    } else {
      ++k;
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}
