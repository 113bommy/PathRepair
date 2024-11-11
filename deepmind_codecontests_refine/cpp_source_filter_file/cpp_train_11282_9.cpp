#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, out = 1;
  string current, t, s;
  cin >> s;
  cin >> t;
  current[0] = s[0];
  int l = t.length();
  int j = 1;
  for (i = 1; i <= l; i++) {
    if (current[0] == t[i]) {
      out++;
      current[0] = s[j];
      j++;
    }
  }
  cout << out;
}
