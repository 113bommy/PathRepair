#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cs = 0, ct = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x')
      cs++;
    else {
      if (cs >= 3) ct += cs - 2;
      cs = 0;
    }
  }
  if (cs >= 3) ct += cs - 2;
  cout << ct;
  return 0;
}
