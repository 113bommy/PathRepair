#include <bits/stdc++.h>
using namespace std;
int mod(char s1, char s2) {
  if (((s1 - 48) * 10 + (s2 - 48)) % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  string s;
  int n, res = 0;
  cin >> s;
  int len = s.size();
  if ((s[0] - 48) % 4 == 0) res = 1;
  for (int i = 1; i < len; i++) {
    if ((s[i] - 48) % 4 == 0) {
      ++res;
    }
    if (mod(s[i - 1], s[i]) == 1) {
      res = res + i;
    }
  }
  cout << res << endl;
  return 0;
}
