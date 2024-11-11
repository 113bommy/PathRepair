#include <bits/stdc++.h>
using namespace std;
int main() {
  int hash[1002] = {0};
  int t = 0;
  string s;
  cin >> s;
  s += ',';
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ',') {
      hash[t] = 1;
      t = 0;
    } else {
      t = t * 10 + (s[i] - '0');
    }
  }
  int p = 0, q = 0, start = 1;
  for (int i = 1; i < 1002; i++) {
    if (hash[i] == 0 && p > 0) {
      q++;
      if (q > 1) cout << ',';
      if ((i - start) == 1) {
        cout << start;
      } else {
        cout << start << '-' << i - 1;
      }
      p = 0;
    } else if (hash[i] == 1) {
      p++;
      if (p == 1) {
        start = i;
      }
    }
  }
  return 0;
}
