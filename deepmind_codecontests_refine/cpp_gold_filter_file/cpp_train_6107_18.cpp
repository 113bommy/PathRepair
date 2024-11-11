#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  char q;
  long c = 0;
  bool f = true;
  for (long i = 0; i < s.size(); i++) {
    if (i == 0 or q != s[i]) {
      c = 1;
      q = s[i];
    } else {
      c++;
    }
    if (c == 7) {
      cout << "YES";
      f = false;
      break;
    }
  }
  if (f) cout << "NO";
  return 0;
}
